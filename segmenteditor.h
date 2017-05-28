#ifndef SEGMENTEDITOR_H
#define SEGMENTEDITOR_H

#include <QWidget>

class SegmentEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SegmentEditor(QWidget *parent = 0);

    void setupUi(QWidget *widget);

signals:

public slots:
};

#endif // SEGMENTEDITOR_H
