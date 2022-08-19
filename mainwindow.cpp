#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainForm *window = new MainForm(this);
    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

