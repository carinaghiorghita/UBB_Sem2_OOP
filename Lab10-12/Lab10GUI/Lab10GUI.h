#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>

#include "ui_Lab10GUI.h"
#include "Service.h"
#include "MylistWidget.h"

class Lab10GUI : public QMainWindow
{
	Q_OBJECT
private:
	Service& service;
	MylistWidget* widget;

public:
	Lab10GUI(Service& service, QWidget* parent = Q_NULLPTR);
	void populateList();
	//void populateMylist();
	void makeConnection();

	int getSelectedIndex() const;

	void addVictim();
	void deleteVictim();
	void updateVictim();
	void filterVictims();
	void saveVictims();
	void nextVictim();
	void mylist();
	void undo();
	void redo();
	void savedUndo();
	void savedRedo();

private:
	Ui::Lab10GUIClass ui;
};
