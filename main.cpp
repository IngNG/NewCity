#include "TXLib.h"



struct Picture
{
    int x;
    int y;
    int width;
    int height;
    HDC object;
};

struct Button
{
    int x;
    int y;
    const char text[];
    COLORREF colorButton;
    COLORREF colorText;
};

void drawButton(int x,int y,const char text[],COLORREF color,COLORREF color1)
{
    txSetColour(TX_BLACK);
    txSetFillColour(color);
    txRectangle(x,y,x + 190,y + 130);
    txSetColour(color1);
    txSelectFont("ARIAL", 40);
    txDrawText(x,y,x + 190,y + 130,text);
}

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

        HDC  object0 = txLoadImage ("Äîìà/dom1.bmp");
        HDC  object1 = txLoadImage ("Äîìà/dom2.bmp");
        HDC  object2 = txLoadImage ("Äîìà/dom3.bmp");
        HDC  object3 = txLoadImage ("Äîìà/dom4.bmp");
        HDC  object4 = txLoadImage ("Äîìà/dom5.bmp");
        HDC  object5 = txLoadImage ("Äîìà/dom6.bmp");
        HDC  object6 = txLoadImage ("Äîìà/mnogoetajka1.bmp");
        HDC  object7 = txLoadImage ("Ïàðêè/park1.bmp");
        HDC  object8 = txLoadImage ("Ïàðêè/park2.bmp");
        HDC  object9 = txLoadImage ("Ïàðêè/park3.bmp");

        Picture pic[100];
        pic[0] = {1300, 250, 615, 369, object0};
        pic[1] = {1300, 400, 564, 300, object1};
        pic[2] = {1300, 550, 571, 393, object2};
        pic[3] = {1300, 250, 350, 324, object3};
        pic[4] = {1300, 400, 407, 264, object4};
        pic[5] = {1300, 550, 495, 293, object5};
        pic[6] = {1300, 550, 520, 342, object6};
        pic[7] = {1300, 250, 900, 197, object7};
        pic[8] = {1300, 400, 512, 355, object8};
        pic[9] = {1300, 550, 650, 400, object9};


    while(true)
    {
        txBegin();
        txSetFillColour(TX_GRAY);
        txSetColour(TX_BLACK);
        txRectangle(0,0,1532,150);
        txRectangle(1300,150,1532,840);
        txSetFillColour(TX_WHITE);
        txRectangle(0,150,1300,840);

        drawButton(10,10, "Äîìà",TX_CYAN,TX_YELLOW);
        drawButton(210,10, "Ïàðêè",TX_GREEN,TX_ORANGE);
        drawButton(410,10, "Çäàíèè",TX_BLUE,TX_MAGENTA);
        drawButton(610,10, "Ïðèðîäà",TX_MAGENTA,TX_BLUE);
        drawButton(810,10, "Äîðîãè",TX_ORANGE,TX_GREEN);
        drawButton(1010,10, "Ìíîãîýòàæêè",TX_YELLOW,TX_CYAN);

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
            for (int i = 0; i <= 2; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
        else if(drawPark)
            for (int i = 3; i <= 5; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);

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