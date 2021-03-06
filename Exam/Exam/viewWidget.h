#pragma once

#include <QPainter>
#include <QWidget>
#include "ui_viewWidget.h"
#include "Service.h"
class viewWidget : public QWidget
{
	Q_OBJECT

public:
	viewWidget(Service& service,Star s,QWidget *parent = Q_NULLPTR);
	~viewWidget();

private:
	Ui::viewWidget ui;
	Star s;
	Service& service;

	void paintEvent(QPaintEvent* event) override;
};
