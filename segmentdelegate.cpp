#include "segmentdelegate.h"
#include "constants.h"
#include "segmenteditor.h"
#include <QSpinBox>
#include <QLineEdit>

SegmentDelegate::SegmentDelegate(Program *prog, QObject */* parent */) : program(prog)
{

}

QWidget *SegmentDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    SegmentEditor *editor = new SegmentEditor;

    return editor;
}

void SegmentDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QString encoding = index.model()->data(index, Constants::SerializeRole).toString();

    QStringList result = encoding.split(',');
    Q_ASSERT(result.length() == 2);

    SegmentEditor *segEdit = static_cast<SegmentEditor*>(editor);
    QStringRef ref = program->getStringRef(result[0].toInt(), result[1].toInt());
    segEdit->setReference(ref);
}

void SegmentDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    SegmentEditor *segEdit = static_cast<SegmentEditor*>(editor);
    QStringRef ref = segEdit->getReference();

    QString text = QString::number(ref.position()) + "," + QString::number(ref.length());

    model->setData(index, text, Constants::SerializeRole);
}

void SegmentDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
