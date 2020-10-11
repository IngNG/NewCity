#include "TXLib.h"
#include "struct Picture.cpp"
#include "Button.cpp"

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);



    string category = "Home";

    int n_active = -30;

    bool Mnogoetajka1 = false;
    bool LKM = false;

    const int N_PICS = 21;
    Picture pic[N_PICS];
    pic[0] = {1300, 200, 615, 369, txLoadImage ("Дома/dom1.bmp"), "Home"};
    pic[1] = {1300, 300, 564, 300, txLoadImage ("Дома/dom2.bmp"), "Home"};
    pic[2] = {1300, 400, 571, 393, txLoadImage ("Дома/dom3.bmp"), "Home"};
    pic[3] = {1300, 500, 350, 324, txLoadImage ("Дома/dom4.bmp"), "Home"};
    pic[4] = {1300, 600, 407, 264, txLoadImage ("Дома/dom5.bmp"), "Home"};
    pic[5] = {1300, 700, 495, 293, txLoadImage ("Дома/dom6.bmp"), "Home"};
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
    pic[16] = {1300, 200, 300, 196, txLoadImage ("Zdania/Zdania1.bmp"), "Zdania"};
    pic[17] = {1300, 300, 256, 256, txLoadImage ("Zdania/Zdania2.bmp"), "Zdania"};
    pic[18] = {1300, 400, 360, 360, txLoadImage ("Zdania/Zdania3.bmp"), "Zdania"};
    pic[19] = {1300, 500, 260, 260, txLoadImage ("Zdania/Zdania4.bmp"), "Zdania"};
    pic[20] = {1300, 600, 360, 360, txLoadImage ("Zdania/Zdania5.bmp"), "Zdania"};

    int n_pics = 0;
    Picture center[2000];

    const int N_Button = 6;
    Button buttons[N_Button];
    buttons[0] = {10, 10, "Дома",TX_CYAN,TX_YELLOW, "Home"};
    buttons[1] = {210, 10, "Парки",TX_GREEN,TX_ORANGE, "Park"};
    buttons[2] = {410, 10, "Здании",TX_BLUE,TX_MAGENTA, "Zdania"};
    buttons[3] = {610, 10, "Природа",TX_MAGENTA,TX_BLUE, "Tree"};
    buttons[4] = {810, 10, "Дороги",TX_ORANGE,TX_GREEN};
    buttons[5] = {1010, 10, "Многоэтажки",TX_YELLOW,TX_CYAN};




    const int MAX_X = 1300;
    const int MAX_Y = 840;

    bool gameOver = false;
    while (!gameOver)
    {
        txBegin();
        txSetFillColour(TX_GRAY);
        txSetColour(TX_BLACK);
        txRectangle(0,0,1532,150);
        txRectangle(MAX_X,150,1532,MAX_Y);
        txSetFillColour(TX_WHITE);
        txRectangle(0,150,MAX_X,MAX_Y);

        for (int i = 0; i < N_PICS; i++)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() >= center[n_active].x && txMouseX() <= center[n_active].x + 200 &&
                txMouseY() >= center[n_active].y && txMouseY() <= center[n_active].y + 100 && n_active < 0)
            {
                n_active = i;
            }
        }

        if(n_active >=0)
        {
            center[n_active].x = txMouseX() - 60;
            center[n_active].y = txMouseY() - 50;
        }

        if(txMouseButtons() !=1)
            n_active = -100;

        for (int i = 0; i < N_Button; i++)
            drawButton(buttons[i].x, buttons[i].y, buttons[i].text, buttons[i].colorButton, buttons[i].colorText);

        for (int i = 0; i < N_Button; i++)
            if (Click(buttons[i].x, buttons[i].y))
                category = buttons[i].category;

        for (int i = 0; i < N_PICS; i++)
            if(category == pic[i].category)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);

        //Рисование центральных картинок
        for (int i = 0; i < n_pics; i++)
        {
            if (center[i].visible)
            Win32::TransparentBlt (txDC(),center[i].x,center[i].y,center[i].widthPic,center[i].heightPic,center[i].object,0,0,center[i].width,center[i].height, TX_WHITE);
        }



        for (int i = 0; i < N_PICS; i++)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() >= pic[i].x && txMouseX() <= pic[i].x + 200 &&
                txMouseY() >= pic[i].y && txMouseY() <= pic[i].y + 100 && category == pic[i].category )
            {
                center[n_pics] = {random(0,MAX_X - 200), random(150,840 - 100),  pic[i].width,  pic[i].height, pic[i].object, pic[i].category, true, 200, 100};
                n_pics++;
                txSleep(200);
            }
        }


        if(GetAsyncKeyState(VK_DELETE))
        {
            n_pics = n_pics - 1;
        }



        if(GetAsyncKeyState(VK_OEM_PLUS))
        {
            center[n_active].widthPic = center[n_active].widthPic * 1.05;
            center[n_active].heightPic = center[n_active].heightPic * 1.05;
        }
        if(GetAsyncKeyState(VK_OEM_MINUS))
        {
            center[n_active].widthPic = center[n_active].widthPic / 1.05;
            center[n_active].heightPic = center[n_active].heightPic / 1.05;
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


        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameOver = true;
        }


        txSleep(20);
        txEnd();
    }


    for (int i = 0; i < N_PICS; i++)
        txDeleteDC(pic[i].object);

    for (int i = 0; i < n_pics; i++)
        txDeleteDC(center[i].object);

    return 0;
}
