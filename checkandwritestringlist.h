#ifndef CHECKANDWRITESTRINGLIST_H
#define CHECKANDWRITESTRINGLIST_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QStringList>


class CheckAndWriteStringList : public QObject
{
    Q_OBJECT
public:
    explicit CheckAndWriteStringList(QObject *parent = nullptr);

    QStringList linesFile;
    QStringList shipsZone;

public slots:
    void slot_checkAndWriteStringList(QStringList stringlist);

signals:
    void signal_checkAndWriteStringListBack(QStringList stringlist, int mesEr1, int mesEr2);

};

#endif // CHECKANDWRITESTRINGLIST_H
