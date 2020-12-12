/// \file Picture.cpp
/// \brief ��������
#include "TXLib.h"
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

///��������� ��������
struct Picture
{
    ///����� ����� � ���������
    string address;
    ///��������� ��������
    string category;
    ///���������� �
    int x;
    ///���������� y
    int y;
    ///������ �������� �� ������
    int width;
    ///������ �������� �� ������
    int height;
    ///����� ��������
    HDC object;
    ///��������� ��������
    bool visible;
    ///������ �������� � �����
    int widthPic;
    ///������ �������� � �����
    int heightPic;
};

///��������� ������ ��� ������
///\param N_PICS ���������� ��������, category ������������� ��������� ��������, pic ����� ��������
void drawRightPictures(const int N_PICS, Picture* pic, string category)
{
     for (int i = 0; i < N_PICS; i++)
            if(category == pic[i].category)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
}

///������ ������ �� �����
///\param address ����� �����
///\return Width ������ ��������
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

///������ ������ �� �����
///\param address ����� �����
///\return Height ������ ��������
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

///������ ������
///\param address ����� �����
///\return ���������� ��������
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

///��������� �������� � ������ ��������� � ��������� ������ ��������
///\param pic ������ ��������
///\return ���������� ��������
int fillVariants(Picture* pic)
{
    //������ ������ ��������
    int N_PICS = file_read("����/", pic, 0);
    N_PICS = file_read("�����������/", pic, N_PICS);
    N_PICS = file_read("�����/", pic, N_PICS);
    N_PICS = file_read("�������/", pic, N_PICS);
    N_PICS = file_read("������/", pic, N_PICS);
    N_PICS = file_read("������/", pic, N_PICS);

    int ydoma = 150;
    int yhighbuildings = 150;
    int ypark = 150;
    int yderevo = 150;
    int ysdania = 150;
    int ydorogi = 150;

    //������ ���������, ��������� ��������
    for(int nomer = 0; nomer < N_PICS; nomer = nomer + 1)
    {
        string address = pic[nomer].address;
        int pos = address.find(" ", 0);
        int pos2 = address.find("/", pos + 1);
        pic[nomer].category = address.substr(pos + 1,pos2 - pos - 1);

        if(pic[nomer].category == "����")
        {
            pic[nomer].y = ydoma;
            ydoma += 100;
        }
        if(pic[nomer].category == "�����")
        {
            pic[nomer].y = ypark;
            ypark += 100;
        }
        if(pic[nomer].category == "�������")
        {
            pic[nomer].y = yderevo;
            yderevo += 100;
        }
        if(pic[nomer].category == "������")
        {
            pic[nomer].y = ysdania;
            ysdania += 100;
        }
        if(pic[nomer].category == "������")
        {
            pic[nomer].y = ydorogi;
            ydorogi += 100;
        }
         if(pic[nomer].category == "�����������")
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

///\brief ��������� ����������� ��������
///\param center ������ ����������� ��������,
///\param center_x ��������� ������ / ���� �����������
///\param n_pics ���������� ��������
void drawCentralPictures(int n_pics, Picture* center, int center_x)
{
    for (int i = 0; i < n_pics; i++)
    {
        if (center[i].visible)
            Win32::TransparentBlt (txDC(),center[i].x - center_x,center[i].y,center[i].widthPic,center[i].heightPic,center[i].object,0,0,center[i].width,center[i].height, TX_WHITE);
    }
}
