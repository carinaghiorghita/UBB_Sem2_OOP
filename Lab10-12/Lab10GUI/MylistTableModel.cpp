#include "MylistTableModel.h"

int MylistTableModel::rowCount(const QModelIndex& parent) const
{
	return this->service.getSizeSavedList();
}

int MylistTableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant MylistTableModel::data(const QModelIndex& index, int role) const
{
	Victim currentSaved = this->service.getAllVictimsInSavedList()[index.row()];
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(currentSaved.getName());
		case 1:
			return QString::fromStdString(currentSaved.getPlaceOfOrigin());
		case 2:
			return QString::number(currentSaved.getAge());
		case 3:
			return QString::fromStdString(currentSaved.getPhotograph());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant MylistTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
				return QString("Place");
			case 2:
				return QString("Age");
			case 3:
				return QString("Photograph");
			default:
				break;

			}
		}
	}
	return QVariant();
}
