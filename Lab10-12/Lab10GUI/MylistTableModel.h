#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"

class MylistTableModel : public QAbstractTableModel
{
private:
	Service& service;
	
public:
	MylistTableModel(Service& service) : service{ service } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

