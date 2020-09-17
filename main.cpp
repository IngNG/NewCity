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
    bool drawHouse = true;

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

        drawButton(10,10, "����",TX_CYAN,TX_YELLOW);
        drawButton(210,10, "�����",TX_GREEN,TX_ORANGE);
        drawButton(410,10, "������",TX_BLUE,TX_MAGENTA);
        drawButton(610,10, "�������",TX_MAGENTA,TX_BLUE);
        drawButton(810,10, "������",TX_ORANGE,TX_GREEN);
        drawButton(1010,10, "�����������",TX_YELLOW,TX_CYAN);

        if (1)
        {
            drawHouse = true;
        }

        else if(2)
        {
            //drawPark = true;
        }

        if (drawHouse)
            for (int i = 0; i <= 2; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);

        else
            for (int i = 3; i <= 5; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
















        txSleep(20);
        txEnd();
    }



    return 0;
    }

