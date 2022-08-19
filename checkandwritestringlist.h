#ifndef CHECKANDWRITESTRINGLIST_H
#define CHECKANDWRITESTRINGLIST_H

#include <QObject>

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

};

#endif // CHECKANDWRITESTRINGLIST_H
