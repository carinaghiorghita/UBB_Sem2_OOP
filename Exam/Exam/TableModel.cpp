#include "TableModel.h"

int TableModel::rowCount(const QModelIndex& parent) const
{
	return this->service.getAllS().size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	Star s = this->service.getAllS()[index.row()];
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(s.getName());
		case 1:
			return QString::fromStdString(s.getConstel());
		case 2:
			return QString::number(s.getRA());
		case 3:
			return QString::number(s.getDec());
		case 4:
			return QString::number(s.getDiam());

		default:
			break;
		}
	}
	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Name");
			case 1:
				return QString("Constellation");
			case 2:
				return QString("RA");
			case 3:
				return QString("Dec");
			case 4:
				return QString("Diameter");

			default:
				break;

			}
		}
	}
	return QVariant();
}
