#include <string>
#include <iostream>
#include <dirent.h>
#include "TXLib.h"
using namespace std;

int main()
{
    txCreateWindow (1532 , 840);
    OPENFILENAME ofn;     // ����� ��������� ����������� ����
    char szFile[260] = {0};      // ����� ��� ����� �����
    HWND hwnd;              // ���� ���������
    HANDLE hf;              // ���������� �����

    // ���������������� OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = txWindow();
    ofn.lpstrFile = szFile;
    // ������������� lpstrFile [0] � '\ 0', ����� GetOpenFileName ��
    // ������������ ���������� szFile ��� �������������.
    //ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Excel files 2003(*.xls)\0*.xls\0Excel files 2007(*.xlsx)\0*.xlsx\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // ����������� ����������� ���� "�������".

    if (GetOpenFileName(&ofn)==TRUE)
    {


    }

}


