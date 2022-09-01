#include "checkingships.h"

CheckingShips::CheckingShips(QObject *parent)
    : QObject{parent}
{

}

void CheckingShips::slot_checkingShips(QStringList stringlist)
{
    //QStringList shipsZone;
    //QStringList allShips;

    // Проверка на близлежащие клетки

    QStringList fakeLineShips;
    QStringList fakeColumnShips;
    QStringList sizeShips;
    QStringList shipsZone;
    QStringList greeenShips;
    QStringList redShips;
    shipsZone=stringlist;

    qDebug()<<"shipsZone="<<shipsZone;

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

                //                qDebug()<<"shipsZone[lineCheck][columnCheck]="<<shipsZone[lineCheck][columnCheck];
                //                qDebug()<<"shipsZone[lineCheck-1][columnCheck-1]="<<shipsZone[lineCheck-1][columnCheck-1];
                //                qDebug()<<"shipsZone[lineCheck-1][columnCheck+1]="<<shipsZone[lineCheck-1][columnCheck+1];
                //                qDebug()<<"shipsZone[lineCheck+1][columnCheck-1]="<<shipsZone[lineCheck+1][columnCheck-1];
                //                qDebug()<<"shipsZone[lineCheck+1][columnCheck+1]="<<shipsZone[lineCheck+1][columnCheck+1];

                if ((lineCheck==0)&&(columnCheck==0))
                {
                    if (shipsZone[lineCheck+1][columnCheck+1]=='*')
                    {
                        QString a1 = QString::number(lineCheck);
                        QString a2 = QString::number(columnCheck);
//                        QString a3 = QString::number(lineCheck+1);
//                        QString a4 = QString::number(columnCheck+1);
                        QString allA = a1+a2;
                        redShips.append(allA);

                        //qDebug()<<"11111";
                        errorCheck++;
                    }

                    if ((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                    {
                        QString a1 = QString::number(lineCheck);
                        QString a2 = QString::number(columnCheck);
                        QString allA = a1+a2;
                        redShips.append(allA);

                        //qDebug()<<"22222";
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
                            //qDebug()<<"111111";
                            errorCheck++;
                        }

                        if ((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                        {
                            QString a1 = QString::number(lineCheck);
                            QString a2 = QString::number(columnCheck);
                            QString allA = a1+a2;
                            redShips.append(allA);
                            //qDebug()<<"222222";
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
                                //qDebug()<<"3";
                                errorCheck++;
                            }

                            if ((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*'))
                            {
                                QString a1 = QString::number(lineCheck);
                                QString a2 = QString::number(columnCheck);
                                QString allA = a1+a2;
                                redShips.append(allA);
                                //qDebug()<<"4";
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
                                    //qDebug()<<"5";
                                    errorCheck++;
                                }

                                if ((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*'))
                                {
                                    QString a1 = QString::number(lineCheck);
                                    QString a2 = QString::number(columnCheck);
                                    QString allA = a1+a2;
                                    redShips.append(allA);
                                    //qDebug()<<"6";
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
                                        //qDebug()<<"1";
                                        errorCheck++;
                                    }

                                    if (((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*'))
                                            ||((shipsZone[lineCheck+1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*')))
                                    {
                                        QString a1 = QString::number(lineCheck);
                                        QString a2 = QString::number(columnCheck);
                                        QString allA = a1+a2;
                                        redShips.append(allA);
                                        //qDebug()<<"2";
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
                                            //qDebug()<<"11";
                                            errorCheck++;
                                        }

                                        if (((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck-1][columnCheck]=='*'))
                                                ||((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*')))
                                        {
                                            QString a1 = QString::number(lineCheck);
                                            QString a2 = QString::number(columnCheck);
                                            QString allA = a1+a2;
                                            redShips.append(allA);
                                            //qDebug()<<"22";
                                            errorCheck++;
                                        }
                                    }
                                    else
                                        if (columnCheck==0)
                                        {
                                            //                    qDebug()<<"23131323";
                                            //                    qDebug()<<"lineCheck="<<lineCheck;
                                            //                    qDebug()<<"columnCheck="<<columnCheck;
                                            if ((shipsZone[lineCheck-1][columnCheck+1]=='*')||(shipsZone[lineCheck+1][columnCheck+1]=='*'))
                                            {
                                                QString a1 = QString::number(lineCheck);
                                                QString a2 = QString::number(columnCheck);
                                                QString allA = a1+a2;
                                                redShips.append(allA);
                                                //qDebug()<<"111";
                                                errorCheck++;
                                            }

                                            if (((shipsZone[lineCheck-1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck+1]=='*'))
                                                    ||((shipsZone[lineCheck][columnCheck+1]=='*')&&(shipsZone[lineCheck+1][columnCheck]=='*')))
                                            {
                                                QString a1 = QString::number(lineCheck);
                                                QString a2 = QString::number(columnCheck);
                                                QString allA = a1+a2;
                                                redShips.append(allA);
                                                //qDebug()<<"222";
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
                                                    //qDebug()<<"1111";
                                                    errorCheck++;
                                                }

                                                if (((shipsZone[lineCheck][columnCheck-1]=='*')&&(shipsZone[lineCheck-1][columnCheck]=='*'))
                                                        ||((shipsZone[lineCheck+1][columnCheck]=='*')&&(shipsZone[lineCheck][columnCheck-1]=='*')))
                                                {
                                                    QString a1 = QString::number(lineCheck);
                                                    QString a2 = QString::number(columnCheck);
                                                    QString allA = a1+a2;
                                                    redShips.append(allA);
                                                    //qDebug()<<"2222";
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
                                                    //qDebug()<<"111111111111";
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
                                                    //qDebug()<<"2222222222";
                                                    errorCheck++;
                                                }
                                            }

                //+проверка угловых

            }


            columnCheck++;
        }
        //selectPointsShips="";

        lineCheck++;
    }

    qDebug()<<"redShips="<<redShips;

    ////////////////////////*////////////////////////////////////////////////////////

//    if (errorCheck==0)   //тут мб errorCheck>0
//    {


        // Проверка на близлежащие клетки

        QString usedPointsShips="";

        QString allPointsShips="";
        QString selectPointsShips="";


        QString strFakeLineShips="";
        QString strFakeColumnShips="";

        int countChecksPoints=0;
        int line = 0;
        int column = 0;

        //for (int line = 0; line < 10; line++)
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
                            //strFakeLineShips = strFakeLineShips + selectPointsShips;

                            selectPointsShips="";
                            countPoint=0;
                        }
                    }

                }
                else
                    if (countPoint !=0)
                    {
                        fakeLineShips.append(selectPointsShips);
                        //strFakeLineShips = strFakeLineShips + selectPointsShips;

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
                    //allPointsShips = allPointsShips+str1+str2;
                    //countChecksPoints++;

                    countPoint++;
                    selectPointsShips = selectPointsShips+str1+str2;


                    if (line==9)
                    {
                        if (countPoint !=0)
                        {
                            fakeColumnShips.append(selectPointsShips);

                            //strFakeColumnShips = strFakeColumnShips + selectPointsShips;

                            selectPointsShips="";
                            countPoint=0;
                        }
                    }

                }
                else
                    if (countPoint !=0)
                    {
                        fakeColumnShips.append(selectPointsShips);

                        //strFakeColumnShips = strFakeColumnShips + selectPointsShips;
                        selectPointsShips="";
                        countPoint=0;
                    }

                line++;
            }
            selectPointsShips="";

            column++;
        }

        //qDebug()<<"fakeLineShips="<<fakeLineShips;
        //qDebug()<<"fakeColumnShips="<<fakeColumnShips;

        //    qDebug()<<"fakeLineShips.size()="<<fakeLineShips.size();
        //    qDebug()<<"fakeColumnShips.size()="<<fakeColumnShips.size();


        /*

    /////////////////////////////////////////////////////////////////////////////////////////
    //ДЛЯ 2 ЧАСТИ ПРОГРАММЫ


    int countI=0;
    int countJ=0;

    int kUp=0;
    int kDown=0;

    int qUp=0;
    int qDown=0;

    while (kUp<fakeLineShips.size())
    {
        //kDown=0;

        //qDebug()<<"fakeLineShips[countI].size()-2="<<fakeLineShips[kDown].size()-2;

//        for (int countI = 0; countI < fakeLineShips[countI].size()-2; countI++)
//        {

        int kDown=0;
        while (kDown < fakeLineShips[kUp].size()) //мб без -1
        {
            QString point1LineShips = fakeLineShips[kUp][kDown];
            QString point2LineShips = fakeLineShips[kUp][kDown+1];

            //qDebug()<<"point1LineShips="<<point1LineShips;
            //qDebug()<<"point2LineShips="<<point2LineShips;



            while (qUp<fakeColumnShips.size())//
            {
                //int q=0;
                //qDebug()<<"1";
                while (qDown<fakeColumnShips[qUp].size()) //мб без -1
                {
                    //qDebug()<<"qDown="<<qDown;
                    QString point1ColumnShips = fakeColumnShips[qUp][qDown];
                    QString point2ColumnShips = fakeColumnShips[qUp][qDown+1];

                    //qDebug()<<"point1ColumnShips="<<point1ColumnShips;
                    //qDebug()<<"point2ColumnShips="<<point2ColumnShips;
                    //qDebug()<<"fakeColumnShips[qUp].size()="<<fakeColumnShips[qUp].size();

                    //qDebug()<<"kUp="<<kUp;


                    //&&(fakeLineShips[qUp].size()>2)
                    if ((point1LineShips==point1ColumnShips)&&(point2LineShips==point2ColumnShips)&&(fakeLineShips[kUp].size()>2)&&(fakeColumnShips[qUp].size()>2))
                    {
                        //qDebug()<<"fakeColumnShips["<<qUp<<"].size()="<<fakeLineShips[qUp].size();
                        //qDebug()<<"point1LineShips="<<point1LineShips;
                        //qDebug()<<"point2LineShips="<<point2LineShips;



                        QString povtor = point1ColumnShips+point2ColumnShips;

                        //int countSpace = fakeColumnShips[qUp].size();

                        QString noSpace;

                        //for (int i = 0; i <  fakeColumnShips[qUp].size(); i++)
                        //qDebug()<<"fakeColumnShips[qUp]="<<fakeColumnShips[qUp];

                        int countNoSpace=0;
                        while (countNoSpace < fakeColumnShips[qUp].size())
                        {
//                            QString point1ColumnShips = fakeColumnShips[qUp][qDown];
//                            QString point2ColumnShips = fakeColumnShips[qUp][qDown+1];

                            //qDebug()<<"point1ColumnShips="<<point1ColumnShips;
                            //qDebug()<<"point2ColumnShips="<<point2ColumnShips;

//                            qDebug()<<"fakeColumnShips[qUp][countNoSpace]="<<fakeColumnShips[qUp][countNoSpace];
//                            qDebug()<<"fakeColumnShips[qUp][countNoSpace+1]="<<fakeColumnShips[qUp][countNoSpace+1];

                            if ((fakeColumnShips[qUp][countNoSpace]!=point1ColumnShips)||(fakeColumnShips[qUp][countNoSpace+1]!=point2ColumnShips))
                            {
                                noSpace = noSpace + fakeColumnShips[qUp][countNoSpace]+ fakeColumnShips[qUp][countNoSpace+1];
                                //qDebug()<<"22222222222222222222";
                            }

                            countNoSpace=countNoSpace+2;
                        }

//                        QString strSpace;
//                        for (int i = 0; i <  fakeColumnShips[qUp].size(); i++)
//                        {
//                            strSpace = strSpace+" ";
//                        }

                        //fakeColumnShips[qUp]=strSpace;

                        //тут работаю

                        //qDebug()<<"noSpace="<<noSpace;

                        //QString strX=point1ColumnShips+point2ColumnShips;

                        //все одинаковые плюсовать

                        QString strOld;

                        for (int i = 0; i < fakeLineShips[kUp].size(); i++)
                        {

                            strOld = strOld + fakeLineShips[kUp][i];
                        }

                        QString final = strOld+noSpace;

                        //qDebug()<<"final="<<final;

                        //fakeLineShips[kUp]=final;

                        allShips.append(final);

                        //qDebug()<<"+++";
                    }

                    //q=q+2;
                    qDown=qDown+2;
                }
                //qDebug()<<"----";
                qDown=0;

                qUp++;
            }


//            if (qUp != fakeColumnShips.size()-1)
//            {
                qUp=0;
//            }

            qDown=0;
            kDown=kDown+2;
        }



        //kDown++;

//        }


//        if (qUp != fakeColumnShips.size())
//        {
//            qUp=0;
//        }

        kUp++;

         //fakeLineShips.removeAll();
    }

    //qDebug()<<"strOld="<<strOld;

    qDebug()<<"allShips="<<allShips;
//    qDebug()<<"fakeColumnShips="<<fakeColumnShips;

///////////////////////////////////////////////////////////////////////

    */




        //int pointShip=0;

        //    int qUp=0;
        //    int qDown=0;

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

        /* ------переделать в поиск по shipsZone

    //int q=lineShip;
    while(lineShip<fakeLineShips.size())
    {
        int pointShip=0;


        while (pointShip < fakeLineShips[lineShip].size())
        {
            QString point1LineShips = fakeLineShips[lineShip][pointShip];
            QString point2LineShips = fakeLineShips[lineShip][pointShip+1];
            int intPoint1LineShips = point1LineShips.toInt();
            int intPoint2LineShips = point2LineShips.toInt();

//            qDebug()<<"intPoint1LineShips="<<intPoint1LineShips;
//            qDebug()<<"intPoint2LineShips="<<intPoint2LineShips;

            int q=pointShip;
            while (q<fakeLineShips.size())
            {

                int p=0;
                while (p<fakeLineShips[q].size())
                {
                    QString test1LineShips = fakeLineShips[q][p];
                    QString test2LineShips = fakeLineShips[q][p+1];
                    int intTest1LineShips = point1LineShips.toInt();
                    int intTest2LineShips = point2LineShips.toInt();


//                    if((intPoint1LineShips==+1)&&(intPoint2LineShips==))
//                    {

//                    }

                    p=p+2;
                }

                q++;
            }

            pointShip = pointShip+2;
        }
//                if ((q!=now)&&(q+1!=now+1))
//                {
//                    qDebug()<<"point1LineShips="<<point1LineShips;
//                    qDebug()<<"point2LineShips="<<point2LineShips;
//                }

        lineShip++;
    }

    */


        lineShip =0;
        while (lineShip<fakeLineShips.size())
        {
            int pointShip=0;
            int countPointLineShip=0;

            while (pointShip < fakeLineShips[lineShip].size())
            {
                QString point1LineShips = fakeLineShips[lineShip][pointShip];
                QString point2LineShips = fakeLineShips[lineShip][pointShip+1];

//                qDebug()<<"point1LineShips="<<point1LineShips;
//                qDebug()<<"point2LineShips="<<point2LineShips;

                //qDebug()<<"point1LineShips="<<point1LineShips;
                //qDebug()<<"point2LineShips="<<point2LineShips;

                //            int now = pointShip;
                //int now2 = pointShip+1;



                //            for (int i = 0; i < fakeLineShips.size(); i++)
                //            {
                //                int q=0;
                //                while(q<fakeLineShips[i].size())
                //                {
                //                    if ()

                //                    q=q+2;
                //                }
                //            }

                if (fakeLineShips[lineShip].size()==2)
                {


                    for (int i = 0; i < fakeColumnShips.size(); i++)
                    {
                        int countSizeColumnShips = fakeColumnShips[i].size();
                        //qDebug()<<"countSizeColumnShips="<<countSizeColumnShips;

                        //for (int j = 0; j < fakeLineShips[i].size()-1; j++)
                        int j=0;
                        while (j < fakeColumnShips[i].size())
                        {



                            if ((point1LineShips!=fakeColumnShips[i][j])||(point2LineShips!=fakeColumnShips[i][j+1]))
                            {
                                //qDebug()<<"fakeColumnShips[i].size()="<<fakeColumnShips.size();

                                //                            qDebug()<<"point1LineShips="<<point1LineShips;
                                //                            qDebug()<<"point2LineShips="<<point2LineShips;
                                //                            qDebug()<<"fakeColumnShips[i][j]="<<fakeColumnShips[i][j];
                                //                            qDebug()<<"fakeColumnShips[i][j+1])="<<fakeColumnShips[i][j+1];

                                //                            if((countSizeColumnShips==2)&&(point1LineShips==fakeColumnShips[i][j])&&(point2LineShips==fakeColumnShips[i][j+1]))
                                //                            {
                                //                                countPointLineShip++;
                                //                            }
                                //                            else
                                //                            {
                                error1=1;
                                //                            }

                                //countPointLineShip++;

                            }
                            else
                            {
                                if((countSizeColumnShips==2)&&((point1LineShips==fakeColumnShips[i][j])||(point2LineShips==fakeColumnShips[i][j+1])))
                                {



                                    countPointLineShip++;
                                    error2=1;
                                }

                                //countPointLineShip++;

                            }

                            j=j+2;

                        }

                    }
                }
                else
                {
                    //                QString point1LineShips = fakeLineShips[lineShip][pointShip];
                    //                QString point2LineShips = fakeLineShips[lineShip][pointShip+1];



                    //                for (int i = 0; i < fakeColumnShips.size(); i++)
                    //                {
                    //                    int q=0;
                    //                    while(q<fakeColumnShips[i].size())
                    //                    {


                    //                        q=q+2;
                    //                    }
                    //                }

                    countPointLineShip++;

                    //qDebug()<<"ELSE";
                }

                pointShip=pointShip+2;
            }

            if (((error1==0)||(error2==1))&&(countPointLineShip!=0)) //Появляются 0 если убрать (countPointLineShip!=0)
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


            //qDebug()<<"countPointLineShip="<<countPointLineShip; //мб записывать в стринглист все размеры кораблей

            lineShip++;
        }



        ////////////////////////////////////////////

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
                        //int countColumnLineShips = fakeColumnShips[i].size();


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

                            //                        else
                            //                        if((countSizeColumnShips==2)&&((point1LineShips==fakeColumnShips[i][j])||(point2LineShips==fakeColumnShips[i][j+1])))
                            //                        {
                            //                            countPointLineShip++;
                            //                            error2=1;
                            //                        }


                            j=j+2;

                        }

                    }
                }
                else
                {
                    countPointColumnShip++;
                    //qDebug()<<"ELSE";
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

        //qDebug()<<"sizeShips="<<sizeShips;

        //    int countRealShip1=0;
        //    int countNormalShip1=4;
        //    int countRealShip2=0;
        //    int countNormalShip2=3;
        //    int countRealShip3=0;
        //    int countNormalShip3=2;
        //    int countRealShip4=0;
        //    int countNormalShip4=1;

        QString strPointsShip;
        for (int i = 0; i < sizeShips.size(); i++)
        {
            strPointsShip = "";

            for (int j = 0; j < sizeShips[i].size(); j++)
            {
                strPointsShip = strPointsShip + sizeShips[i];
            }

            //qDebug()<<"strPointsShip="<<strPointsShip;

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
                            //qDebug()<<"ERRROOOOORRR";
                            finalError=1;
                        }

        }

        //qDebug()<<"countRealShip1="<<countRealShip1<<" countNormalShip4="<<countNormalShip4;
        //qDebug()<<"countRealShip2="<<countRealShip2<<" countNormalShip2="<<countNormalShip3;
        //qDebug()<<"countRealShip3="<<countRealShip3<<" countNormalShip3="<<countNormalShip2;
        //qDebug()<<"countRealShip4="<<countRealShip4<<" countNormalShip1="<<countNormalShip1;

        if ((countRealShip1!=countNormalShip1)||(countRealShip2!=countNormalShip2)
                ||(countRealShip3!=countNormalShip3)||(countRealShip4!=countNormalShip4))
        {
            finalError=1;

            //qDebug()<<"----------------------";
        }


//        if (finalError==0)
//        {
//            //cout << "It's okay. Ships placement is correct!" << endl;
//        }
//        else
//            if (finalError == 1)
//            {
//                //cout << "ERROR! Wrong number of ships!" << endl;
//            }

        ////////////////////////*//////////////////

//    }
//    else
//    {
//            finalError2 = 1;
//        //cout << "ERROR! Wrong position of ships! The ships are touching!" << endl;
//    }





    emit signal_checkingShipsBack(finalError, errorCheck, redShips);


    //    if (countRealShip4==countNormalShip4)
    //    {
    //        countRealShip4++;
    //    }
    //    else
    //        if (countRealShip3==countNormalShip3)
    //        {
    //            countRealShip3++;
    //        }
    //        else
    //            if (countRealShip2==countNormalShip2)
    //            {
    //                countRealShip2++;
    //            }
    //            else
    //                if (countRealShip1==countNormalShip1)
    //                {
    //                    countRealShip1++;
    //                }
    //                else
    //                {
    //                    finalError=1;
    //                }


    //qDebug()<<"allPointsShips="<<allPointsShips;
    //qDebug()<<"allPointsShips.size()="<<allPointsShips.size();
    //qDebug()<<"countChecksPoints="<<countChecksPoints;

    //    QString Ship="";

    //    int countChecksShips=0;
    //    int i = 0;
    //    int j = 0;
    //    QString lineStr;
    //    QString columnStr;
    //    int errorRadiusCheck=0;
    //    int intLineRadiusStep=0;
    //    int intColumnRadiusStep=0;
    //    int countError = 0;
    //    QString ship="";


    //qDebug()<<"allShips="<<allShips;



    /*

    while (allPointsShips.size()!=0)
    {
        lineStr = allPointsShips[i];
        columnStr = allPointsShips[i+1];

        ship=ship+lineStr+columnStr;

        allPointsShips[i]=' ';
        allPointsShips[i+1] = ' ';

        allPointsShips = allPointsShips.simplified();

        //allPointsShips.remove(0,2);

        //allPointsShips.remove(columnStr);


        int lineInt = lineStr.toInt();
        int columnInt = columnStr.toInt();

        shipsZone[lineInt][columnInt]='-';

//        for (int i = 0; i < allPointsShips.size(); i++)
//        {

//        }

        qDebug()<<"lineInt="<<lineInt;
        qDebug()<<"columnInt="<<columnInt;

        //qDebug()<<shipsZone[0][3];



        while (errorRadiusCheck==0)
        {
//        if ((shipsZone[lineInt-1][columnInt-1] == '*') ||
//                (shipsZone[lineInt-1][columnInt] == '*') ||
//                (shipsZone[lineInt-1][columnInt+1] == '*') ||
//                (shipsZone[lineInt][columnInt-1] == '*') ||
//                (shipsZone[lineInt][columnInt+1] == '*') ||
//                (shipsZone[lineInt+1][columnInt-1] == '*') ||
//                (shipsZone[lineInt+1][columnInt] == '*') ||
//                (shipsZone[lineInt+1][columnInt+1] == '*'))

            if (shipsZone[lineInt-1][columnInt] == '*')
                // проверять и на '-' в радиусе
            {
                intLineRadiusStep = lineInt-1;
                intColumnRadiusStep = columnInt;
                shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                countError=1;
            }
            else
                if (shipsZone[lineInt][columnInt-1] == '*')
                {
                    intLineRadiusStep = lineInt;
                    intColumnRadiusStep = columnInt-1;
                    shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                    countError=1;
                }
                else
                    if (shipsZone[lineInt][columnInt+1] == '*')
                    {
                        intLineRadiusStep = lineInt;
                        intColumnRadiusStep = columnInt+1;
                        shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                        countError=1;
                    }
                    else
                        if (shipsZone[lineInt+1][columnInt] == '*')
                        {
                            intLineRadiusStep = lineInt+1;
                            intColumnRadiusStep = columnInt;
                            shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                            countError=1;
                        }
                        else
                        {
                            errorRadiusCheck = 1;
                        }

            if (countError==0)
            {

            qDebug()<<"intLineRadiusStep="<<intLineRadiusStep;
            qDebug()<<"intColumnRadiusStep="<<intColumnRadiusStep;

            QString str1 = QString::number(intLineRadiusStep);
            QString str2 = QString::number(intColumnRadiusStep);

            ship=ship+str1+str2;


            for (int i = 0; i < allPointsShips.size()-1; i++)
            {
                if ((i%2!=0)&&(allPointsShips[i]==str1)&&(allPointsShips[i+1]==str2))
                {
                    allPointsShips[i]=' ';
                    allPointsShips[i+1]=' ';
                }

            }

            //allPointsShips.erase(intLineRadiusStep,intColumnRadiusStep);
//            allPointsShips = allPointsShips.simplified();
//            allPointsShips = allPointsShips.simplified();

            //qDebug()<<"shipsZone[intLineRadiusStep][intColumnRadiusStep]="<<shipsZone[intLineRadiusStep][intColumnRadiusStep];

            QString str;
            for (int i = 0; i < allPointsShips.size(); i++)
            {
                if (allPointsShips[i]!=' ')
                {
                  str = str + allPointsShips[i];
                }
            }
            allPointsShips.clear();
            allPointsShips.append(str);

            }
            countError=0;

        }



        //errorRadiusCheck=0;
        qDebug()<<"ship="<<ship;
        qDebug()<<"allPointsShips="<<allPointsShips;

        //allPointsShips="";
    }

    */


    //        for (int i = 0; i < allPointsShips.size()-2; i++)
    //        {
    //            QString selectedPoint = allPointsShips[i];

    //            QString str1 = allPointsShips[i];
    //            QString str2 = allPointsShips[i+1];

    //            Ship = Ship+str1+str2;

    //            if (i<allPointsShips.size()-2)
    //            {

    //                int j = i + 2;
    //                while (j < allPointsShips.size()-1)
    //                {
    //                    if (allPointsShips[i]==allPointsShips[j])
    //                    {
    //                        if (allPointsShips[i+1]==allPointsShips[j+1])
    //                        {
    //                            QString str1 = allPointsShips[i+1];
    //                            QString str2 = QString::number(column);

    //                        }
    //                    }

    //                    j=j+2;
    //                }
    //            }


    //        countChecksShips++;
    //    }



}
