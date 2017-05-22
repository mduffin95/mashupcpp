#include "searcharea.h"
#include "ui_searcharea.h"
#include "segment.h"
#include "segmentlistmodel.h"

#include <QtDebug>

SearchArea::SearchArea(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::SearchArea)
{
    ui->setupUi(this);
    model = new SegmentListModel;
    ui->listView->setModel(model);
    //ui->listView->setDragDropMode(QAbstractItemView::DragDrop);

    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    //ui->listView->setDragEnabled(true);
    //ui->listView->setAcceptDrops(true);
    ui->listView->setDragDropMode(QAbstractItemView::DragOnly);
    ui->listView->setDropIndicatorShown(true);
    ui->listView->setDragDropOverwriteMode(false);
    ui->listView->setDefaultDropAction(Qt::CopyAction);
}

SearchArea::~SearchArea()
{
    delete ui;
}

void SearchArea::setProgram(Program *prog)
{
    model->setProgram(prog);
}

void SearchArea::on_searchButton_clicked()
{
    qDebug() << "Clicked";
    QString searchString = ui->lineEdit->text();
    //QVector<Segment*> results;
    model->search(searchString);
}


