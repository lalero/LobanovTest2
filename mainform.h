#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include "readfile.h"
#include "checkandwritestringlist.h"
#include "checkingships.h"



namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

    int globalError=0;
    int finalError = 0;
    int errorCheck = 0;
    QStringList linesFile;
    QStringList shipsZone;

private slots:
    void on_pushButton_clicked();
    void slot_readFileBack(QStringList stringlist);
    void slot_checkAndWriteStringListBack(QStringList stringlist, int mesEr1, int mesEr2);
    void slot_checkingShipsBack(int finErr,int errCheck);
//    void readFile();

signals:
    void signal_readFile(QString str);
    void signal_checkAndWriteStringList(QStringList stringlist);
    void signal_checkingShips(QStringList stringlist);

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
