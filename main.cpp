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
    txCreateWindow (1432 , 740);
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

    const int N_PICS = 21;
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
    pic[16] = {1300, 200, 300, 196, txLoadImage ("Zdania/Zdania1.bmp"), "Zdania"};
    pic[17] = {1300, 300, 256, 256, txLoadImage ("Zdania/Zdania2.bmp"), "Zdania"};
    pic[18] = {1300, 400, 360, 360, txLoadImage ("Zdania/Zdania3.bmp"), "Zdania"};
    pic[19] = {1300, 500, 260, 260, txLoadImage ("Zdania/Zdania4.bmp"), "Zdania"};
    pic[20] = {1300, 600, 360, 360, txLoadImage ("Zdania/Zdania5.bmp"), "Zdania"};

    const int N_PICS2 = 13;
    Picture center[N_PICS2];
    center[0] = {325, 250, 200, 100,pic[0].object, pic[0].category};
   /* center[1] = {300, 400, 200, 100,pic[1].object, 0,0,564,300, TX_WHITE);
    center[2] = {300, 550, 200, 100,pic[2].object, 0,0,571,393, TX_WHITE);
    center[3] = {300, 250, 200, 100,pic[3].object, 0,0,900,195, TX_WHITE);
    center[4] = {300, 400, 200, 100,pic[4].object, 0,0,512,355, TX_WHITE);
    center[5] = {300, 550, 200, 100,pic[5].object, 0,0,650,400, TX_WHITE);
    center[6] = {300, 550, 200, 100,pic[6].object, 0,0,650,400, TX_WHITE);
    center[7] = {300, 550, 200, 100,pic[7].object, 0,0,650,400, TX_WHITE);
    center[8] = {300, 550, 200, 100,pic[8].object, 0,0,650,400, TX_WHITE);
    center[9] = {300, 550, 200, 100,pic[9].object, 0,0,650,400, TX_WHITE);
    center[10] = {300, 550, 200, 100,pic[10].object, 0,0,650,400, TX_WHITE);
    center[11] = {300, 550, 200, 100,pic[11].object, 0,0,650,400, TX_WHITE);*/

    string PAGE = "Справка";
    const int N_Button = 7;
    Button buttons[N_Button];
    buttons[0] = {10, 10, "Дома",TX_CYAN,TX_YELLOW, "Home"};
    buttons[1] = {210, 10, "Парки",TX_GREEN,TX_ORANGE, "Park"};
    buttons[2] = {410, 10, "Здании",TX_BLUE,TX_MAGENTA, "Zdania"};
    buttons[3] = {610, 10, "Природа",TX_MAGENTA,TX_BLUE, "Tree"};
    buttons[4] = {810, 10, "Дороги",TX_ORANGE,TX_GREEN};
    buttons[5] = {1010, 10, "Многоэтажки",TX_YELLOW,TX_CYAN};
    buttons[6] = {1210, 10, "?",TX_WHITE,TX_BLACK};





    bool gameOver = false;
    while (!gameOver)
    {
        txBegin();


    if (PAGE == "Справка")
    {
        txSetFillColor(TX_WHITE);
        txSetColor(TX_BLACK);
        txClear();
        txDrawText(1200, 0, 1300, 100, "Другой режим");
     txDrawText(100, 100, 1200, 500, "Привет \n"
              "это конструктор города \n"
              "здесь ты сможешь создать свой новый город в котором будет всё как ты хочеш\n"
              "для остройки города тебе нужно иметь фотназию и логику толко не путайте логику и упоротую логику"
              "управление обьектами осущевляется при помощи мыши\n"
             );


        if (txMouseButtons() == 1 &&
         txMouseX() >= 1200 &&
         txMouseX() <= 1300)
       {
           PAGE = "Редактор";
                txSleep(2000);
       }

    }
        if (PAGE == "Редактор")
        {
            if (txMouseButtons() == 1 &&
                     txMouseX() >= 0 &&
                     txMouseX() <= 100)
             {
                 PAGE = "Справка";
                txSleep(2000);
             }
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

                 if (txMouseButtons() == 1 &&
                txMouseX() >= 1210 &&  txMouseX() <= 1525 &&
                txMouseY() >= 10 && txMouseY() <= 10 && category == "?" )






            if (drawObject1)
                Win32::TransparentBlt (txDC(),center[0].x,center[0].y,200,100,center[0].object,0,0,615,369, TX_WHITE);
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

    return 0;
}
