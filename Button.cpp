/// \file Button.cpp
/// \brief Кнопка

#include "TXLib.h"

///Структура кнопки
struct Button
{
    const char* text;
    COLORREF colorButton;
    COLORREF colorText;
    string category;
    int x;
    int y;
    int width;
    int height;
};

///Рисование кнопок
void drawButton(int x,int y,int width,const char* text,COLORREF color,COLORREF color1)
{
    txSetColour(TX_BLACK);
    txSetFillColour(color);
    txRectangle(x,y,x + width,y + 130);
    txSetColour(color1);
    txSelectFont("ARIAL", 25);
    txDrawText(x,y,x + width,y + 130,text);
}

///Клик на кнопку
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

///Рисование всех кнопок
void drawAllButtons(const int N_Button, Button* buttons)
{
    for (int i = 0; i < N_Button; i++)
        drawButton(buttons[i].x, buttons[i].y, buttons[i].width, buttons[i].text, buttons[i].colorButton, buttons[i].colorText);
}

///Выбор категорий
string selectCategory(const int N_Button, Button* buttons, string category)
{
    for (int i = 0; i < N_Button; i++)
            if (Click(buttons[i].x, buttons[i].y))
                category = buttons[i].category;
    return category;
}
