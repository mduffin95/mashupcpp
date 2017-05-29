#ifndef SEGMENTDELEGATE_H
#define SEGMENTDELEGATE_H

#include "program.h"
#include <QStyledItemDelegate>

class SegmentDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SegmentDelegate(Program *prog, QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    Program *program;
};

#endif // SEGMENTDELEGATE_H
