#include "segmentdelegate.h"
#include "constants.h"
#include "segmenteditor.h"
#include <QSpinBox>
#include <QLineEdit>

SegmentDelegate::SegmentDelegate(QObject */* parent */)
{

}

QWidget *SegmentDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    //TODO: Make my own editor
    //QLineEdit *editor = new QLineEdit(parent);
    SegmentEditor *editor = new SegmentEditor;
    //editor->setFrame(false);

    return editor;
}

void SegmentDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QString text = index.model()->data(index, Constants::SerializeRole).toString();

    //QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    //lineEdit->insert(text);
}

void SegmentDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString text = lineEdit->text();

    model->setData(index, text, Constants::SerializeRole);
}

void SegmentDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
