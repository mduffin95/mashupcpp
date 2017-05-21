#include "segmentlistmodel.h"
#include <QtDebug>

int SegmentListModel::rowCount(const QModelIndex &parent) const
{
    return segmentList.count();
}

QVariant SegmentListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= segmentList.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return segmentList.at(index.row())->getText();
    else
        return QVariant();
}

QVariant SegmentListModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags SegmentListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool SegmentListModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{
    if (value.canConvert<Segment*>())
    {
        Segment *newSegment = value.value<Segment*>();
        if (index.isValid() && role == Qt::EditRole) {

            segmentList.replace(index.row(), newSegment);
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

/*
bool SegmentListModel::insertRows(int position, int rows, const QModelIndex &index = QModelIndex())
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        stringList.insert(position, "");
    }

    endInsertRows();
    return true;
}

bool SegmentListModel::removeRows(int position, int rows, const QModelIndex &index = QModelIndex())
{

}
*/

Qt::DropActions SegmentListModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

void SegmentListModel::setProgram(Program *prog)
{
    program = prog;
    qDebug() << "Program set";
}
