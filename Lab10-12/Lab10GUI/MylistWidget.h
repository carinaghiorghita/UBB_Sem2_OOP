#pragma once

#include <QWidget>
#include "ui_MylistWidget.h"
#include "MylistTableModel.h"

class MylistWidget : public QWidget
{
	Q_OBJECT

public:
	MylistWidget();
	MylistWidget(Service& service, QWidget *parent = Q_NULLPTR);
	//void update();
	~MylistWidget();

private:
	Ui::MylistWidget ui;
	Service& service;
	//MylistTableModel* model;
};
