#include "readfile.h"
//#include "MainForm.h"

ReadFile::ReadFile(QObject *parent)
    : QObject{parent}
{

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

