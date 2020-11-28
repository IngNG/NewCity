#include "TXLib.h"

struct Picture
{
    string address;
    string category;
    int x;
    int y;
    int width;
    int height;
    HDC object;
    bool visible;
    int widthPic;
    int heightPic;
};

void drawRightPictures(const int N_PICS, Picture* pic, string category)
{
     for (int i = 0; i < N_PICS; i++)
            if(category == pic[i].category)
                Win32::TransparentBlt (txDC(),pic[i].x,pic[i].y,200,100,pic[i].object,0,0,pic[i].width,pic[i].height, TX_WHITE);
}

void drawCentralPictures(int n_pics,Picture* center)
{
    for (int i = 0; i < n_pics; i++)
        {
            if (center[i].visible)
            Win32::TransparentBlt (txDC(),center[i].x,center[i].y,center[i].widthPic,center[i].heightPic,center[i].object,0,0,center[i].width,center[i].height, TX_WHITE);
        }
}
