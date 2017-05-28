#include "segmenteditor.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

SegmentEditor::SegmentEditor(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

void SegmentEditor::setupUi(QWidget *widget)
{
    QPushButton *left = new QPushButton("left");
    QPushButton *right = new QPushButton("right");
    QLabel *text = new QLabel(widget); //This will go in between the two buttons

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(left);
    layout->addWidget(right);
    layout->addWidget(text);
    widget->setLayout(layout);
}
