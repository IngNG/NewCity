/// \file Picture.cpp
/// \brief Картинка
#include "TXLib.h"
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

///Структура картинок
struct Picture
{
    ///Адрес файла с картинкой
    string address;
    ///Категории картинок
    string category;
    ///Переменная х
    int x;
    ///Переменная y
    int y;
    ///Ширина картинок на экране
    int width;
    ///Высота картинок на экране
    int height;
    ///Адрес картинки
    HDC object;
    ///Видимость картинок
    bool visible;
    ///Ширина картинок в файле
    int widthPic;
    ///Высота картинок в файле
    int heightPic;
};

///Рисование иконок для выбора
///\param N_PICS Количество картинок, category использование категорий картинок, pic адрес картинки
void drawRightPictures(const int N_PICS, Picture* pic, string category)
{
     for (int i = 0; i < N_PICS; i++)
            if(category == pic[i].category)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
}

///Чтение ширины из файла
///\param address Адрес файла
///\return Width Ширина картинки
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

///Чтение высоты из файла
///\param address Адрес файла
///\return Height высота картинки
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

///Чтение файлов
///\param address Адрес файла
///\return Количество картинок
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

///Заполнять картинки в разные категории и нахожения адреса картинок
///\param pic Массив картинок
///\return Количество картинок
int fillVariants(Picture* pic)
{
    //Чтение списка картинок
    int N_PICS = file_read("Дома/", pic, 0);
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

    //Расчет координат, категорий картинок
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

        bool addressFind = false;
        for(int i = 0; i < nomer; i++)
        if(pic[i].address == address)
        {
          addressFind = true;
          pic[nomer].object = pic[i].object;
        }
        if(!addressFind)
            pic[nomer].object = txLoadImage(address.c_str());

        pic[nomer].x = 1300;
        pic[nomer].height = getHeight(pic[nomer].address.c_str());
        pic[nomer].width = getWidth(pic[nomer].address.c_str());
    }

    return N_PICS;
}

///\brief Рисование центральных картинок
///\param center массив центральных картинок,
///\param center_x Положение камеры / глаз наблюдателя
///\param n_pics Количество картинок
void drawCentralPictures(int n_pics, Picture* center, int center_x)
{
    for (int i = 0; i < n_pics; i++)
    {
        if (center[i].visible)
            Win32::TransparentBlt (txDC(),center[i].x - center_x,center[i].y,center[i].widthPic,center[i].heightPic,center[i].object,0,0,center[i].width,center[i].height, TX_WHITE);
    }
}
