/// \file main.cpp
/// \brief Главный файл
#include "TXLib.h"
#include "Picture.cpp"
#include "Button.cpp"

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);

    //картинки дорог
    HDC picLeftRight = txLoadImage("Дороги/dorogaLeftRight.bmp");
    HDC picLeftUp = txLoadImage("Дороги/dorogaLeftUp.bmp");
    HDC picLeftDown = txLoadImage("Дороги/dorogaLeftDown.bmp");
    HDC picRightDown = txLoadImage("Дороги/dorogaRightDown.bmp");
    HDC picRightUp = txLoadImage("Дороги/dorogaRightUp.bmp");
    HDC picUpDown = txLoadImage("Дороги/dorogaUpDown.bmp");
    HDC pic4 = txLoadImage("Дороги/doroga4.bmp");
    HDC pic3Up = txLoadImage("Дороги/doroga3Up.bmp");
    HDC pic3Down = txLoadImage("Дороги/doroga3Down.bmp");
    HDC pic3Right = txLoadImage("Дороги/doroga3Right.bmp");
    HDC pic3Left = txLoadImage("Дороги/doroga3Left.bmp");
    HDC picTupikUp = txLoadImage("Дороги/dorogaTupikUp.bmp");
    HDC picTupikDown = txLoadImage("Дороги/dorogaTupikDown.bmp");
    HDC picTupikRight = txLoadImage("Дороги/dorogaTupikRight.bmp");
    HDC picTupikLeft = txLoadImage("Дороги/dorogaTupikLeft.bmp");

    bool dorogi[30][30];
    bool drawDorogi = true;

    for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++)
        dorogi[i][j] = false;



    int center_x = 0;
    string category = "Home";
    int i = 0;
    int n_active = -30;



    Picture pic[6060];
    int N_PICS = fillVariants(pic);

    //Картинки на карте города
    Picture center[2000];
    int n_variants = 0;


    const int N_Button = 9;
    Button buttons[N_Button];
    buttons[0] = {"Дома",TX_CYAN,TX_YELLOW, "Дома"};
    buttons[1] = {"Парки",TX_GREEN,TX_ORANGE, "Парки"};
    buttons[2] = {"Здания",TX_BLUE,TX_MAGENTA, "Здания"};
    buttons[3] = {"Деревья",TX_MAGENTA,TX_BLUE, "Деревья"};
    buttons[4] = {"Дороги",TX_ORANGE,TX_GREEN, "1"};
    buttons[5] = {"Многоэтажки",TX_YELLOW,TX_CYAN, "многоэтажки"};
    buttons[6] = {"?",TX_WHITE,TX_BLACK};
    buttons[7] = {"Сохранение",TX_WHITE,TX_BLACK};
    buttons[8] = {"Загрузка",TX_WHITE,TX_BLACK};

    ///Расставление кнопок
    for(int N = 0; N < N_Button; N++)
    {
        buttons[N].x = txGetExtentX() * 0.85 * N / N_Button;
        buttons[N].y = -5;
        buttons[N].width = txGetExtentX() * 0.85 / N_Button;
    }


    string PAGE = "Редактор";

    const int MAX_X = 1300;
    const int MAX_Y = 840;

    bool gameOver = false;
    while (!gameOver)
    {
        txBegin();

        if (PAGE == "Справка")
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);
            txClear();
            txDrawText(1000, 600, 1200, 700, "Начать!");
            txDrawText(100, 100, 1200, 500,
                  "Привет \n"
                  "Это конструктор города!!\n"
                  "Здесь ты можешь построить большой, красивый город!\n"
                  "Для то чтобы построить город тебе надо только уметь включить компьютер!!!\n"
                  "Также в городе ты можешь увеличивать и уменьшать дома и парки,\n"
                  "Строить дороги, а также если тебе не понравиться ты можешь удалить картинки домов которые тебе не понравились\n"
                  "У нас есть обширное меню домов и парков\n"
                  "Создатели: Тимофеев Владислав и Храмцов Артём\n"
                  "Изгнанный: Плешаков Артём!!..\n"
            );

            if (txMouseButtons() == 1 &&
                txMouseX() >= 1000 && txMouseY() >= 600 &&
                txMouseX() <= 1200 && txMouseY() <= 700)
            {
                PAGE = "Редактор";
                txSleep(500);
            }

        }
        if (PAGE == "Редактор")
        {
            if (Click(buttons[6].x, buttons[6].y))
            {
                PAGE = "Справка";
                txSleep(500);
            }

            txSetFillColour(TX_GRAY);
            txSetColour(TX_BLACK);
            txRectangle(0,0,1532,100);
            txSetFillColour(TX_WHITE);
            txRectangle(0,100,MAX_X,MAX_Y);

            ///Рисование кнопок движения по экрану
            txSetFillColor(TX_RED);
            txRectangle(0, 755, 75, 840);
            txDrawText(0, 755, 75, 840, "<<<");
            txRectangle(1225, 755, 1300, 840);
            txDrawText(1225, 755, 1300, 840, ">>>");
            if (txMouseButtons() == 1 &&
                txMouseX() > 0 &&  txMouseX() < 75 &&
                txMouseY() > 755 &&  txMouseY() < 840)
            {
                center_x = center_x - 5;
            }

            if (txMouseButtons() == 1 &&
                txMouseX() > 1225 &&  txMouseX() < 1300 &&
                txMouseY() > 755 &&  txMouseY() < 840)
            {
                center_x = center_x + 5;
            }

            for (int i = 0; i < n_variants; i++)
            {
                if (txMouseButtons() == 1 &&
                    center[i].visible &&
                    txMouseX() >= center[i].x - center_x &&
                    txMouseX() <= center[i].x - center_x + 200 &&
                    txMouseY() >= center[i].y && txMouseY() <= center[i].y + 100 && n_active < 0)
                {
                    n_active = i;
                }
            }

            drawAllButtons(N_Button, buttons);


            if(n_active >= 0)
            {
                center[n_active].x = txMouseX() - 60 + center_x;
                center[n_active].y = txMouseY() - 50;
            }

            if(txMouseButtons() == 0)
                n_active = -100;

            category = selectCategory(N_Button, buttons, category);



            //появление активной картинки
            for (int i = 0; i < N_PICS; i++)
            {
                if (txMouseButtons() == 1 &&
                    txMouseX() >= pic[i].x && txMouseX() <= pic[i].x + 200 &&
                    txMouseY() >= pic[i].y && txMouseY() <= pic[i].y + 100 && category == pic[i].category )
                {
                    center[n_variants] = {pic[i].address, pic[i].category, random(0,MAX_X - 200), random(150,840 - 100), pic[i].width, pic[i].height, pic[i].object, true, 200, 100};
                    n_variants++;
                    txSleep(200);
                }
            }


            ///Картинки не накладываются
            for (int i = 0; i < n_variants; i++)
            {
                for(int k = 0; k < n_variants; k++)
                {
                    if(k != i &&
                        center[i].x < center[k].x + center[k].widthPic  &&
                        center[k].x < center[i].x + center[i].widthPic  &&
                        center[i].y < center[k].y + center[k].heightPic &&
                        center[k].y < center[i].y + center[i].heightPic &&
                        center[k].category != "Дороги")
                    {
                        if (center[i].x < center[k].x)
                        {
                            center[k].x = center[i].x + center[i].widthPic;
                        }
                        else if (center[i].x > center[k].x)
                        {
                            center[i].x = center[k].x + center[k].widthPic;
                        }
                        else if (center[i].y < center[k].y)
                        {
                            center[k].y = center[i].y + center[i].heightPic;
                        }
                        else if (center[i].y > center[k].y)
                        {
                            center[i].y = center[k].y + center[k].heightPic;
                        }
                    }
                }
            }

            drawDorogi = false;
            if (category == "1")
            {
                drawDorogi = true;
            }

            int x = round((txMouseX() + center_x) / 100);
            int y = round(txMouseY() / 100);

            if (txMouseButtons() == 1 && drawDorogi && txMouseY() > 100)
                dorogi [x][y] = true;
            if (txMouseButtons() == 2)
                dorogi [x][y] = false;

            for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
            if(dorogi[i][j])
            {
                if (dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic4);

                else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Up);
                else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Down);
                else if(dorogi[i+1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Right);
                else if(dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Left);

                else if(dorogi[i-1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftUp);
                else if(dorogi[i-1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftDown);
                else if(dorogi[i+1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picRightDown);
                else if(dorogi[i+1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picRightUp);

                else if (dorogi[i][j+1] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picUpDown);
                else if (dorogi[i+1][j] && dorogi[i-1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftRight);

                else if (dorogi[i-1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikRight);
                else if (dorogi[i+1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikLeft);
                else if (dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikUp);
                else if (dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikDown);
            }

            //Скриншот
            if(GetAsyncKeyState(VK_SNAPSHOT))
            {
                ScreenCapture(0, 150, MAX_X, 700, "screen.bmp", txWindow());
                txMessageBox ("Скриншот сохранён.");
            }

            //Удаление
            if(GetAsyncKeyState(VK_DELETE))
            {
                n_variants = n_variants - 1;
            }

            //Уменьшение и увеличение картинок
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
            //Выход по ескейпу
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gameOver = true;
            }

            //Срабатывание кнопки загрузки
            if (Click(buttons[8].x, buttons[8].y))
            {
                OPENFILENAME ofn;     // общая структура диалогового окна
                char szFile[260] = {0};      // буфер для имени файла
                HWND hwnd;              // окно владельца
                HANDLE hf;              // дескриптор файла

                // Инициализировать OPENFILENAME
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = txWindow();
                ofn.lpstrFile = szFile;
                // Устанавливаем lpstrFile [0] в '\ 0', чтобы GetOpenFileName не
                // использовать содержимое szFile для инициализации.
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Text\0*.txt";
                ofn.nFilterIndex = 1;
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                // Отображение диалогового окна "Открыть".

                if (GetOpenFileName(&ofn)==TRUE)
                {

                    ifstream file1(ofn.lpstrFile);
                    n_variants = 0;
                    while(file1.good())
                    {
                        string s;
                        //x
                        getline(file1, s);
                        if (s == "А теперь дороги")
                        {
                            for(int i = 0; i < 30; i++)
                            {
                                for(int j = 0; j < 30; j++)
                                {
                                    char ch = file1.get();
                                    dorogi[j][i] = (ch == '1');
                                }
                                file1.get();
                            }
                            getline(file1, s);
                        }
                        else if (s.length()  > 0)
                        {
                            center[n_variants].x = atoi(s.c_str());
                            //y
                            getline(file1, s);
                            center[n_variants].y = atoi(s.c_str());
                            //Ширина
                            getline(file1, s);
                            center[n_variants].widthPic = atoi(s.c_str());
                            // Высота
                            getline(file1, s);
                            center[n_variants].heightPic = atoi(s.c_str());
                            //адрес
                            getline(file1, s);
                            center[n_variants].address = s.c_str();

                            string address = center[n_variants].address;
                            int pos = address.find(" ", 0);
                            int pos2 = address.find("/", pos + 1);
                            center[n_variants].category = address.substr(pos + 1,pos2 - pos - 1);

                            center[n_variants].height = getHeight(center[n_variants].address.c_str());
                            center[n_variants].width = getWidth(center[n_variants].address.c_str());
                            center[n_variants].visible = true;
                            center[n_variants].object = txLoadImage(center[n_variants].address.c_str());

                            n_variants = n_variants + 1;
                        }
                    }

                    file1.close();
                }



            }

            //Срабатывание сохранения
            if(Click(buttons[7].x, buttons[7].y))
            {
                OPENFILENAME ofn;     // общая структура диалогового окна
                char szFile[260] = {0};      // буфер для имени файла
                HWND hwnd;              // окно владельца
                HANDLE hf;              // дескриптор файла

                // Инициализировать OPENFILENAME
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = txWindow();
                ofn.lpstrFile = szFile;
                // Устанавливаем lpstrFile [0] в '\ 0', чтобы GetOpenFileName не
                // использовать содержимое szFile для инициализации.
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Text\0*.txt";
                ofn.nFilterIndex = 1;
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                // Отображение диалогового окна "Открыть".

                if (GetSaveFileName(&ofn)==TRUE)
                {
                    ofstream out(ofn.lpstrFile);

                    for (int i = 0; i < n_variants; i++)
                    {
                        if (center[i].visible)
                        {
                            out << center[i].x << endl;
                            out << center[i].y << endl;
                            out << center[i].widthPic << endl;
                            out << center[i].heightPic << endl;
                            out << center[i].address << endl;
                        }
                    }

                    out << "А теперь дороги" << endl;
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 0; j < 30; j++)
                            out << dorogi[j][i];
                        out << endl;
                    }
                    out.close();
                }
            }

            //Рисование центральных картинок
            drawCentralPictures(n_variants, center, center_x);

            //Варианты картинок
            txSetFillColour(TX_GRAY);
            txRectangle(MAX_X,100,1532,MAX_Y);

            drawRightPictures(N_PICS, pic, category);
        }


        txSleep(20);
        txEnd();
    }


    for (int i = 0; i < N_PICS; i++)
        txDeleteDC(pic[i].object);

    for (int i = 0; i < n_variants; i++)
        txDeleteDC(center[i].object);

    return 0;
}
