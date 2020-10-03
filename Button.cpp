#include "TXLib.h"

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
