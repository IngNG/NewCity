

#include "TXLib.h"

int main()
{
    txCreateWindow (1532 , 840);

    txTextCursor (false);
    bool drawHouse = true;

        HDC  object0 = txLoadImage ("Дома/dom1.bmp");
        HDC  object1 = txLoadImage ("Дома/dom2.bmp");
        HDC  object2 = txLoadImage ("Дома/dom3.bmp");
        HDC  object3 = txLoadImage ("Дома/dom4.bmp");
        HDC  object4 = txLoadImage ("Дома/dom5.bmp");
        HDC  object5 = txLoadImage ("Дома/dom6.bmp");
        HDC  object6 = txLoadImage ("Дома/mnogoetajka1.bmp");
        HDC  object7 = txLoadImage ("Парки/park1.bmp");
        HDC  object8 = txLoadImage ("Парки/park2.bmp");
        HDC  object9 = txLoadImage ("Парки/park3.bmp");

    while(true)
    {
        txBegin();
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

        /*

  while (txMouseButtons() != 3)
              {
              if (txMouseButtons() & 1)
              (
               (txMouseButtons()

               )

              if (txMouseButtons() & 2)
              txSleep (0);
        */

        if (1)
        {
            drawHouse = true;
        }

        else if(2)
        {
            //drawPark = true;
        }

        if (drawHouse)
        {
            Win32::TransparentBlt (txDC(),1300,250,200,100,object0,0,0,1536,1152, TX_WHITE);
            Win32::TransparentBlt (txDC(),1300,400,200,100,object1,0,0,564,300, TX_WHITE);
            Win32::TransparentBlt (txDC(),1300,550,200,100,object2,0,0,571,393, TX_WHITE);
        }
        else
        {
            Win32::TransparentBlt (txDC(),1300,250,200,100,object7,0,0,900,197, TX_WHITE);
            Win32::TransparentBlt (txDC(),1300,400,200,100,object8,0,0,512,355, TX_WHITE);
            Win32::TransparentBlt (txDC(),1300,550,200,100,object9,0,0,650,400, TX_WHITE);
        }















        txSleep(20);
        txEnd();
    }



    return 0;
    }

