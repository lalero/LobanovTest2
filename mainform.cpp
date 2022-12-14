#include "mainform.h"
#include "ui_mainform.h"
#include "iostream"

using namespace std;

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);

    model = new QStandardItemModel;
    model->insertColumns(0,10);
    model->setHeaderData(0,Qt::Horizontal,"A");
    model->setHeaderData(1,Qt::Horizontal,"B");
    model->setHeaderData(2,Qt::Horizontal,"C");
    model->setHeaderData(3,Qt::Horizontal,"D");
    model->setHeaderData(4,Qt::Horizontal,"I");
    model->setHeaderData(5,Qt::Horizontal,"F");
    model->setHeaderData(6,Qt::Horizontal,"G");
    model->setHeaderData(7,Qt::Horizontal,"H");
    model->setHeaderData(8,Qt::Horizontal,"I");
    model->setHeaderData(9,Qt::Horizontal,"J");

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Stretch);

    for (int i = 0; i < 10; i++)
    {
        model->insertRows(model->rowCount(),1);
        model->setData(model->index(model->rowCount()-1,0),"0",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,1),"1",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,2),"2",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,3),"3",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,4),"4",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,5),"5",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,6),"6",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,7),"7",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,8),"8",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,9),"9",Qt::BackgroundRole);
    }

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
    model = new QStandardItemModel;
    model->insertColumns(0,10);
    model->setHeaderData(0,Qt::Horizontal,"A");
    model->setHeaderData(1,Qt::Horizontal,"B");
    model->setHeaderData(2,Qt::Horizontal,"C");
    model->setHeaderData(3,Qt::Horizontal,"D");
    model->setHeaderData(4,Qt::Horizontal,"I");
    model->setHeaderData(5,Qt::Horizontal,"F");
    model->setHeaderData(6,Qt::Horizontal,"G");
    model->setHeaderData(7,Qt::Horizontal,"H");
    model->setHeaderData(8,Qt::Horizontal,"I");
    model->setHeaderData(9,Qt::Horizontal,"J");

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Stretch);

    for (int i = 0; i < 10; i++)
    {
        model->insertRows(model->rowCount(),1);
        model->setData(model->index(model->rowCount()-1,0),"0",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,1),"1",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,2),"2",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,3),"3",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,4),"4",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,5),"5",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,6),"6",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,7),"7",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,8),"8",Qt::BackgroundRole);
        model->setData(model->index(model->rowCount()-1,9),"9",Qt::BackgroundRole);
    }

    linesFile.clear();
    shipsZone.clear();
    redShips.clear();

    globalError=0;
    finalError = 0;
    errorCheck = 0;

    QString str;
    str = QFileDialog::getOpenFileName();
//    str = QFileDialog::getOpenFileName(this, "Select file", "C:/Programms/",
//                                       "All Files (*.*);; TXT Files (*.txt);");
    ui->label->setText(str);

    emit signal_readFile(str);
}

void MainForm::slot_readFileBack(QStringList stringlist)
{
    linesFile = stringlist;

    emit signal_checkAndWriteStringList(linesFile);
}

void MainForm::slot_checkAndWriteStringListBack(QStringList stringlist, int mesEr1, int mesEr2)
{
    shipsZone = stringlist;

    int messageError1 = mesEr1;
    int messageError2 = mesEr2;

    globalError=0;
    if (messageError2==1)
    {
        ui->textEdit->setText("Error! Characters in contact with the Ships placement are detected. Remove them for the correct operation of the program. Ships placement must be 10x10");
        globalError=1;
    }
    else
        if (messageError1==1)
        {
            ui->textEdit->setText("Error! No valid Ships placement with a size 10x10 with symbols '*' and '0' was found! Please specify an isolated 10x10 Ships placement");
            globalError=1;

        }

    if (globalError==0)
    {
        emit signal_checkingShips(shipsZone);
    }

    //???????????? globEr
}

void MainForm::slot_checkingShipsBack(int finErr,int errCheck, QStringList stringlist)
{
    finalError=finErr;
    errorCheck=errCheck;
    redShips = stringlist;

    if (errorCheck==0)
    {

        if (finalError==0)
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (shipsZone[i][j]=='*')
                    {
                        model->setData(model->index(i,j), QBrush(Qt::green), Qt::BackgroundRole);
                    }
                }
            }

            ui->textEdit->setText("It's okay. Ships placement is correct!");
        }
        else
            if (finalError == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (shipsZone[i][j]=='*')
                        {
                            model->setData(model->index(i,j), QBrush(Qt::green), Qt::BackgroundRole);
                        }
                    }
                }

                ui->textEdit->setText("ERROR! Wrong number of ships!");
            }

    }
    else
    {

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (shipsZone[i][j]=='*')
                {
                    model->setData(model->index(i,j), QBrush(Qt::green), Qt::BackgroundRole);
                }
            }
        }

        int sizeRedShips = 0;
        while (sizeRedShips<redShips.size())
        {
            QString line = redShips[sizeRedShips][0];
            QString column = redShips[sizeRedShips][1];

            int lineInt = 0;
            lineInt = line.toInt();
            int columnInt = 0;
            columnInt = column.toInt();

            model->setData(model->index(lineInt,columnInt), QBrush(Qt::red), Qt::BackgroundRole);

            sizeRedShips++;
        }

        ui->textEdit->setText("ERROR! Wrong position of ships! The ships are touching!");
    }
}
