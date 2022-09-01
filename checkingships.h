#ifndef CHECKINGSHIPS_H
#define CHECKINGSHIPS_H

#include <QObject>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDebug>


class CheckingShips : public QObject
{
    Q_OBJECT
public:
    explicit CheckingShips(QObject *parent = nullptr);

    int finalError=0;
    int finalError2=0;
public slots:
    void slot_checkingShips(QStringList stringlist);

signals:
    void signal_checkingShipsBack(int finErr,int errCheck, QStringList stringlist);

};

#endif // CHECKINGSHIPS_H
