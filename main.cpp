#include "TXLib.h"

struct Picture
{
    int x;
    int y;
    int width;
    int height;
    HDC object;
    string category;
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
bool Click(int x,int y)
{
if (txMouseButtons() == 1 &&
    txMouseX() >= x &&  txMouseX() <= x + 190 &&
    txMouseY() >= y &&  txMouseY() <= y + 130)
    {
    return true;
    }
else
    return false;

}

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);


    string category = "Home";

    bool Mnogoetajka1 = false;
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

    const int N_PICS = 16;
    Picture pic[N_PICS];
    pic[0] = {1300, 250, 615, 369, txLoadImage ("����/dom1.bmp"), "Home"};
    pic[1] = {1300, 400, 564, 300, txLoadImage ("����/dom2.bmp"), "Home"};
    pic[2] = {1300, 550, 571, 393, txLoadImage ("����/dom3.bmp"), "Home"};
    pic[3] = {1300, 250, 350, 324, txLoadImage ("����/dom4.bmp"), "Home"};
    pic[4] = {1300, 400, 407, 264, txLoadImage ("����/dom5.bmp"), "Home"};
    pic[5] = {1300, 550, 495, 293, txLoadImage ("����/dom6.bmp"), "Home"};
    pic[6] = {1300, 550, 520, 342, txLoadImage ("����/mnogoetajka1.bmp"), "Mnogoetajka1"};
    pic[7] = {1300, 250, 900, 195, txLoadImage ("�����/park1.bmp"), "Park"};
    pic[8] = {1300, 400, 512, 355, txLoadImage ("�����/park2.bmp"), "Park"};
    pic[9] = {1300, 550, 650, 400, txLoadImage ("�����/park3.bmp"), "Park"};
    pic[10] = {1300, 250, 512, 429, txLoadImage ("�������/tree1.bmp"), "Tree"};
    pic[11] = {1300, 400, 414, 484, txLoadImage ("�������/tree2.bmp"), "Tree"};
    pic[12] = {1300, 550, 214, 236, txLoadImage ("�������/tree3.bmp"), "Tree"};
    pic[13] = {1300, 250, 408, 581, txLoadImage ("�������/tree4.bmp"), "Tree"};
    pic[14] = {1300, 400, 423, 512, txLoadImage ("�������/tree5.bmp"), "Tree"};
    pic[15] = {1300, 550, 550, 412, txLoadImage ("�������/tree6.bmp"), "Tree"};


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

        drawButton(10,10, "����",TX_CYAN,TX_YELLOW);
        drawButton(210,10, "�����",TX_GREEN,TX_ORANGE);
        drawButton(410,10, "������",TX_BLUE,TX_MAGENTA);
        drawButton(610,10, "�������",TX_MAGENTA,TX_BLUE);
        drawButton(810,10, "������",TX_ORANGE,TX_GREEN);
        drawButton(1010,10, "�����������",TX_YELLOW,TX_CYAN);

        if (Click(10, 10))
        {
            category = "Home";
        }
        else if(Click(210, 10))
        {
            category = "Park";
        }
        else if(Click(410,10))
        {
            category = "Tree";
        }


        for (int i = 0; i < N_PICS; i++)
            if(category == pic[i].category)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && category == "Home" )
        {
            drawObject1 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && category == "Home" )
        {
            drawObject2 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && category == "Home")
        {
            drawObject3 = true;
        }

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && category == "Park" )
        {
            drawObject4 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && category == "Park" )
        {
            drawObject5 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && category == "Park" )
        {
            drawObject6 = true;
        }

        if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && category == "Tree" )
        {
            drawObject7 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && category == "Tree" )
        {
            drawObject8 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && category == "Tree" )
        {
            drawObject9 = true;
        }
        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 250 && txMouseY() <= 350 && category == "Tree" )
        {
            drawObject10 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 400 && txMouseY() <= 500 && category == "Tree" )
        {
            drawObject11 = true;
        }

        else if (txMouseButtons() == 1 &&
            txMouseX() >= 1325 &&  txMouseX() <= 1525 &&
            txMouseY() >= 550 && txMouseY() <= 650 && category == "Tree" )
        {
            drawObject12 = true;
        }



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


    for (int i = 0; i < N_PICS; i++)
        txDeleteDC(pic[i].object);

    return 0;
}
