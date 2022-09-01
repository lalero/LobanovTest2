#include "checkingships.h"

CheckingShips::CheckingShips(QObject *parent)
    : QObject{parent}
{

}

void CheckingShips::slot_checkingShips(QStringList stringlist)
{
    QStringList fakeLineShips;
    QStringList fakeColumnShips;
    QStringList sizeShips;
    QStringList shipsZone;
    QStringList greeenShips;
    QStringList redShips;
    QStringList redShipsUpd;
    shipsZone=stringlist;

    finalError=0;
    finalError2=0;

    int lineCheck = 0;
    int columnCheck = 0;
    int errorCheck=0;

    while (lineCheck < 10)
    {
        columnCheck = 0;
        while (columnCheck < 10)
        {
            if (shipsZone[lineCheck][columnCheck]=='*')
            {
                QString str1 = QString::number(lineCheck);
                QString str2 = QString::number(columnCheck);

                if ((lineCheck==0)&&(columnCheck==0))
                {
                    if (shipsZone[lineCheck+1][columnCheck+1]=='*')
                    {
                        QString a1 = QString::number(lineCheck);
                        QString a2 = QString::number(columnCheck);
                        QString allA = a1+a2;
                        redShips.append(allA);
                        errorCheck++;
                    }

                    if ((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                    {
                        QString a1 = QString::number(lineCheck);
                        QString a2 = QString::number(columnCheck);
                        QString allA = a1+a2;
                        redShips.append(allA);
                        errorCheck++;
                    }
                }
                else
                    if ((lineCheck==0)&&(columnCheck==9))
                    {
                        if (shipsZone[lineCheck+1][columnCheck-1]=='*')
                        {
                            QString a1 = QString::number(lineCheck);
                            QString a2 = QString::number(columnCheck);
                            QString allA = a1+a2;
                            redShips.append(allA);
                            errorCheck++;
                        }

                        if ((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                        {
                            QString a1 = QString::number(lineCheck);
                            QString a2 = QString::number(columnCheck);
                            QString allA = a1+a2;
                            redShips.append(allA);
                            errorCheck++;
                        }
                    }
                    else
                        if ((lineCheck==9)&&(columnCheck==9))
                        {
                            if (shipsZone[lineCheck-1][columnCheck-1]=='*')
                            {
                                QString a1 = QString::number(lineCheck);
                                QString a2 = QString::number(columnCheck);
                                QString allA = a1+a2;
                                redShips.append(allA);
                                errorCheck++;
                            }

                            if ((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*'))
                            {
                                QString a1 = QString::number(lineCheck);
                                QString a2 = QString::number(columnCheck);
                                QString allA = a1+a2;
                                redShips.append(allA);
                                errorCheck++;
                            }
                        }
                        else
                            if ((lineCheck==9)&&(columnCheck==0))
                            {
                                if (shipsZone[lineCheck-1][columnCheck+1]=='*')
                                {
                                    QString a1 = QString::number(lineCheck);
                                    QString a2 = QString::number(columnCheck);
                                    QString allA = a1+a2;
                                    redShips.append(allA);
                                    errorCheck++;
                                }

                                if ((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*'))
                                {
                                    QString a1 = QString::number(lineCheck);
                                    QString a2 = QString::number(columnCheck);
                                    QString allA = a1+a2;
                                    redShips.append(allA);
                                    errorCheck++;
                                }
                            }
                            else
                                if (lineCheck==0)
                                {
                                    if ((shipsZone[lineCheck+1][columnCheck-1]=='*')||(shipsZone[lineCheck+1][columnCheck+1]=='*'))
                                    {
                                        QString a1 = QString::number(lineCheck);
                                        QString a2 = QString::number(columnCheck);
                                        QString allA = a1+a2;
                                        redShips.append(allA);
                                        errorCheck++;
                                    }

                                    if (((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                                            ||((shipsZone[lineCheck+1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*')))
                                    {
                                        QString a1 = QString::number(lineCheck);
                                        QString a2 = QString::number(columnCheck);
                                        QString allA = a1+a2;
                                        redShips.append(allA);
                                        errorCheck++;
                                    }
                                }
                                else
                                    if (lineCheck==9)
                                    {
                                        if ((shipsZone[lineCheck-1][columnCheck-1]=='*')||(shipsZone[lineCheck-1][columnCheck+1]=='*'))
                                        {
                                            QString a1 = QString::number(lineCheck);
                                            QString a2 = QString::number(columnCheck);
                                            QString allA = a1+a2;
                                            redShips.append(allA);
                                            errorCheck++;
                                        }

                                        if (((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck-1][columnCheck]=='*'))
                                                ||((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*')))
                                        {
                                            QString a1 = QString::number(lineCheck);
                                            QString a2 = QString::number(columnCheck);
                                            QString allA = a1+a2;
                                            redShips.append(allA);
                                            errorCheck++;
                                        }
                                    }
                                    else
                                        if (columnCheck==0)
                                        {
                                            if ((shipsZone[lineCheck-1][columnCheck+1]=='*')||(shipsZone[lineCheck+1][columnCheck+1]=='*'))
                                            {
                                                QString a1 = QString::number(lineCheck);
                                                QString a2 = QString::number(columnCheck);
                                                QString allA = a1+a2;
                                                redShips.append(allA);
                                                errorCheck++;
                                            }

                                            if (((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*'))
                                                    ||((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*')))
                                            {
                                                QString a1 = QString::number(lineCheck);
                                                QString a2 = QString::number(columnCheck);
                                                QString allA = a1+a2;
                                                redShips.append(allA);
                                                errorCheck++;
                                            }
                                        }
                                        else
                                            if (columnCheck==9)
                                            {
                                                if ((shipsZone[lineCheck-1][columnCheck-1]=='*')||(shipsZone[lineCheck+1][columnCheck-1]=='*'))
                                                {
                                                    QString a1 = QString::number(lineCheck);
                                                    QString a2 = QString::number(columnCheck);
                                                    QString allA = a1+a2;
                                                    redShips.append(allA);
                                                    errorCheck++;
                                                }

                                                if (((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck-1][columnCheck]=='*'))
                                                        ||((shipsZone[lineCheck+1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*')))
                                                {
                                                    QString a1 = QString::number(lineCheck);
                                                    QString a2 = QString::number(columnCheck);
                                                    QString allA = a1+a2;
                                                    redShips.append(allA);
                                                    errorCheck++;
                                                }
                                            }

                                            else
                                            {
                                                if ((shipsZone[lineCheck-1][columnCheck-1]=='*')||(shipsZone[lineCheck-1][columnCheck+1]=='*')
                                                        ||(shipsZone[lineCheck+1][columnCheck-1]=='*')||(shipsZone[lineCheck+1][columnCheck+1]=='*'))
                                                {
                                                    QString a1 = QString::number(lineCheck);
                                                    QString a2 = QString::number(columnCheck);
                                                    QString allA = a1+a2;
                                                    redShips.append(allA);
                                                    errorCheck++;
                                                }

                                                if (((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck-1][columnCheck]=='*'))
                                                        ||((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*'))
                                                        ||((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                                                        ||((shipsZone[lineCheck+1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*')))
                                                {
                                                    QString a1 = QString::number(lineCheck);
                                                    QString a2 = QString::number(columnCheck);
                                                    QString allA = a1+a2;
                                                    redShips.append(allA);
                                                    errorCheck++;
                                                }
                                            }
            }
            columnCheck++;
        }

        lineCheck++;
    }

    QString usedPointsShips="";

    QString allPointsShips="";
    QString selectPointsShips="";


    QString strFakeLineShips="";
    QString strFakeColumnShips="";

    int countChecksPoints=0;
    int line = 0;
    int column = 0;

    int countPoint=0;

    while (line < 10)
    {
        column = 0;
        while (column < 10)
        {
            if (shipsZone[line][column]=='*')
            {
                QString str1 = QString::number(line);
                QString str2 = QString::number(column);
                allPointsShips = allPointsShips+str1+str2;
                countChecksPoints++;

                countPoint++;
                selectPointsShips = selectPointsShips+str1+str2;

                if (column==9)
                {
                    if (countPoint !=0)
                    {
                        fakeLineShips.append(selectPointsShips);

                        selectPointsShips="";
                        countPoint=0;
                    }
                }

            }
            else
                if (countPoint !=0)
                {
                    fakeLineShips.append(selectPointsShips);

                    selectPointsShips="";
                    countPoint=0;
                }

            column++;
        }
        selectPointsShips="";

        line++;
    }

    line = 0;
    column = 0;
    selectPointsShips="";
    while (column < 10)
    {
        line = 0;
        while (line < 10)
        {
            if (shipsZone[line][column]=='*')
            {
                QString str1 = QString::number(line);
                QString str2 = QString::number(column);
                countPoint++;
                selectPointsShips = selectPointsShips+str1+str2;


                if (line==9)
                {
                    if (countPoint !=0)
                    {
                        fakeColumnShips.append(selectPointsShips);
                        selectPointsShips="";
                        countPoint=0;
                    }
                }

            }
            else
                if (countPoint !=0)
                {
                    fakeColumnShips.append(selectPointsShips);
                    selectPointsShips="";
                    countPoint=0;
                }

            line++;
        }
        selectPointsShips="";

        column++;
    }


    int lineShip=0;
    int columnShip=0;
    int error1=0;
    int error2=0;
    int error3=0;
    int error4=0;
    int countRealShip1=0;
    int countNormalShip1=4;
    int countRealShip2=0;
    int countNormalShip2=3;
    int countRealShip3=0;
    int countNormalShip3=2;
    int countRealShip4=0;
    int countNormalShip4=1;

    lineShip =0;
    while (lineShip<fakeLineShips.size())
    {
        int pointShip=0;
        int countPointLineShip=0;

        while (pointShip < fakeLineShips[lineShip].size())
        {
            QString point1LineShips = fakeLineShips[lineShip][pointShip];
            QString point2LineShips = fakeLineShips[lineShip][pointShip+1];

            if (fakeLineShips[lineShip].size()==2)
            {


                for (int i = 0; i < fakeColumnShips.size(); i++)
                {
                    int countSizeColumnShips = fakeColumnShips[i].size();

                    int j=0;
                    while (j < fakeColumnShips[i].size())
                    {



                        if ((point1LineShips!=fakeColumnShips[i][j])||(point2LineShips!=fakeColumnShips[i][j+1]))
                        {
                            error1=1;
                        }
                        else
                        {
                            if((countSizeColumnShips==2)&&((point1LineShips==fakeColumnShips[i][j])||(point2LineShips==fakeColumnShips[i][j+1])))
                            {
                                countPointLineShip++;
                                error2=1;
                            }
                        }

                        j=j+2;

                    }

                }
            }
            else
            {
                countPointLineShip++;
            }

            pointShip=pointShip+2;
        }

        if (((error1==0)||(error2==1))&&(countPointLineShip!=0))
        {
            QString x = QString::number(countPointLineShip);
            sizeShips.append(x);
            countPointLineShip=0;
        }
        else
        {
            error1=0;
            error2=0;
        }

        lineShip++;
    }

    for (int i = 0; i < fakeColumnShips.size(); i++)
    {
        if (fakeColumnShips[i].size()>8)
        {
            int j=0;
            while (j<fakeColumnShips[i].size())
            {
                QString p1 = fakeColumnShips[i][j];
                QString p2 = fakeColumnShips[i][j+1];
                QString p12 = p1+p2;

                redShips.append(p12);

                j=j+2;
            }

        }
    }

    for (int i = 0; i < fakeColumnShips.size(); i++)
    {
        int j=0;
        while (j<fakeColumnShips[i].size())
        {
            QString p1 = fakeColumnShips[i][j];
            QString p2 = fakeColumnShips[i][j+1];
            QString p12 = p1+p2;

            int k=0;
            while (k<redShips.size())
            {
                if (p12==redShips[k])
                {

                    int q=0;
                    while (q<fakeColumnShips[i].size())
                    {
                        QString p3 = fakeColumnShips[i][q];
                        QString p4 = fakeColumnShips[i][q+1];
                        QString p34 = p3+p4;

                        redShips.append(p34);

                        q=q+2;
                    }
                    k=redShips.size();
                }

                k++;
            }

            j=j+2;
        }

    }

    for (int i = 0; i < fakeLineShips.size(); i++)
    {
        int j=0;
        while (j<fakeLineShips[i].size())
        {
            QString p1 = fakeLineShips[i][j];
            QString p2 = fakeLineShips[i][j+1];
            QString p12 = p1+p2;

            int k=0;
            while (k<redShips.size())
            {
                if (p12==redShips[k])
                {

                    int q=0;
                    while (q<fakeLineShips[i].size())
                    {
                        QString p3 = fakeLineShips[i][q];
                        QString p4 = fakeLineShips[i][q+1];
                        QString p34 = p3+p4;

                        redShips.append(p34);

                        q=q+2;
                    }
                    k=redShips.size();
                }

                k++;
            }



            j=j+2;
        }

    }

    for (int i = 0; i < fakeLineShips.size(); i++)
    {
        if (fakeLineShips[i].size()>8)
        {
            int j=0;
            while (j<fakeLineShips[i].size())
            {
                QString p1 = fakeLineShips[i][j];
                QString p2 = fakeLineShips[i][j+1];
                QString p12 = p1+p2;

                redShips.append(p12);

                j=j+2;
            }

        }
    }

    while (columnShip<fakeColumnShips.size())
    {
        int pointShip=0;
        int countPointColumnShip=0;
        while (pointShip < fakeColumnShips[columnShip].size())
        {
            if (fakeColumnShips[columnShip].size()==2)
            {

                QString point1ColumnShips = fakeColumnShips[columnShip][pointShip];
                QString point2ColumnShips = fakeColumnShips[columnShip][pointShip+1];

                for (int i = 0; i < fakeLineShips.size(); i++)
                {

                    int countSizeLineShips = fakeLineShips[i].size();

                    int j=0;
                    while (j < fakeLineShips[i].size())
                    {
                        if (((point1ColumnShips!=fakeLineShips[i][j])||(point2ColumnShips!=fakeLineShips[i][j+1]))
                                &&(countSizeLineShips!=2))
                        {

                            countPointColumnShip++;
                        }
                        else
                        {
                            error3=1;
                        }

                        j=j+2;

                    }

                }
            }
            else
            {
                countPointColumnShip++;
            }

            pointShip=pointShip+2;

        }

        if (((error3==0)||(error4==1))&&(countPointColumnShip!=0))
        {
            QString x = QString::number(countPointColumnShip);
            sizeShips.append(x);
            countPointColumnShip=0;
        }
        else
        {
            error3=0;
            error4=0;
        }

        columnShip++;
    }

    QString strPointsShip;
    for (int i = 0; i < sizeShips.size(); i++)
    {
        strPointsShip = "";

        for (int j = 0; j < sizeShips[i].size(); j++)
        {
            strPointsShip = strPointsShip + sizeShips[i];
        }

        int lineInt = strPointsShip.toInt();

        if (lineInt==1)
        {
            countRealShip1++;
        }
        else
            if (lineInt==2)
            {
                countRealShip2++;
            }
            else
                if (lineInt==3)
                {
                    countRealShip3++;
                }
                else
                    if (lineInt==4)
                    {
                        countRealShip4++;
                    }
                    else
                    {
                        finalError=1;
                    }

    }

    if ((countRealShip1!=countNormalShip1)||(countRealShip2!=countNormalShip2)
            ||(countRealShip3!=countNormalShip3)||(countRealShip4!=countNormalShip4))
    {
        finalError=1;
    }

    emit signal_checkingShipsBack(finalError, errorCheck, redShips);
}
