#ifndef READFILE_H
#define READFILE_H

#include <QObject>
#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QStringList>

class ReadFile : public QObject
{
    Q_OBJECT
public:
    explicit ReadFile(QObject *parent = nullptr);

    QStringList linesFile;

public slots:
    void slot_readFile(QString str);


signals:
    void signal_readFileBack(QStringList stringlist);

};

#endif // READFILE_H
