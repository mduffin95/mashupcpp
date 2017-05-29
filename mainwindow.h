#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "searcharea.h"
#include "segmentlistmodel.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createDockWindows();

    QListView *view;
    SearchArea *searchArea;

    SegmentListModel *model;
    Program *program;

private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
