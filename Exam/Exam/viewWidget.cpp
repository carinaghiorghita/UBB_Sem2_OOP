#include "viewWidget.h"

viewWidget::viewWidget(Service& service,Star s,QWidget *parent)
	: QWidget(parent), service{ service },s{ s }
{
	ui.setupUi(this);
}

viewWidget::~viewWidget()
{
}

void viewWidget::paintEvent(QPaintEvent* event)
{
	vector<Star> stars = service.getByConstel(s.getConstel());
	QPainter painter(this);
	for (auto it : stars)
	{
		if (it.getName() == s.getName())
		{
			painter.setBrush(Qt::red);
		}
		else
		{
			painter.setBrush(Qt::black);
		}
		painter.drawEllipse(it.getRA(), it.getDec(), it.getDiam(), it.getDiam());
	}
}
