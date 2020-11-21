#include <string>
#include <iostream>
#include <dirent.h>
#include "TXLib.h"
using namespace std;

int main()
{
    txCreateWindow (1532 , 840);
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
    //ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Excel files 2003(*.xls)\0*.xls\0Excel files 2007(*.xlsx)\0*.xlsx\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Отображение диалогового окна "Открыть".

    if (GetOpenFileName(&ofn)==TRUE)
    {


    }

}


