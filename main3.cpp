#include <string>
#include <iostream>
#include <dirent.h>
#include "TXLib.h"
using namespace std;

int main()
{
    txCreateWindow (1532 , 840);

    HDC pic1 = txLoadImage("Дороги/dorogaLeftRight.bmp");
    HDC pic2 = txLoadImage("Дороги/doroga2.bmp");
    HDC pic3 = txLoadImage("Дороги/dorogaUpDown.bmp");

    bool dorogi[10][10];

    for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
    dorogi[i][j] = false;

    while(true)
    {
        txSetFillColor(TX_WHITE);
        txClear();

        int x = round(txMouseX() / 100);
        int y = round(txMouseY() / 100);

        if (txMouseButtons() == 1)
            dorogi [x][y] = true;

        for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        if(dorogi[i][j])
        {
            if(dorogi[i-1][j] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic2);
            else if (dorogi[i][j+1] && dorogi[i][j-1])
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic3);
            else
                txBitBlt(txDC(), 100 * i,100 * j, 100, 100, pic1);
        }
        txSleep(10);
    }

}


