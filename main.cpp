

#include "TXLib.h"

int main()
{
    txCreateWindow (1532 , 840);

    txTextCursor (false);
    bool drawHouse = false;
    bool drawPark = false;
    bool drawObject = false;
    bool drawObject1 = false;
    bool drawObject2 = false;
    bool drawObject3 = false;
    bool drawObject4 = false;
    bool drawObject5 = false;
    bool drawObject6 = false;

        HDC  object0 = txLoadImage ("����/dom1.bmp");
        HDC  object1 = txLoadImage ("����/dom2.bmp");
        HDC  object2 = txLoadImage ("����/dom3.bmp");
        HDC  object3 = txLoadImage ("����/dom4.bmp");
        HDC  object4 = txLoadImage ("����/dom5.bmp");
        HDC  object5 = txLoadImage ("����/dom6.bmp");
        HDC  object6 = txLoadImage ("����/mnogoetajka1.bmp");
        HDC  object7 = txLoadImage ("�����/park1.bmp");
        HDC  object8 = txLoadImage ("�����/park2.bmp");
        HDC  object9 = txLoadImage ("�����/park3.bmp");

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
        txTextOut(70, 60,"����");
        txSetColour(TX_MAGENTA);
        txTextOut(250, 60,"�����");
        txSetColour(TX_RED);
        txTextOut(450, 60,"������");
        txSetColour(TX_GREEN);
        txTextOut(650, 60,"�������");
        txSetColour(TX_BLUE);
        txTextOut(850, 60,"������");
        txSetColour(TX_CYAN);
        txTextOut(1020, 60,"�����������");





        if (txMouseButtons() == 1 &&
            txMouseX() >= 10 &&  txMouseX() <= 200 &&
            txMouseY() >= 10 && txMouseY() <= 140 )
        {
            drawHouse = true;
            drawPark = false;
        }

        else if(txMouseButtons() == 1 &&
            txMouseX() >= 210 &&  txMouseX() <= 400 &&
            txMouseY() >= 10 && txMouseY() <= 140)
        {
            drawPark = true;
            drawHouse = false;
        }


        if (drawHouse)
        {
            Win32::TransparentBlt (txDC(),1325,250,200,100,object0,0,0,615,369, TX_WHITE);
            Win32::TransparentBlt (txDC(),1325,400,200,100,object1,0,0,564,300, TX_WHITE);
            Win32::TransparentBlt (txDC(),1325,550,200,100,object2,0,0,571,393, TX_WHITE);
        }
        else if(drawPark)
        {
            Win32::TransparentBlt (txDC(),1325,250,200,100,object7,0,0,900,195, TX_WHITE);
            Win32::TransparentBlt (txDC(),1325,400,200,100,object8,0,0,512,355, TX_WHITE);
            Win32::TransparentBlt (txDC(),1325,550,200,100,object9,0,0,650,400, TX_WHITE);
        }

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && drawHouse )
        {
            drawObject1 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && drawHouse )
        {
            drawObject2 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && drawHouse)
        {
            drawObject3 = true;
        }

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && drawPark )
        {
            drawObject4 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && drawPark )
        {
            drawObject5 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && drawPark )
        {
            drawObject6 = true;
        }



        if (drawObject1)
            Win32::TransparentBlt (txDC(),325,250,200,100,object0,0,0,615,369, TX_WHITE);
        if (drawObject2)
            Win32::TransparentBlt (txDC(),325,400,200,100,object1,0,0,564,300, TX_WHITE);
        if (drawObject3)
            Win32::TransparentBlt (txDC(),325,550,200,100,object2,0,0,571,393, TX_WHITE);

        if (drawObject4)
            Win32::TransparentBlt (txDC(),325,250,200,100,object7,0,0,900,195, TX_WHITE);
        if (drawObject5)
            Win32::TransparentBlt (txDC(),325,400,200,100,object8,0,0,512,355, TX_WHITE);
        if (drawObject6)
            Win32::TransparentBlt (txDC(),325,550,200,100,object9,0,0,650,400, TX_WHITE);















        txSleep(20);
        txEnd();
    }



    return 0;
    }

