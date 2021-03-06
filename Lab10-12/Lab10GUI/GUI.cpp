#include "GUI.h"

using namespace std;

GUI::GUI(Service& newService) :service{ newService }
{
	this->initializeGUI();
	this->populateList();
	this->makeConnection();
}

void GUI::initializeGUI()
{
	this->victimsListWidget = new QListWidget{};

	this->nameLineEdit = new QLineEdit{};
	this->placeLineEdit = new QLineEdit{};
	this->ageLineEdit = new QLineEdit{};
	this->photoLineEdit = new QLineEdit{};

	this->addPushButton = new QPushButton{"Add"};
	this->deletePushButton = new QPushButton{"Delete"};
	this->updatePushButton = new QPushButton{"Update"};
	this->filterPushButton = new QPushButton{ "Filter" };
	this->savePushButton = new QPushButton{ ">" };

	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	QVBoxLayout* modeALayout = new QVBoxLayout;
	QLabel* modeALabel = new QLabel{ "Victims: " };
	modeALayout->addWidget(modeALabel);
	modeALayout->addWidget(this->victimsListWidget);

	QFormLayout* victimAtributesLayout = new QFormLayout;
	victimAtributesLayout->addRow("Name:", this->nameLineEdit);
	victimAtributesLayout->addRow("Place:", this->placeLineEdit);
	victimAtributesLayout->addRow("Age:", this->ageLineEdit);
	victimAtributesLayout->addRow("Photograph:", this->photoLineEdit);
	modeALayout->addLayout(victimAtributesLayout);

	QGridLayout* buttonsLayout = new QGridLayout;
	buttonsLayout->addWidget(this->addPushButton, 0, 0);
	buttonsLayout->addWidget(this->deletePushButton, 0, 1);
	buttonsLayout->addWidget(this->updatePushButton, 0, 2);
	//buttonsLayout->addWidget(this->filterPushButton, 1, 1);
	modeALayout->addLayout(buttonsLayout);
	mainLayout->addLayout(modeALayout);
	
	QGridLayout* saveButtonLayout = new QGridLayout;
	saveButtonLayout->addWidget(this->savePushButton);
	mainLayout->addLayout(saveButtonLayout);

	QVBoxLayout* modeBLayout = new QVBoxLayout;
	QLabel* modeBLabel = new QLabel{ "Mylist: " };
	modeBLayout->addWidget(modeBLabel);
	this->mylistWidget = new QListWidget{};
	modeBLayout->addWidget(this->mylistWidget);
	mainLayout->addLayout(modeBLayout);

}

void GUI::populateList()
{
	this->victimsListWidget->clear();

	vector<Victim>allVictims = this->service.getAllVictimsInRepository();
	for (Victim& victim : allVictims)
		//this->victimsListWidget->addItem(victim.getName() + ": " + victim.getPlaceOfOrigin() + ", " + to_string(victim.getAge()) + ", " + victim.getPhotograph());
		this->victimsListWidget->addItem(QString::fromStdString(victim.getName()));

}

void GUI::populateMylist()
{
	this->mylistWidget->clear();

	vector<Victim>allVictims = this->service.getAllVictimsInSavedList();
	for (Victim& victim : allVictims)
		this->mylistWidget->addItem(QString::fromStdString(victim.getName()));

}

void GUI::makeConnection()
{
	QObject::connect(this->victimsListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0) return;

		Victim victim = this->service.getAllVictimsInRepository()[selectedIndex];
		this->nameLineEdit->setText(QString::fromStdString(victim.getName()));
		this->placeLineEdit->setText(QString::fromStdString(victim.getPlaceOfOrigin()));
		this->ageLineEdit->setText(QString::fromStdString(to_string(victim.getAge())));
		this->photoLineEdit->setText(QString::fromStdString(victim.getPhotograph()));

		});

	QObject::connect(this->addPushButton, &QPushButton::clicked, this, &GUI::addVictim);
	QObject::connect(this->deletePushButton, &QPushButton::clicked, this, &GUI::deleteVictim);
	QObject::connect(this->updatePushButton, &QPushButton::clicked, this, &GUI::updateVictim);
	QObject::connect(this->filterPushButton, &QPushButton::clicked, this, &GUI::filterVictims);
	QObject::connect(this->savePushButton, &QPushButton::clicked, this, &GUI::saveVictims);
}

int GUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->victimsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->nameLineEdit->clear();
		this->placeLineEdit->clear();
		this->ageLineEdit->clear();
		this->photoLineEdit->clear();
		//QMessageBox::critical(this, "Error", "No victim selected");
		return -1;
	}
	return selectedIndexes.at(0).row();
}

void GUI::addVictim()
{
	string name = this->nameLineEdit->text().toStdString();
	string place = this->placeLineEdit->text().toStdString();
	int age = this->ageLineEdit->text().toInt();
	string photograph = this->photoLineEdit->text().toStdString();

	try
	{
		this->service.addVictimRepository(name, place, age, photograph);
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Could not add victim");
		return;
	}
	this->populateList();
	int lastIndex = this->service.getAllVictimsInRepository().size() - 1;
	this->victimsListWidget->setCurrentRow(lastIndex);
}

void GUI::deleteVictim()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No victim selected");
		return;
	}
	Victim victim = this->service.getAllVictimsInRepository()[selectedIndex];
	try
	{
		this->service.deleteVictimRepository(victim.getName());
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Could not delete victim");
		return;
	}

	this->populateList();
}

void GUI::updateVictim()
{
	string name = this->nameLineEdit->text().toStdString();
	string place = this->placeLineEdit->text().toStdString();
	int age = this->ageLineEdit->text().toInt();
	string photograph = this->photoLineEdit->text().toStdString();

	try
	{
		this->service.updateVictimRepository(name, place, age, photograph);
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Could not update victim");
		return;
	}
	this->populateList();
}

void GUI::filterVictims()
{
	this->victimsListWidget->clear();

	string place= this->placeLineEdit->text().toStdString();
	int age = this->ageLineEdit->text().toInt();

	vector<Victim>allVictims = this->service.getAllVictimsInRepository();
	for (Victim& victim : allVictims)
		if (victim.getPlaceOfOrigin() == place && victim.getAge() < age)
			this->victimsListWidget->addItem(QString::fromStdString(victim.getName()));
}

void GUI::saveVictims()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No victim selected");
		return;
	}
	Victim victim = this->service.getAllVictimsInRepository()[selectedIndex];

	this->service.addVictimSavedList(victim);
	this->populateMylist();
}
