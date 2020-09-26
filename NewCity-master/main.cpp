#include "TXLib.h"

int n_active = -1;


struct Picture
{
    int x;
    int y;
    int width;
    int height;
    HDC object;
    bool visibility;
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
    bool drawNature = false;
    bool drawObject = false;
    bool drawObject1 = false;
    bool drawObject2 = false;
    bool drawObject3 = false;
    bool drawObject4 = false;
    bool drawObject5 = false;
    bool drawObject6 = false;
    bool drawObject7 = false;
    bool drawObject8 = false;
    bool drawObject9 = false;
    bool drawObject10 = false;
    bool drawObject11 = false;
    bool drawObject12 = false;

    Picture pic[100];
    pic[0] = {1300, 250, 615, 369, txLoadImage ("Дома/dom1.bmp")};
    pic[1] = {1300, 400, 564, 300, txLoadImage ("Дома/dom2.bmp")};
    pic[2] = {1300, 550, 571, 393, txLoadImage ("Дома/dom3.bmp")};
    pic[3] = {1300, 250, 350, 324, txLoadImage ("Дома/dom4.bmp")};
    pic[4] = {1300, 400, 407, 264, txLoadImage ("Дома/dom5.bmp")};
    pic[5] = {1300, 550, 495, 293, txLoadImage ("Дома/dom6.bmp")};
    pic[6] = {1300, 550, 520, 342, txLoadImage ("Дома/mnogoetajka1.bmp")};
    pic[7] = {1300, 250, 900, 195, txLoadImage ("Парки/park1.bmp")};
    pic[8] = {1300, 400, 512, 355, txLoadImage ("Парки/park2.bmp")};
    pic[9] = {1300, 550, 650, 400, txLoadImage ("Парки/park3.bmp")};
    pic[10] = {1300, 250, 512, 429, txLoadImage ("Деревья/tree1.bmp")};
    pic[11] = {1300, 400, 414, 484, txLoadImage ("Деревья/tree2.bmp")};
    pic[12] = {1300, 550, 214, 236, txLoadImage ("Деревья/tree3.bmp")};
    pic[13] = {1300, 250, 408, 581, txLoadImage ("Деревья/tree4.bmp")};
    pic[14] = {1300, 400, 423, 512, txLoadImage ("Деревья/tree5.bmp")};
    pic[15] = {1300, 550, 550, 412, txLoadImage ("Деревья/tree6.bmp")};

    Picture center[100];
    center[0] = {325, 250, 615, 369, txLoadImage ("Дома/dom1.bmp"), false};
    center[1] = {325, 400, 564, 300, txLoadImage ("Дома/dom2.bmp")};
    center[2] = {325, 550, 571, 393, txLoadImage ("Дома/dom3.bmp")};
    center[3] = {325, 250, 900, 195, txLoadImage ("Парки/park1.bmp")};
    center[4] = {325, 400, 512, 355, txLoadImage ("Парки/park2.bmp")};
    center[5] = {325, 550, 650, 400, txLoadImage ("Парки/park3.bmp")};



    bool gameOver = false;
    while (!gameOver)
    {
        txBegin();
        txSetFillColour(TX_GRAY);
        txSetColour(TX_BLACK);
        txRectangle(0,0,1532,150);
        txRectangle(1300,150,1532,840);
        txSetFillColour(TX_WHITE);
        txRectangle(0,150,1300,840);

        drawButton(10,10, "Дома",TX_CYAN,TX_YELLOW);
        drawButton(210,10, "Парки",TX_GREEN,TX_ORANGE);
        drawButton(410,10, "Здании",TX_BLUE,TX_MAGENTA);
        drawButton(610,10, "Природа",TX_MAGENTA,TX_BLUE);
        drawButton(810,10, "Дороги",TX_ORANGE,TX_GREEN);
        drawButton(1010,10, "Многоэтажки",TX_YELLOW,TX_CYAN);

        if (txMouseButtons() == 1 &&
            txMouseX() >= 10 &&  txMouseX() <= 200 &&
            txMouseY() >= 10 && txMouseY() <= 140 )
        {
            drawHouse = true;
            drawPark = false;
            drawNature = false;
        }
        else if(txMouseButtons() == 1 &&
            txMouseX() >= 210 &&  txMouseX() <= 400 &&
            txMouseY() >= 10 && txMouseY() <= 140)
        {
            drawPark = true;
            drawHouse = false;
            drawNature = false;
        }
        else if(txMouseButtons() == 1 &&
            txMouseX() >= 610 &&  txMouseX() <= 800 &&
            txMouseY() >= 10 && txMouseY() <= 140)
        {
            drawNature = true;
            drawPark = false;
            drawHouse = false;
        }


        if (drawHouse)
            for (int i = 0; i <= 2; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
        else if(drawPark)
            for (int i = 7; i <= 9; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
        else if(drawNature)
            for (int i = 10; i <= 16; i++)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);

        if (txMouseButtons() == 1 &&
            txMouseX() >= pic[0].x &&  txMouseX() <= 1525 &&
            txMouseY() >= pic[0].y && txMouseY() <= 350 && drawHouse )
        {
            center[0].visibility = true;
            drawObject1 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= pic[1].x &&  txMouseX() <= 1525 &&
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

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && drawNature )
        {
            drawObject7 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && drawNature )
        {
            drawObject8 = true;
            n_active = 8;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && drawNature )
        {
            drawObject9 = true;
        }
        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && drawNature )
        {
            drawObject10 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && drawNature )
        {
            drawObject11 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && drawNature )
        {
            drawObject12 = true;
        }

        if (n_active > 0)
            if (GetAsyncKeyState(VK_LEFT))
                pic[n_active].x = pic[n_active].x - 3;


        for (int i = 0; i <= 3; i++)
            if (center[i].visibility)
                Win32::TransparentBlt (txDC(),center[i].x,center[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);


        if (drawObject1)
            Win32::TransparentBlt (txDC(),325,250,200,100,pic[0].object,0,0,615,369, TX_WHITE);
        if (drawObject2)
            Win32::TransparentBlt (txDC(),325,400,200,100,pic[1].object,0,0,564,300, TX_WHITE);
        if (drawObject3)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[2].object,0,0,571,393, TX_WHITE);

        if (drawObject4)
            Win32::TransparentBlt (txDC(),325,250,200,100,pic[7].object,0,0,900,195, TX_WHITE);
        if (drawObject5)
            Win32::TransparentBlt (txDC(),325,400,200,100,pic[8].object,0,0,512,355, TX_WHITE);
        if (drawObject6)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[9].object,0,0,650,400, TX_WHITE);

        if (drawObject7)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[10].object,0,0,650,400, TX_WHITE);
        if (drawObject8)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[11].object,0,0,650,400, TX_WHITE);
        if (drawObject9)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[12].object,0,0,650,400, TX_WHITE);
        if (drawObject10)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[13].object,0,0,650,400, TX_WHITE);
        if (drawObject11)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[14].object,0,0,650,400, TX_WHITE);
        if (drawObject12)
            Win32::TransparentBlt (txDC(),325,550,200,100,pic[15].object,0,0,650,400, TX_WHITE);

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameOver = true;
        }


        txSleep(20);
        txEnd();
    }


    for (int i = 0; i <= 15; i++)
        txDeleteDC(pic[i].object);

    return 0;
}
