#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Sea battle");

    setFixedSize(454,540);

    MainForm *window = new MainForm(this);
    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

