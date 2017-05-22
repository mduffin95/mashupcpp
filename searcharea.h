#ifndef SEARCHAREA_H
#define SEARCHAREA_H
#include "program.h"
#include "segment.h"
#include "segmentlistmodel.h"
#include <QDockWidget>

namespace Ui {
class SearchArea;
}

class SearchArea : public QDockWidget
{
    Q_OBJECT

public:
    explicit SearchArea(QWidget *parent = 0);
    ~SearchArea();

    void setProgram(Program *prog);

private slots:
    void on_searchButton_clicked();

private:
    Ui::SearchArea *ui;
    Program *prog;
    SegmentListModel *model;
    QString text;

    void search(QString searchString, QVector<Segment*> &results);
};

#endif // SEARCHAREA_H
