

#include "TXLib.h"

int main()
    {
    txCreateWindow (1532 , 840);
    txSetFillColour(TX_GRAY);
    txSetColour(TX_BLACK);
    txRectangle(0,0,1532,150);
    txRectangle(1300,150,1532,840);
    txSetFillColour(TX_WHITE);
    txRectangle(0,150,1300,840);

    txRectangle( 10,10,200,140);
    txRectangle(210,10,400,140);
    txRectangle(410,10,600,140);
    txRectangle(610,10,800,140);
    txRectangle(810,10,1000,140);
    txRectangle(1010,10,1200,140);

    txTextOut(100, 10,"тут надо вставить название категорий");




    txTextCursor (false);
    return 0;
    }

