#include "Exam.h"
#include <QModelIndexList>

Exam::Exam(Service& service, Astronomer a,QWidget *parent)
    : QMainWindow(parent), service{ service },a{a}
{
    ui.setupUi(this);
	TableModel* model = new TableModel(service);
	ui.startsTableView->setModel(model);

	//this->populateList();
	this->setWindowTitle(QString::fromStdString(this->a.getName()));
	//QObject::connect(ui.horizontalSlider, &QSlider::valueChanged, radiusLineEdit, &QLineEdit::setText());

	QObject::connect(this->ui.searchLineEdit, &QLineEdit::textEdited, this, &Exam::search);
	//connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(check(int)));
	QObject::connect(ui.horizontalSlider, &QSlider::valueChanged, ui.spinBox, &QSpinBox::setValue);

	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &Exam::add);
	QObject::connect(ui.viewPushButton, &QPushButton::clicked, this, &Exam::openWindow);
}
void Exam::add()
{
	string name = ui.nameLineEdit->text().toStdString();
	int RA = ui.RALineEdit->text().toInt();
	int Dec = ui.DesLineEdit->text().toInt();
	//int diam = ui.diamLineEdit->text().toInt();
	int diam = ui.spinBox->value();
	try
	{
		this->service.add(name, a.getConstel(),RA, Dec, diam);
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Could not add star");
		return;
	}
	this->update();
}
void Exam::search()
{
	string searchString = this->ui.searchLineEdit->text().toStdString();
	this->ui.searchListWidget->clear();
	auto v = this->service.getBySearch(searchString);
	for (auto i : v)
	{
		string line = i.getName() + " " + i.getConstel() + " " + to_string(i.getRA()) + " " + to_string(i.getDec()) + " " + to_string(i.getDiam());
		this->ui.searchListWidget->addItem(QString::fromStdString(line));
	}

}

void Exam::openWindow()
{
	int idx = getSelectedIndex();
	if(idx!=-1) {
		Star s = this->service.getAllS()[idx];
		viewWidget* v = new viewWidget(this->service, s);
		v->show();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please select a constellation.");
		return;
	}
	

}

void Exam::check(int c)
{
	if (c == Qt::Checked)
	{
		TableModel* model = new TableModel(service);
		ui.startsTableView->setModel(model);

	}
}

int Exam::getSelectedIndex()
{
	QModelIndexList selectedIndexes = ui.startsTableView->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		return -1;
	}
	return selectedIndexes.at(0).row();

}

void Exam::populateList()
{
	TableModel* model = new TableModel(service);
	ui.startsTableView->setModel(model);

}

void Exam::update()
{
	this->populateList();
}
