#include "mainform.h"
#include "ui_mainform.h"
#include "iostream"

#include <QFile>

using namespace std;

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    // создать таблицу с полем и красить ячейки

    ui->setupUi(this);

    ReadFile *read = new ReadFile(this);
    connect(this,&MainForm::signal_readFile,read,&ReadFile::slot_readFile);
    connect(read,&ReadFile::signal_readFileBack,this,&MainForm::slot_readFileBack);

    CheckAndWriteStringList *checkStringlist = new CheckAndWriteStringList(this);
    connect(this,&MainForm::signal_checkAndWriteStringList,checkStringlist,&CheckAndWriteStringList::slot_checkAndWriteStringList);
    connect(checkStringlist,&CheckAndWriteStringList::signal_checkAndWriteStringListBack,this,&MainForm::slot_checkAndWriteStringListBack);

    CheckingShips *ships = new CheckingShips(this);
    connect(this,&MainForm::signal_checkingShips,ships,&CheckingShips::slot_checkingShips);
    connect(ships,&CheckingShips::signal_checkingShipsBack,this,&MainForm::slot_checkingShipsBack);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_pushButton_clicked()
{
    linesFile.clear();

    QString str;
    str = QFileDialog::getOpenFileName(this, "Select file", "C:/Programms/",
                                       "All Files (*.*);; TXT Files (*.txt);");

    emit signal_readFile(str);
}

void MainForm::slot_readFileBack(QStringList stringlist)
{
    linesFile = stringlist;

    //qDebug()<<"linesFile="<<linesFile;

//    int o = 0;
//    while (o<10)
//    {
//        QString x="##########";
//        shipsZone.append(x);
//        o++;
//        //qDebug() << x;
//        //qDebug() << "1";
//    }

    emit signal_checkAndWriteStringList(linesFile);
}

void MainForm::slot_checkAndWriteStringListBack(QStringList stringlist, int mesEr1, int mesEr2)
{
    shipsZone = stringlist;

    int messageError1 = mesEr1;
    int messageError2 = mesEr2;


    //qDebug()<<"shipsZone="<<shipsZone;

    globalError=0;
    if (messageError2==1)
    {
        //Ошибка! Обнаружены символы, соприкасающиеся с полем. Уберите их для корректной работы программы. Поле должно быть размером 10х10;
        //cout << "Error! Characters in contact with the Ships placement are detected. Remove them for the correct operation of the program. Ships placement must be 10x10" << endl;
        ui->textEdit->setText("Error! Characters in contact with the Ships placement are detected. Remove them for the correct operation of the program. Ships placement must be 10x10");
        globalError=1;
    }
    else
        if (messageError1==1)
        {
            //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
            //cout << "Error! No valid Ships placement with a size 10x10 with symbols '*' and '0' was found! Please specify an isolated 10x10 Ships placement" << endl;
            ui->textEdit->setText("Error! No valid Ships placement with a size 10x10 with symbols '*' and '0' was found! Please specify an isolated 10x10 Ships placement");
            globalError=1;

        }

    if (globalError==0)
    {
        emit signal_checkingShips(shipsZone);
    }

    //учесть globEr
}

void MainForm::slot_checkingShipsBack(int finErr,int errCheck)
{
    finalError=finErr;
    errorCheck=errCheck;

    qDebug()<<"finalError="<<finalError;
    qDebug()<<"errorCheck="<<errorCheck;

    if (errorCheck==0)
    {

        if (finalError==0)
        {
            //cout << "It's okay. Ships placement is correct!" << endl;
            ui->textEdit->setText("It's okay. Ships placement is correct!");
        }
        else
            if (finalError == 1)
            {
                //cout << "ERROR! Wrong number of ships!" << endl;
                ui->textEdit->setText("ERROR! Wrong number of ships!");
            }
    }
    else
    {
        //cout << "ERROR! Wrong position of ships! The ships are touching!" << endl;
        ui->textEdit->setText("ERROR! Wrong position of ships! The ships are touching!");
    }


}

