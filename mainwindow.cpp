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
    program = new Program(fileName, "");
    qDebug() << fileName;

    SegmentDelegate *delegate = new SegmentDelegate(program);
    view->setItemDelegate(delegate);

    model->setProgram(program);
    searchArea->setProgram(program);
}
