#include "mainform.h"
#include "ui_mainform.h"
#include "iostream"

#include <QFile>

using namespace std;

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    // создать таблицу с полем и красить ячейки

    ui->setupUi(this);

    ReadFile  *read = new ReadFile(this);
    CheckAndWriteStringList  *checkStringlist = new CheckAndWriteStringList(this);


    connect(this,&MainForm::signal_readFile,read,&ReadFile::slot_readFile);
    connect(read,&ReadFile::signal_readFileBack,this,&MainForm::slot_readFileBack);

    connect(this,&MainForm::signal_checkAndWriteStringList,checkStringlist,&CheckAndWriteStringList::slot_checkAndWriteStringList);
    //connect(read,&ReadFile::signal_readFileBack,this,&MainForm::slot_readFileBack);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_pushButton_clicked()
{
    linesFile.clear();

    QString str;
    str = QFileDialog::getOpenFileName(this, "Select file", "C:/Programms/",
                                       "All Files (*.*);; TXT Files (*.txt);");

    emit signal_readFile(str);
}

void MainForm::slot_readFileBack(QStringList stringlist)
{
    linesFile = stringlist;

    qDebug()<<"linesFile="<<linesFile;

    emit signal_checkAndWriteStringList(linesFile);
}

