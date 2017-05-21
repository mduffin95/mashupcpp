#ifndef SEGMENTSEARCHMODEL_H
#define SEGMENTSEARCHMODEL_H

#include "program.h"
#include "segment.h"
#include <QAbstractListModel>

class SegmentSearchModel : public QAbstractListModel
{
    Q_OBJECT

public:
    SegmentSearchModel(QObject *parent = 0)
        : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::DropActions supportedDropActions() const;
    bool insertRows(int position, int rows, const QModelIndex &index);
    bool removeRows(int position, int rows, const QModelIndex &index);

    QStringList mimeTypes() const;
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool canDropMimeData(const QMimeData *data,
        Qt::DropAction action, int row, int column, const QModelIndex &parent);
    bool dropMimeData(const QMimeData *data,
        Qt::DropAction action, int row, int column, const QModelIndex &parent);

    void setProgram(Program *prog);

    void search(QString searchString);
private:
    Program *program;
    QList<Segment*> segmentList;
};

#endif // SEGMENTLISTMODEL_H
