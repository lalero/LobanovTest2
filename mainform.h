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



namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

    QStringList linesFile;

private slots:
    void on_pushButton_clicked();
    void slot_readFileBack(QStringList stringlist);
//    void readFile();

signals:
    void signal_readFile(QString str);
    void signal_checkAndWriteStringList(QStringList stringlist);

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
