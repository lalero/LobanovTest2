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
    void siganl_readFile(QString str);

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
