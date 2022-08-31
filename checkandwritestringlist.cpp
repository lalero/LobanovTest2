#include "checkandwritestringlist.h"

CheckAndWriteStringList::CheckAndWriteStringList(QObject *parent)
    : QObject{parent}
{

}

void CheckAndWriteStringList::slot_checkAndWriteStringList(QStringList stringlist)
{
    linesFile = stringlist;

    shipsZone.clear();
    int o = 0;
    while (o<10)
    {
        QString x="##########";
        shipsZone.append(x);
        o++;
        //qDebug() << x;
        //qDebug() << "1";
    }

    qDebug()<<"shipsZone="<<shipsZone;

    int linesSize = linesFile.size();
    int linesSizeEnd = 0;
    int countLine = 0;
    int countLeftUp = 0;
    int columnError = 0;
    int flagError = 0;
    int messageError1 = 1;
    int messageError2 = 0;
    //int messageError = 0;
    //int flagError2 = 0;
    int flagError3 = 0;
    //int countStepDown = 0;
    //int lengthNormal = 0;
    int countControl = 0;

    //qDebug()<<"linesSize="<<linesSize;
    //qDebug()<<"errorLength="<<errorLength;
    if (linesSize < 10)
    {
        //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
        //cout << "Error! Required field size (10x10) not found!" << endl;
        messageError1=1;
    }
    else
    {
        while (linesSize-1 > linesSizeEnd)
        {
            //qDebug()<<"linesFile[linesSizeEnd].length()="<<linesFile[linesSizeEnd].length();
            for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
            {
                if ((linesFile[linesSizeEnd][i]=='0')||(linesFile[linesSizeEnd][i]=='*'))
                {
                    countLine++;

                    if (countLine == 1)
                    {
                        countLeftUp = i;

                        //qDebug()<<"countLine="<<countLine;
                    }

                    //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                    //qDebug()<<"linesSize-1="<<linesSize-1;
                    countControl=linesSize-linesSizeEnd;

                    //(countLine == 10)
                    if ((countLine == 10)&&(countControl>=9))
                    {
                        int x=0;
                        int y=0;
                        //int pRight=0;
                        //int pRightCount=0;

                        //qDebug()<<"i="<<i;
                        //qDebug()<<"linesFile[linesSizeEnd].length()-1="<<linesFile[linesSizeEnd].length()-1;
                        //qDebug()<<"123456789";
                        //qDebug()<<"flagError="<<flagError;

                        //int countCheck=linesFile[linesSizeEnd].length()-1;

                        //qDebug()<<"linesFile[linesSizeEnd].length()="<<linesFile[linesSizeEnd].length();
                        //qDebug()<<"flagError="<<flagError;
                        //qDebug()<<"linesSize="<<linesSize;
                        //qDebug()<<"countControl="<<countControl;
                        //qDebug()<<"lengthNormal="<<lengthNormal;
                        //qDebug()<<"i="<<i;

                        //int strNowLength;
                        int z = linesSizeEnd;
                        //strNowLength = linesFile[z].length();
                        //qDebug()<<"strNowLength="<<strNowLength;
                        //qDebug()<<"i="<<i;
                        //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                        //lengthNormal = countLeftUp+9;

                        columnError = linesSize - linesSizeEnd;
                        //qDebug()<<"columnError="<<columnError;

                        if (columnError<10)
                        {
                            linesSizeEnd = linesSize-1;
                        }
                        else
                        {

                            //int k=0;
                            while (z<linesSizeEnd+10)
                            {
                                if(linesFile[z].length()-1<i)
                                {
                                    flagError = 1;
                                    flagError3 = 1;

                                    //messageError1=1;

                                    //linesSizeEnd = linesSize-1;
                                    z = linesSizeEnd+10;
                                }
                                z++;
                            }

                            //qDebug()<<"k="<<k;
                            //qDebug()<<"flagError="<<flagError;
                            //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                            //qDebug()<<"countLeftUp="<<countLeftUp;

                            //int u=0;
                            //int w=0;

                            if (flagError == 0)
                            {
                                for (int n = linesSizeEnd; n < linesSizeEnd+10; n++)
                                {
                                    for (int m = countLeftUp; m < countLeftUp+10; m++)
                                    {
                                        if ((linesFile[n][m]!='0')&&(linesFile[n][m]!='*'))
                                        {
                                            //shipsZone[u][w]=linesFile[n][m];
                                            //w++;
                                            flagError3 = 1;
                                            //messageError1=1;
                                        }
                                    }
                                    //w=0;
                                    //u++;
                                }
                                //linesSizeEnd = linesSize-1;
                            }

                            //k = linesSizeEnd;
                            //int strSize = linesFile[k].length()-1;
                            //qDebug()<<"strSize="<<strSize;

                            //for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
                            //if (linesFile[k][i+1]!=' ')
                            //int a=0;

                            //qDebug()<<"countLeftUp="<<countLeftUp;
                            if (flagError == 0)
                            {
                                for (int a = linesSizeEnd; a < linesSizeEnd+10; a++)
                                {
                                    //for (int b = countLeftUp; b < countLeftUp+10; b++)
                                    //{
                                    int strSize = linesFile[a].length()-1;
                                    //qDebug()<<"strSize="<<strSize;

                                    if (strSize-countLeftUp!=9)
                                    {
                                        if (linesFile[a][countLeftUp+10]!=' ')
                                        {

                                            //qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }

                                    if (countLeftUp!=0)
                                    {
                                        if (linesFile[a][countLeftUp-1]!=' ')
                                        {

                                            //qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }
                                }

                                //qDebug()<<"countLeftUp="<<countLeftUp;
                                //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                                //qDebug()<<"linesSize-1="<<linesSize-1;

                                int ColumnSize = linesSize-1-linesSizeEnd;
                                //int cSize = linesSizeEnd;
                                //qDebug()<<"ColumnSize="<<ColumnSize;

                                //int strLengthCheck = linesFile[linesSizeEnd+10].length()-1;
                                //qDebug()<<"strLengthCheck="<<strLengthCheck;

                                if ((ColumnSize>9))
                                {
                                    int a = countLeftUp;
                                    while (a < countLeftUp+10)

                                        //qDebug()<<"Test";
                                        //for (int a = countLeftUp; a < countLeftUp+10; a++)
                                    {
                                        //int intlinesFile10 = linesFile[linesSizeEnd+10].length();
                                        //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                                        //if (strSize-countLeftUp!=9)
                                        //{

                                        int strLengthCheck = linesFile[linesSizeEnd+10].length()-1;
                                        //qDebug()<<"strLengthCheck="<<strLengthCheck;

                                        //if (strLengthCheck>=countLeftUp+9)
                                        if (a<=strLengthCheck)
                                        {

                                            if (linesFile[linesSizeEnd+10][a]!=' ')
                                            {

                                                //qDebug()<<"NOTOKEY";
                                                flagError = 1;
                                                flagError3 = 1;
                                                messageError2 = 1;
                                            }
                                        }

                                        a++;
                                    }
                                }

                                if (ColumnSize<linesSize-1)
                                {
                                    int b = countLeftUp;
                                    while (b < countLeftUp+10)
                                    {
                                        int strLengthCheckUp = linesFile[linesSizeEnd-1].length()-1;

                                        if (b<=strLengthCheckUp)
                                        {
                                            if (linesFile[linesSizeEnd-1][b]!=' ')
                                            {

                                                //qDebug()<<"NOTOKEY2";
                                                flagError = 1;
                                                flagError3 = 1;
                                                messageError2=1;
                                            }
                                        }

                                        b++;
                                    }
                                }
                            }

                            //qDebug()<<"flagError3="<<flagError3;

                            int line = 0;
                            if (flagError3 == 0)
                            {
                                messageError1=0;
                                messageError2=0;

                                //qDebug()<<"OK";
                                //qDebug()<<"countLeftUp="<<countLeftUp;

                                //for (int j = countLeftUp; j < countLeftUp+10; j++)
                                //{
                                int j = countLeftUp;
                                while (j < countLeftUp+10)
                                {

                                    //for (int line = linesSizeEnd; line < linesSizeEnd+10; line++)
                                    //{
                                    line = linesSizeEnd;
                                    while (line < linesSizeEnd+10)
                                    {
                                        //if ((linesFile[line][j]=='0')||(linesFile[line][j]=='*'))
                                        //{
                                        //qDebug()<<"1111111111111111111";

                                        shipsZone[x][y]=linesFile[line][j];

                                        line++;
                                        x++;
                                    }
                                    //}
                                    x=0;
                                    y++;
                                    j++;
                                }
                                //}

                                //if (i==strNowLength)

                                //qDebug()<<"flagError2="<<flagError2;

                                //                            if (flagError2==0)
                                //                            {
                                linesSizeEnd = linesSize-1;
                                //                            }

                            }
                            else
                            {
                                flagError=0;
                                messageError1=1;
                                //flagError2=0;
                                flagError3=0;
                            }

                            //                        }

                        }
                    }
                }
                else
                {
                    countLine=0;
                    countLeftUp=0;
                }
            }
            countLeftUp=0;
            countLine=0;

            flagError=0;
            //flagError2=0;
            flagError3=0;
            countControl=0;
            linesSizeEnd++;
        }
        //qDebug()<<"countLine="<<countLine;


        //emit
    }

//    int globalError=0;
//    if (messageError2==1)
//    {
//        //Ошибка! Обнаружены символы, соприкасающиеся с полем. Уберите их для корректной работы программы. Поле должно быть размером 10х10;
//        //cout << "Error! Characters in contact with the Ships placement are detected. Remove them for the correct operation of the program. Ships placement must be 10x10" << endl;
//        globalError=1;
//    }
//    else
//        if (messageError1==1)
//        {
//            //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;

//            //cout << "Error! No valid Ships placement with a size 10x10 with symbols '*' and '0' was found! Please specify an isolated 10x10 Ships placement" << endl;
//            globalError=1;

//        }

    emit signal_checkAndWriteStringListBack(shipsZone,messageError1,messageError2);
}
