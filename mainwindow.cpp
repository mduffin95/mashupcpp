#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    textEdit(new QPlainTextEdit)
{
    ui->setupUi(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
