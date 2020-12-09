#include <string>
#include <iostream>
#include <dirent.h>
#include "TXLib.h"
using namespace std;

int main()
{
    txCreateWindow (1532 , 840);

    HDC picLeftRight = txLoadImage("������/dorogaLeftRight.bmp");
    HDC picLeftUp = txLoadImage("������/dorogaLeftUp.bmp");
    HDC picLeftDown = txLoadImage("������/dorogaLeftDown.bmp");
    HDC picRightDown = txLoadImage("������/dorogaRightDown.bmp");
    HDC picRightUp = txLoadImage("������/dorogaRightUp.bmp");
    HDC picUpDown = txLoadImage("������/dorogaUpDown.bmp");
    HDC pic4 = txLoadImage("������/doroga4.bmp");
    HDC pic3Up = txLoadImage("������/doroga3Up.bmp");
    HDC pic3Down = txLoadImage("������/doroga3Down.bmp");
    HDC pic3Right = txLoadImage("������/doroga3Right.bmp");
    HDC pic3Left = txLoadImage("������/doroga3Left.bmp");
    HDC picTupikUp = txLoadImage("������/dorogaTupikUp.bmp");
    HDC picTupikDown = txLoadImage("������/dorogaTupikDown.bmp");
    HDC picTupikRight = txLoadImage("������/dorogaTupikRight.bmp");
    HDC picTupikLeft = txLoadImage("������/dorogaTupikLeft.bmp");

    bool dorogi[30][30];

    for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++)
    dorogi[i][j] = false;

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();

        int x = round(txMouseX() / 100);
        int y = round(txMouseY() / 100);

        if (txMouseButtons() == 1)
            dorogi [x][y] = true;

        for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
        if(dorogi[i][j])
        {
            if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic4);

            else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic3Up);
            else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic3Down);
            else if(dorogi[i+1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic3Right);
            else if(dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic3Left);

            else if(dorogi[i-1][j] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picLeftUp);
            else if(dorogi[i-1][j] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picLeftDown);
            else if(dorogi[i+1][j] && dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picRightDown);
            else if(dorogi[i+1][j] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picRightUp);

            else if (dorogi[i][j+1] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picUpDown);
            else if (dorogi[i+1][j] && dorogi[i-1][j])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picLeftRight);

            else if (dorogi[i-1][j])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picTupikRight);
            else if (dorogi[i+1][j])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picTupikLeft);
            else if (dorogi[i][j+1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picTupikUp);
            else if (dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, picTupikDown);


        }
        txSleep(10);
        txEnd();
    }

}


