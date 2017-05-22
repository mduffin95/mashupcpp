#ifndef SEGMENTDELEGATE_H
#define SEGMENTDELEGATE_H

#include <QStyledItemDelegate>

class SegmentDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SegmentDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // SEGMENTDELEGATE_H
