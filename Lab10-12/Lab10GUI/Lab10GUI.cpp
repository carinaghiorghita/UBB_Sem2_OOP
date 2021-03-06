#include "Lab10GUI.h"

Lab10GUI::Lab10GUI(Service& service, QWidget* parent): QMainWindow(parent), service{ service }
{
	ui.setupUi(this);
	//ui.tableView->setModel(this->model);
	this->makeConnection();
	this->widget = new MylistWidget(this->service);

}


void Lab10GUI::populateList()
{
	ui.victimsListWidget->clear();

	vector<Victim>allVictims = this->service.getAllVictimsInRepository();
	for (Victim& victim : allVictims)
		//this->victimsListWidget->addItem(victim.getName() + ": " + victim.getPlaceOfOrigin() + ", " + to_string(victim.getAge()) + ", " + victim.getPhotograph());
		ui.victimsListWidget->addItem(QString::fromStdString(victim.getName()));

}

/*void Lab10GUI::populateMylist()
{
	this->mylistWidget->clear();

	vector<Victim>allVictims = this->service.getAllVictimsInSavedList();
	for (Victim& victim : allVictims)
		this->mylistWidget->addItem(QString::fromStdString(victim.getName()));

}*/

void Lab10GUI::makeConnection()
{
	populateList();
	QObject::connect(ui.victimsListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0) return;

		Victim victim = this->service.getAllVictimsInRepository()[selectedIndex];
		ui.nameLineEdit->setText(QString::fromStdString(victim.getName()));
		ui.placeLineEdit->setText(QString::fromStdString(victim.getPlaceOfOrigin()));
		ui.ageLineEdit->setText(QString::fromStdString(to_string(victim.getAge())));
		ui.photographLineEdit->setText(QString::fromStdString(victim.getPhotograph()));

		});

	QObject::connect(ui.AddPushButton, &QPushButton::clicked, this, &Lab10GUI::addVictim);
	QObject::connect(ui.DeletePushButton, &QPushButton::clicked, this, &Lab10GUI::deleteVictim);
	QObject::connect(ui.UpdatePushButton, &QPushButton::clicked, this, &Lab10GUI::updateVictim);
	QObject::connect(ui.FilterPushButton, &QPushButton::clicked, this, &Lab10GUI::filterVictims);
	QObject::connect(ui.SavePushButton, &QPushButton::clicked, this, &Lab10GUI::saveVictims);
	QObject::connect(ui.NextPushButton, &QPushButton::clicked, this, &Lab10GUI::nextVictim);
	QObject::connect(ui.MylistPushButton, &QPushButton::clicked, this, &Lab10GUI::mylist);
	QObject::connect(ui.undoButton, &QPushButton::clicked, this, &Lab10GUI::undo);
	QObject::connect(ui.redoButton, &QPushButton::clicked, this, &Lab10GUI::redo);
	QObject::connect(ui.undoSaveButton, &QPushButton::clicked, this, &Lab10GUI::savedUndo);
	QObject::connect(ui.redoSaveButton, &QPushButton::clicked, this, &Lab10GUI::savedRedo);
}

int Lab10GUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = ui.victimsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		ui.nameLineEdit->clear();
		ui.placeLineEdit->clear();
		ui.ageLineEdit->clear();
		ui.photographLineEdit->clear();
		//QMessageBox::critical(this, "Error", "No victim selected");
		return -1;
	}
	return selectedIndexes.at(0).row();
}

void Lab10GUI::addVictim()
{
	string name = ui.nameLineEdit->text().toStdString();
	string place = ui.placeLineEdit->text().toStdString();
	int age = ui.ageLineEdit->text().toInt();
	string photograph = ui.photographLineEdit->text().toStdString();

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
	ui.victimsListWidget->setCurrentRow(lastIndex);
}

void Lab10GUI::deleteVictim()
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

void Lab10GUI::updateVictim()
{
	string name = ui.nameLineEdit->text().toStdString();
	string place = ui.placeLineEdit->text().toStdString();
	int age = ui.ageLineEdit->text().toInt();
	string photograph = ui.photographLineEdit->text().toStdString();

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

void Lab10GUI::filterVictims()
{
	string place = ui.filterPlaceLineEdit->text().toStdString();
	int age = ui.filterAgeLineEdit->text().toInt();

	ui.filteredListWidget->clear();

	vector<Victim>allVictims = this->service.getAllVictimsInRepository();
	for (Victim& victim : allVictims)
		if (victim.getPlaceOfOrigin() == place && victim.getAge() < age)
			ui.filteredListWidget->addItem(QString::fromStdString(victim.getName()));
}

void Lab10GUI::saveVictims()
{
	/*int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No victim selected");
		return;
	}
	Victim victim = this->service.getAllVictimsInRepository()[selectedIndex];*/

	string name = ui.saveLineEdit->text().toStdString();
	Victim victim = this->service.findVictimRepository(name);
	this->service.addVictimSavedList(victim);
	//this->populateMylist();
}

void Lab10GUI::nextVictim()
{
	ui.nextListWidget->clear();
	Victim victim = this->service.getNext();

	std::string next = victim.getString();
	this->ui.nextListWidget->addItem(QString::fromStdString(next));
	this->ui.saveLineEdit->setText(QString::fromStdString(victim.getName()));
}

void Lab10GUI::mylist()
{
	/*if (this->service.getType() == "memory")
	{
		ui.mylistWidget->clear();

		vector<Victim>allVictims = this->service.getAllVictimsInSavedList();
		for (Victim& victim : allVictims)
				ui.mylistWidget->addItem(QString::fromStdString(victim.getString()));
	}
	else
	{
		this->service.open();
	}*/
	this->widget = new MylistWidget(this->service);
	this->widget->show();
}

void Lab10GUI::undo()
{
	try
	{
		this->service.undo();
		this->populateList();
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "No more undos!");
		return;

	}
}

void Lab10GUI::redo()
{
	try
	{
		this->service.redo();
		this->populateList();
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "No more redos!");
		return;

	}

}

void Lab10GUI::savedUndo()
{
	try
	{
		this->service.savedUndo();
		//modify mylist
		this->widget = new MylistWidget(this->service);
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "No more undos!");
		return;

	}

}

void Lab10GUI::savedRedo()
{
	try
	{
		this->service.savedRedo();
		//modify mylist
		this->widget = new MylistWidget(this->service);
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "No more redos!");
		return;

	}

}
