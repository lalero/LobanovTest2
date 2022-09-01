#include "checkandwritestringlist.h"

CheckAndWriteStringList::CheckAndWriteStringList(QObject *parent)
    : QObject{parent}
{

}

void CheckAndWriteStringList::slot_checkAndWriteStringList(QStringList stringlist)
{
    linesFile.clear();
    linesFile = stringlist;

    shipsZone.clear();
    int o = 0;
    while (o<10)
    {
        QString x="##########";
        shipsZone.append(x);
        o++;
    }

    int linesSize = linesFile.size();
    int linesSizeEnd = 0;
    int countLine = 0;
    int countLeftUp = 0;
    int columnError = 0;
    int flagError = 0;
    int messageError1 = 1;
    int messageError2 = 0;
    int flagError3 = 0;
    int countControl = 0;

    if (linesSize < 10)
    {
        messageError1=1;
    }
    else
    {
        while (linesSize-1 > linesSizeEnd)
        {
            for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
            {
                if ((linesFile[linesSizeEnd][i]=='0')||(linesFile[linesSizeEnd][i]=='*'))
                {
                    countLine++;

                    if (countLine == 1)
                    {
                        countLeftUp = i;
                    }

                    countControl=linesSize-linesSizeEnd;

                    if ((countLine == 10)&&(countControl>=9))
                    {
                        int x=0;
                        int y=0;
                        int z = linesSizeEnd;
                        columnError = linesSize - linesSizeEnd;

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

                                    z = linesSizeEnd+10;
                                }
                                z++;
                            }

                            if (flagError == 0)
                            {
                                for (int n = linesSizeEnd; n < linesSizeEnd+10; n++)
                                {
                                    for (int m = countLeftUp; m < countLeftUp+10; m++)
                                    {
                                        if ((linesFile[n][m]!='0')&&(linesFile[n][m]!='*'))
                                        {
                                            flagError3 = 1;
                                        }
                                    }
                                }
                            }

                            if (flagError == 0)
                            {
                                for (int a = linesSizeEnd; a < linesSizeEnd+10; a++)
                                {
                                    int strSize = linesFile[a].length()-1;

                                    if (strSize-countLeftUp!=9)
                                    {
                                        if (linesFile[a][countLeftUp+10]!=' ')
                                        {
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }

                                    if (countLeftUp!=0)
                                    {
                                        if (linesFile[a][countLeftUp-1]!=' ')
                                        {
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }
                                }

                                int ColumnSize = linesSize-1-linesSizeEnd;

                                if ((ColumnSize>9))
                                {
                                    int a = countLeftUp;
                                    while (a < countLeftUp+10)

                                    {

                                        int strLengthCheck = linesFile[linesSizeEnd+10].length()-1;

                                        if (a<=strLengthCheck)
                                        {

                                            if (linesFile[linesSizeEnd+10][a]!=' ')
                                            {
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
                                                flagError = 1;
                                                flagError3 = 1;
                                                messageError2=1;
                                            }
                                        }

                                        b++;
                                    }
                                }
                            }

                            int line = 0;
                            if (flagError3 == 0)
                            {
                                messageError1=0;
                                messageError2=0;

                                int j = countLeftUp;
                                while (j < countLeftUp+10)
                                {
                                    line = linesSizeEnd;
                                    while (line < linesSizeEnd+10)
                                    {
                                        shipsZone[x][y]=linesFile[line][j];

                                        line++;
                                        x++;
                                    }
                                    x=0;
                                    y++;
                                    j++;
                                }
                                linesSizeEnd = linesSize-1;

                            }
                            else
                            {
                                flagError=0;
                                messageError1=1;
                                flagError3=0;
                            }
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
            flagError3=0;
            countControl=0;
            linesSizeEnd++;
        }
    }

    emit signal_checkAndWriteStringListBack(shipsZone,messageError1,messageError2);
}
