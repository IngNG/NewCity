#include "TXLib.h"
#include "Picture.cpp"
#include "Button.cpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <string>
using namespace std;

int getWidth(const char* address)
{
    char header[54];
    ifstream bmp;
    bmp.open(address, ios::in | ios::binary);
    bmp.read(header, 54);
    int width;
    memcpy(&width, &header[18], sizeof(width));
    return width;
}

int getHeight(const char* address)
{
    char header[54];
    ifstream bmp;
    bmp.open(address, ios::in | ios::binary);
    bmp.read(header, 54);
    int height;
    memcpy(&height, &header[22], sizeof(height));
    return height;
}

int file_read(const char* address, Picture* pic, int N)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (address)) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            string s = ent -> d_name;
            s = address + s;
            if(s.find(".bmp") != -1)
           {
                pic[N] = {s};
                N++;
           }
        }
     closedir (dir);
    }
    return N;
}

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);




    string category = "Home";
    int i = 0;
    int n_active = -30;
    //Что делает эта переменная?
    bool Mnogoetajka1 = false;
    //А эта?
    bool LKM = false;

    int N_PICS = 0;
    Picture pic[6060];
    N_PICS = file_read("Дома/", pic, N_PICS);
    N_PICS = file_read("многоэтажки/", pic, N_PICS);
    N_PICS = file_read("Парки/", pic, N_PICS);
    N_PICS = file_read("Деревья/", pic, N_PICS);
    N_PICS = file_read("Здания/", pic, N_PICS);
    N_PICS = file_read("Дороги/", pic, N_PICS);

    int ydoma = 150;
    int yhighbuildings = 150;
    int ypark = 150;
    int yderevo = 150;
    int ysdania = 150;
    int ydorogi = 150;
    for(int nomer = 0; nomer < N_PICS; nomer = nomer + 1)
    {

        string address = pic[nomer].address;

        int pos = address.find(" ", 0);
        int pos2 = address.find("/", pos + 1);
        pic[nomer].category = address.substr(pos + 1,pos2 - pos - 1);

        if(pic[nomer].category == "Дома")
        {
            pic[nomer].y = ydoma;
            ydoma += 100;
        }
        if(pic[nomer].category == "Парки")
        {
            pic[nomer].y = ypark;
            ypark += 100;
        }
        if(pic[nomer].category == "Деревья")
        {
            pic[nomer].y = yderevo;
            yderevo += 100;
        }
        if(pic[nomer].category == "Здания")
        {
            pic[nomer].y = ysdania;
            ysdania += 100;
        }
        if(pic[nomer].category == "Дороги")
        {
            pic[nomer].y = ydorogi;
            ydorogi += 100;
        }
         if(pic[nomer].category == "многоэтажки")
        {
            pic[nomer].y = yhighbuildings;
            yhighbuildings += 100;
        }
        pic[nomer].x = 1300;
        pic[nomer].object = txLoadImage(pic[nomer].address.c_str());
        pic[nomer].height = getHeight(pic[nomer].address.c_str());
        pic[nomer].width = getWidth(pic[nomer].address.c_str());
    }

    int n_variants = 0;
    Picture center[2000];

    const int N_Button = 9;
    Button buttons[N_Button];
    buttons[0] = {"Дома",TX_CYAN,TX_YELLOW, "Дома"};
    buttons[1] = {"Парки",TX_GREEN,TX_ORANGE, "Парки"};
    buttons[2] = {"Здания",TX_BLUE,TX_MAGENTA, "Здания"};
    buttons[3] = {"Деревья",TX_MAGENTA,TX_BLUE, "Деревья"};
    buttons[4] = {"Дороги",TX_ORANGE,TX_GREEN, "Дороги"};
    buttons[5] = {"Многоэтажки",TX_YELLOW,TX_CYAN, "многоэтажки"};
    buttons[6] = {"?",TX_WHITE,TX_BLACK};
    buttons[7] = {"Сохранение",TX_WHITE,TX_BLACK};
    buttons[8] = {"Загрузка",TX_WHITE,TX_BLACK};
    for(int N = 0; N < N_Button; N++)
    {
        buttons[N].x = txGetExtentX() * 0.85 * N / N_Button;
        buttons[N].y = 10;
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
            txRectangle(0,0,1532,150);
            txRectangle(MAX_X,150,1532,MAX_Y);
            txSetFillColour(TX_WHITE);
            txRectangle(0,150,MAX_X,MAX_Y);

            for (int i = 0; i < n_variants; i++)
            {
                if (txMouseButtons() == 1 &&
                    center[i].visible &&
                    txMouseX() >= center[i].x && txMouseX() <= center[i].x + 200 &&
                    txMouseY() >= center[i].y && txMouseY() <= center[i].y + 100 && n_active < 0)
                {
                    n_active = i;
                }
            }

            drawAllButtons(N_Button, buttons);


            if(n_active >=0)
            {
                center[n_active].x = txMouseX() - 60;
                center[n_active].y = txMouseY() - 50;
            }

            if(txMouseButtons() == 0)
                n_active = -100;


            category = selectCategory(N_Button, buttons, category);

            drawRightPictures(N_PICS, pic, category);

            //Рисование центральных картинок
            drawCentralPictures(n_variants, center);

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


            //Картинки не накладываются
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


            //Удаление
            if(GetAsyncKeyState(VK_DELETE))
            {
                n_variants = n_variants - 1;
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
                        if (s.length()  > 0)
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
                            center[n_variants].height = getHeight(center[n_variants].address.c_str());
                            center[n_variants].width = getWidth(center[n_variants].address.c_str());
                            center[n_variants].visible = true;
                            txMessageBox(center[n_variants].address.c_str());
                            center[n_variants].object = txLoadImage(center[n_variants].address.c_str());

                            n_variants = n_variants + 1;
                        }
                    }

                    file1.close();
                    txMessageBox("Загрузка");
                }

            /*
                     */
            }

            //Срабатывание сохранения
            if(Click(buttons[7].x, buttons[7].y))
            {
                std::ofstream out("dungeonmaster.txt");

                for (int i = 0; i < n_variants; i++)
                {
                    if (center[i].visible)
                    {
                        out << center[i].x << std::endl;
                        out << center[i].y << std::endl;
                        out << center[i].widthPic << std::endl;
                        out << center[i].heightPic << std::endl;
                        out << center[i].address << std::endl;
                    }
                }
                out.close();
                txMessageBox("Сохранение");
            }

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
