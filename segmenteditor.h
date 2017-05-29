#ifndef SEGMENTEDITOR_H
#define SEGMENTEDITOR_H

#include "program.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class SegmentEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SegmentEditor(QWidget *parent = 0);

    void setupUi(QWidget *widget);
    void insert(QString text);
    void setReference(QStringRef r);
    QStringRef getReference();
private:
    QPushButton *leftButton;
    QPushButton *rightButton;
    QLabel *label;
    QStringRef ref;

signals:

public slots:
};

#endif // SEGMENTEDITOR_H
