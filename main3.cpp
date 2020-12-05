#include <string>
#include <iostream>
#include <dirent.h>
#include "TXLib.h"
using namespace std;

int main()
{
    txCreateWindow (1532 , 840);

    HDC picLeftRight = txLoadImage("Дороги/dorogaLeftRight.bmp");
    HDC picLeftUp = txLoadImage("Дороги/dorogaLeftUp.bmp");
    HDC picLeftDown = txLoadImage("Дороги/dorogaLeftDown.bmp");
    HDC picRightDown = txLoadImage("Дороги/dorogaRightDown.bmp");
    HDC picRightUp = txLoadImage("Дороги/dorogaRightUp.bmp");
    HDC picUpDown = txLoadImage("Дороги/dorogaUpDown.bmp");
    HDC pic4 = txLoadImage("Дороги/doroga4.bmp");
    HDC pic3Up = txLoadImage("Дороги/doroga3Up.bmp");
    HDC pic3Down = txLoadImage("Дороги/doroga3Down.bmp");
    HDC pic3Right = txLoadImage("Дороги/doroga3Right.bmp");
    HDC pic3Left = txLoadImage("Дороги/doroga3Left.bmp");
    HDC picTupikUp = txLoadImage("Дороги/dorogaTupikUp.bmp");
    HDC picTupikDown = txLoadImage("Дороги/dorogaTupikDown.bmp");
    HDC picTupikRight = txLoadImage("Дороги/dorogaTupikRight.bmp");
    HDC picTupikLeft = txLoadImage("Дороги/dorogaTupikLeft.bmp");

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


