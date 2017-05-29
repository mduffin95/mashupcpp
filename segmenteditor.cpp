#include "segmenteditor.h"
#include "program.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

SegmentEditor::SegmentEditor(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

void SegmentEditor::setupUi(QWidget *widget)
{
    leftButton = new QPushButton("left");
    rightButton = new QPushButton("right");
    label =  new QLabel(widget); //This will go in between the two buttons

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(leftButton);
    layout->addWidget(label);
    layout->addWidget(rightButton);
    widget->setLayout(layout);
}

void SegmentEditor::setReference(QStringRef r)
{
    ref = r;
    label->setText(ref.toString());
}

QStringRef SegmentEditor::getReference()
{
    return ref;
}
