#include "segmentsearchmodel.h"
#include <QtDebug>
#include <QStringListModel>
#include <QMimeData>

int SegmentSearchModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return segmentList.count();
}

QVariant SegmentSearchModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= segmentList.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return segmentList.at(index.row())->getText();
    if (role == 0x0100)
        return segmentList.at(index.row())->getPosition();
    if (role == 0x0101)
        return segmentList.at(index.row())->getLength();
    else
        return QVariant();
}

bool SegmentSearchModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{
    if (index.isValid()) {
        if (role == 0x100)
        {
            segmentList.at(index.row())->setPosition(value.toInt());
            emit dataChanged(index, index);
            return true;
        }
        if (role == 0x101)
        {
            segmentList.at(index.row())->setLength(value.toInt());
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

QVariant SegmentSearchModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

void SegmentSearchModel::setProgram(Program *prog)
{
    program = prog;
    qDebug() << "Program set";
}

void SegmentSearchModel::search(QString searchString)
{
    beginResetModel();
    qDeleteAll(segmentList);
    segmentList.clear();
    int from = 0;
    while(true)
    {
        from = program->getText().indexOf(searchString, from);
        if(from == -1) break;
        else
        {
            segmentList.append(new Segment(program, from, searchString.length()));
            from += 1;
        }

        //qDebug() << QString::number(from);
    }
    endResetModel();
}

Qt::ItemFlags SegmentSearchModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractItemModel::flags(index);

    if (index.isValid())
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled;
    else
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

Qt::DropActions SegmentSearchModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

bool SegmentSearchModel::insertRows(int position, int rows, const QModelIndex &index = QModelIndex())
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        segmentList.insert(position, new Segment(program, 0, 0));
    }

    endInsertRows();
    return true;
}

bool SegmentSearchModel::removeRows(int position, int rows, const QModelIndex &index = QModelIndex())
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        segmentList.removeAt(position);
    }

    endRemoveRows();
    return true;
}


QStringList SegmentSearchModel::mimeTypes() const
{
    QStringList types;
    types << "application/vnd.segment.list";
    return types;
}

QMimeData *SegmentSearchModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    foreach (const QModelIndex &index, indexes) {
        if (index.isValid()) {
            stream << data(index, 0x100).toString() + "," + data(index, 0x101).toString();
        }
    }

    mimeData->setData("application/vnd.segment.list", encodedData);
    return mimeData;
}

bool SegmentSearchModel::canDropMimeData(const QMimeData *data,
    Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(parent);

    if (!data->hasFormat("application/vnd.segment.list"))
        return false;

    if (column > 0)
        return false;

    return true;
}

bool SegmentSearchModel::dropMimeData(const QMimeData *data,
    Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if (!canDropMimeData(data, action, row, column, parent))
        return false;

    if (action == Qt::IgnoreAction)
        return true;

    int beginRow;
    if (row != -1)
        beginRow = row;

    else if (parent.isValid())
        beginRow = parent.row();
    else
        beginRow = rowCount(QModelIndex());

    QByteArray encodedData = data->data("application/vnd.segment.list");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    QStringList newItems;
    int rows = 0;

    while (!stream.atEnd())
    {
        QString text;
        stream >> text;
        newItems << text;
        ++rows;
    }

    insertRows(beginRow, rows, QModelIndex());
    foreach (const QString &text, newItems)
    {
        QModelIndex idx = index(beginRow, 0, QModelIndex());
        qDebug() << idx;
        QStringList result = text.split(',');
        setData(idx, result[0], 0x100);
        setData(idx, result[1], 0x101);
        beginRow++;
    }

    return true;
}
