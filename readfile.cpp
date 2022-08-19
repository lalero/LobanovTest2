#include "readfile.h"
//#include "MainForm.h"

ReadFile::ReadFile(QObject *parent)
    : QObject{parent}
{
//    MainForm *window = new MainForm(this);
//    setCentralWidget(window);

    //MainForm  *mainfor = new MainForm(this);
    //connect(MainForm,SIGNAL(siganl_readFile(str)),this,SLOT(readFile(QString str)));

    //connect(this,&MyTask::setbuff_in,DatabaseAccessor::getInstance(),&DatabaseAccessor::setbuff_in);
}

void ReadFile::slot_readFile(QString str)
{
    //QString str;
    linesFile.clear();

    QFile file(str);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //ui->textEdit->setText("Please select a file");

        return;
    }
    else
    {
        qDebug() << "OK";
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        linesFile.append(line);
    }
    qDebug()<<linesFile;

    emit  signal_readFileBack(linesFile);
}

//    QString str;
//    str = QFileDialog::getOpenFileName(this, "Select file", "C:/Programms/",
//                                       "All Files (*.*);; TXT Files (*.txt);");
//    ui->label->setText(str);

//    QFile file(str);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        ui->textEdit->setText("Please select a file");

//        return;
//    }
//    else
//    {
//        qDebug() << "OK";
//    }

//    QTextStream in(&file);
//    while (!in.atEnd())
//    {
//        QString line = in.readLine();
//        linesFile.append(line);
//    }
//        qDebug()<<linesFile;
