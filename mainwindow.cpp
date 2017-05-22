#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searcharea.h"
#include "segmentdelegate.h"

#include <QFileDialog>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDockWindows();

    model = new SegmentListModel;
    view = new QListView;
    view->setModel(model);
    view->setDragDropMode(QAbstractItemView::DragDrop); //Accept drops from the search area
    view->setDropIndicatorShown(true);
    view->setDragDropOverwriteMode(false);
    view->setDefaultDropAction(Qt::MoveAction);
    SegmentDelegate *delegate = new SegmentDelegate;
    view->setItemDelegate(delegate);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDockWindows()
{
    searchArea = new SearchArea(this);
    searchArea->setAllowedAreas(Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea, searchArea);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    Program *prog = new Program(fileName, "");
    qDebug() << fileName;

    model->setProgram(prog);
    searchArea->setProgram(prog);
}
