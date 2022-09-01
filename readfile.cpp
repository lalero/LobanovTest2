#include "readfile.h"

ReadFile::ReadFile(QObject *parent)
    : QObject{parent}
{

}

void ReadFile::slot_readFile(QString str)
{
    linesFile.clear();

    QFile file(str);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    else
    {
        //qDebug() << "OK";
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        linesFile.append(line);
    }

    emit  signal_readFileBack(linesFile);
}

