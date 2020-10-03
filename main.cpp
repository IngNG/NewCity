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
    const char* text;
    COLORREF colorButton;
    COLORREF colorText;
    string category;
};

void drawButton(int x,int y,const char* text,COLORREF color,COLORREF color1)
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

    int n_active = 0;

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
    pic[0] = {1300, 250, 615, 369, txLoadImage ("Дома/dom1.bmp"), "Home"};
    pic[1] = {1300, 400, 564, 300, txLoadImage ("Дома/dom2.bmp"), "Home"};
    pic[2] = {1300, 550, 571, 393, txLoadImage ("Дома/dom3.bmp"), "Home"};
    pic[3] = {1300, 250, 350, 324, txLoadImage ("Дома/dom4.bmp"), "Home"};
    pic[4] = {1300, 400, 407, 264, txLoadImage ("Дома/dom5.bmp"), "Home"};
    pic[5] = {1300, 550, 495, 293, txLoadImage ("Дома/dom6.bmp"), "Home"};
    pic[6] = {1300, 550, 520, 342, txLoadImage ("Дома/mnogoetajka1.bmp"), "Mnogoetajka1"};
    pic[7] = {1300, 250, 900, 195, txLoadImage ("Парки/park1.bmp"), "Park"};
    pic[8] = {1300, 400, 512, 355, txLoadImage ("Парки/park2.bmp"), "Park"};
    pic[9] = {1300, 550, 650, 400, txLoadImage ("Парки/park3.bmp"), "Park"};
    pic[10] = {1300, 250, 512, 429, txLoadImage ("Деревья/tree1.bmp"), "Tree"};
    pic[11] = {1300, 400, 414, 484, txLoadImage ("Деревья/tree2.bmp"), "Tree"};
    pic[12] = {1300, 550, 214, 236, txLoadImage ("Деревья/tree3.bmp"), "Tree"};
    pic[13] = {1300, 250, 408, 581, txLoadImage ("Деревья/tree4.bmp"), "Tree"};
    pic[14] = {1300, 400, 423, 512, txLoadImage ("Деревья/tree5.bmp"), "Tree"};
    pic[15] = {1300, 550, 550, 412, txLoadImage ("Деревья/tree6.bmp"), "Tree"};

    const int N_PICS2 = 3;
    Picture center[N_PICS2];
    center[0] = {325, 250, 200, 100,pic[0].object, pic[0].category};
    center[1] = {300, 400, 200, 100,pic[1].object, pic[1].category};
    center[2] = {300, 550, 200, 100,pic[2].object, pic[2].category};
   /* center[3] = {300, 250, 200, 100,pic[3].object, 0,0,900,195, TX_WHITE);
    center[4] = {300, 400, 200, 100,pic[4].object, 0,0,512,355, TX_WHITE);
    center[5] = {300, 550, 200, 100,pic[5].object, 0,0,650,400, TX_WHITE);
    center[6] = {300, 550, 200, 100,pic[6].object, 0,0,650,400, TX_WHITE);
    center[7] = {300, 550, 200, 100,pic[7].object, 0,0,650,400, TX_WHITE);
    center[8] = {300, 550, 200, 100,pic[8].object, 0,0,650,400, TX_WHITE);
    center[9] = {300, 550, 200, 100,pic[9].object, 0,0,650,400, TX_WHITE);
    center[10] = {300, 550, 200, 100,pic[10].object, 0,0,650,400, TX_WHITE);
    center[11] = {300, 550, 200, 100,pic[11].object, 0,0,650,400, TX_WHITE);*/

    const int N_Button = 6;
    Button buttons[N_Button];
    buttons[0] = {10, 10, "Дома",TX_CYAN,TX_YELLOW, "Home"};
    buttons[1] = {210, 10, "Парки",TX_GREEN,TX_ORANGE, "Park"};
    buttons[2] = {410, 10, "Здании",TX_BLUE,TX_MAGENTA};
    buttons[3] = {610, 10, "Природа",TX_MAGENTA,TX_BLUE, "Tree"};
    buttons[4] = {810, 10, "Дороги",TX_ORANGE,TX_GREEN};
    buttons[5] = {1010, 10, "Многоэтажки",TX_YELLOW,TX_CYAN};






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


        for (int i = 0; i < N_Button; i++)
            drawButton(buttons[i].x, buttons[i].y, buttons[i].text, buttons[i].colorButton, buttons[i].colorText);



        for (int i = 0; i < N_Button; i++)
            if (Click(buttons[i].x, buttons[i].y))
                category = buttons[i].category;


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


        if(GetAsyncKeyState(VK_LEFT))
        {
            center[n_active].x = center[n_active].x  - 5;
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            center[n_active].x = center[n_active].x  + 5;
        }

        if(GetAsyncKeyState(VK_UP))
        {
            center[n_active].y = center[n_active].y  - 5 ;
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            center[n_active].y = center[n_active].y  + 5;
        }

        for (int i = 0; i < 3; i = i + 1)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() >= center[i].x &&  txMouseX() <= center[i].x + 200 &&
                txMouseY() >= center[i].y && txMouseY() <= center[i].y + 100 && category == "Home" )
            {
                n_active = i;
            }
        }

        if (drawObject1)
            Win32::TransparentBlt (txDC(),center[0].x,center[0].y,200,100,center[0].object,0,0,615,369, TX_WHITE);
        if (drawObject2)
            Win32::TransparentBlt (txDC(),center[1].x,center[1].y,200,100,center[1].object,0,0,564,300, TX_WHITE);
        if (drawObject3)
            Win32::TransparentBlt (txDC(),center[2].x,center[2].y,200,100,center[2].object,0,0,571,393, TX_WHITE);

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
