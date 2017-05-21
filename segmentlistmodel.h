#ifndef SEGMENTLISTMODEL_H
#define SEGMENTLISTMODEL_H

#include "program.h"
#include "segment.h"
#include <QAbstractListModel>


class SegmentListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    SegmentListModel(QObject *parent = 0)
        : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);


    //bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    //bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());
    Qt::DropActions supportedDropActions() const;

    void setProgram(Program *prog);
private:
    Program *program;
    QList<Segment*> segmentList;
};

#endif // SEGMENTLISTMODEL_H
