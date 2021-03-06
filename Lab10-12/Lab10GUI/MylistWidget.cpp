#include "MylistWidget.h"

MylistWidget::MylistWidget(Service& service,QWidget *parent)
	: QWidget(parent), service{service}
{
	ui.setupUi(this);
	MylistTableModel* model = new MylistTableModel(service);
	ui.tableView->setModel(model);
}

MylistWidget::~MylistWidget()
{
}
