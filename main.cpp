

#include "TXLib.h"

int main()
    {
    txCreateWindow (1532 , 840);

    HDC  object0 = txLoadImage ("dom1.bmp");
    HDC  object1 = txLoadImage ("dom2.bmp");
    HDC  object2 = txLoadImage ("dom3.bmp");
    HDC  object3 = txLoadImage ("dom4.bmp");
    HDC  object4 = txLoadImage ("dom5.bmp");
    HDC  object5 = txLoadImage ("dom6.bmp");
    HDC  object6 = txLoadImage ("mnogoetajka1.bmp");
    HDC  object7 = txLoadImage ("park1.bmp");
    HDC  object8 = txLoadImage ("park2.bmp");
    HDC  object9 = txLoadImage ("park3.bmp");

    txTextCursor (false);


    while(true)
    {

        txSetFillColour(TX_GRAY);
        txSetColour(TX_BLACK);
        txRectangle(0,0,1532,150);
        txRectangle(1300,150,1532,840);
        txSetFillColour(TX_WHITE);
        txRectangle(0,150,1300,840);

        txSetFillColour(TX_CYAN);
        txRectangle( 10,10,200,140);
        txSetFillColour(TX_BLUE);
        txRectangle(210,10,400,140);
        txSetFillColour(TX_GREEN);
        txRectangle(410,10,600,140);
        txSetFillColour(TX_RED);
        txRectangle(610,10,800,140);
        txSetFillColour(TX_MAGENTA);
        txRectangle(810,10,1000,140);
        txSetFillColour(TX_ORANGE);
        txRectangle(1010,10,1200,140);

        txSetColour(TX_ORANGE);
        txSelectFont("ARIAL", 40);
        txTextOut(70, 60,"Дома");
        txSetColour(TX_MAGENTA);
        txTextOut(250, 60,"Парки");
        txSetColour(TX_RED);
        txTextOut(450, 60,"Здании");
        txSetColour(TX_GREEN);
        txTextOut(650, 60,"Природа");
        txSetColour(TX_BLUE);
        txTextOut(850, 60,"Дороги");
        txSetColour(TX_CYAN);
        txTextOut(1020, 60,"Многоэтажки");


  while (txMouseButtons() != 3)
              {
              if (txMouseButtons() & 1)
              (
               (txMouseButtons()

               )

              if (txMouseButtons() & 2)
              txSleep (0);






















        txSleep(20);
    }

    return 0;
    }

