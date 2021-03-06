#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include "Service.h"
class GUI : public QWidget
{
private:
	Service& service;

	QListWidget* victimsListWidget,* mylistWidget;
	QLineEdit* nameLineEdit, * placeLineEdit, * ageLineEdit, * photoLineEdit;
	QPushButton* addPushButton, * deletePushButton, * updatePushButton,* filterPushButton,* savePushButton;

public:
	GUI(Service& newService);

private:
	void initializeGUI();
	void populateList();
	void populateMylist();
	void makeConnection();

	int getSelectedIndex() const;

	void addVictim();
	void deleteVictim();
	void updateVictim();
	void filterVictims();
	void saveVictims();
};

