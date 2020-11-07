#include "TXLib.h"
#include "Picture.cpp"
#include "Button.cpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

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

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);




    string category = "Home";

    int n_active = -30;
    //��� ������ ��� ����������?
    bool Mnogoetajka1 = false;
    //� ���?
    bool LKM = false;

    const int N_PICS = 24;
    Picture pic[N_PICS];
    pic[0] = {"����/dom1.bmp", "����"};
    pic[1] = {"����/dom2.bmp", "����"};
    pic[2] = {"����/dom3.bmp", "����"};
    pic[3] = {"����/dom4.bmp", "����"};
    pic[4] = {"����/dom5.bmp", "����"};
    pic[5] = {"����/dom6.bmp", "����"};
    //� ������ ��� ��� �������?
    pic[6] = {"����/mnogoetajka1.bmp", "Mnogoetajka1"};
    pic[7] = {"�����/park1.bmp", "�����"};
    pic[8] = {"�����/park2.bmp", "�����"};
    pic[9] = {"�����/park3.bmp", "�����"};
    pic[10] = {"�������/tree1.bmp", "�������"};
    pic[11] = {"�������/tree2.bmp", "�������"};
    pic[12] = {"�������/tree3.bmp", "�������"};
    pic[13] = {"�������/tree4.bmp", "�������"};
    pic[14] = {"�������/tree5.bmp", "�������"};
    pic[15] = {"�������/tree6.bmp", "�������"};
    pic[16] = {"������/Zdania1.bmp", "������"};
    pic[17] = {"������/Zdania2.bmp", "������"};
    pic[18] = {"������/Zdania3.bmp", "������"};
    pic[19] = {"������/Zdania4.bmp", "������"};
    pic[20] = {"������/Zdania5.bmp", "������"};
    pic[21] = {"������/doroga1.bmp", "������"};
    pic[22] = {"������/doroga2.bmp", "������"};
    pic[23] = {"������/doroga3.bmp", "������"};


    int ydoma = 150;
    int ypark = 150;
    int yderevo = 150;
    int ysdania = 150;
    int ydorogi = 150;
    for(int nomer = 0; nomer < N_PICS; nomer = nomer + 1)
    {
        string address = pic[nomer].address;


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
        pic[nomer].x = 1300;
        pic[nomer].object = txLoadImage(pic[nomer].address);
        pic[nomer].height = getHeight(pic[nomer].address);
        pic[nomer].width = getWidth(pic[nomer].address);
    }

    int n_pics = 0;
    Picture center[2000];



    /*ifstream file1("dungeonmaster.txt");

    //while(file1.good())
    {
        n_pics = 1;
        string s;
        getline(file1, s);
        center[0].x = atoi(s.c_str());
        getline(file1, s);
        center[0].y = atoi(s.c_str());
        center[0].address = pic[0].address;
        center[0].heightPic = getHeight(center[0].address);
        center[0].widthPic = getWidth(center[0].address);
        center[0].height = getHeight(center[0].address);
        center[0].width = getWidth(center[0].address);
        center[0].visible = true;
        center[0].object = pic[0].object;

    }
    file1.close();*/



    const int N_Button = 9;
    Button buttons[N_Button];
    buttons[0] = {"����",TX_CYAN,TX_YELLOW, "����"};
    buttons[1] = {"�����",TX_GREEN,TX_ORANGE, "�����"};
    buttons[2] = {"������",TX_BLUE,TX_MAGENTA, "������"};
    buttons[3] = {"�������",TX_MAGENTA,TX_BLUE, "�������"};
    buttons[4] = {"������",TX_ORANGE,TX_GREEN, "������"};
    buttons[5] = {"�����������",TX_YELLOW,TX_CYAN};
    buttons[6] = {"?",TX_WHITE,TX_BLACK};
    buttons[7] = {"����������",TX_WHITE,TX_BLACK};
    buttons[8] = {"��������",TX_WHITE,TX_BLACK};
    for(int N = 0; N < N_Button; N++)
    {
        buttons[N].x = txGetExtentX() * 0.85 * N / N_Button;
        buttons[N].y = 10;
        buttons[N].width = txGetExtentX() * 0.85 / N_Button;
    }


    string PAGE = "��������";



    const int MAX_X = 1300;
    const int MAX_Y = 840;

    bool gameOver = false;
    while (!gameOver)
    {
        txBegin();

        if (PAGE == "�������")
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);
            txClear();
            txDrawText(1200, 0, 1300, 100, "������!");
            txDrawText(100, 100, 1200, 500,
                  "������ \n"
                  "��� ����������� ������!!\n"
                  "����� �� ������ ��������� �������, �������� �����!\n"
                  "��� �� ����� ��������� ����� ���� ���� ������ ����� �������� ���������!!!\n"
                  "����� � ������ �� ������ ����������� � ��������� ���� � �����,\n"
                  "������� ������, � ����� ���� ���� �� ����������� �� ������ ������� �������� ����� ������� ���� �� �����������\n"
                  "� ��� ���� �������� ���� ����� � ������\n"
                  "���������: �������� ��������� � ������� ����\n"
                  "���������: �������� ����!!..\n"
            );


            if (Click(buttons[6].x,buttons[6].y))
            {
                PAGE = "��������";
                txSleep(500);
            }

        }
        if (PAGE == "��������")
        {
            if (Click(buttons[6].x,buttons[6].y))
            {
                PAGE = "�������";
                txSleep(500);
            }

            txSetFillColour(TX_GRAY);
            txSetColour(TX_BLACK);
            txRectangle(0,0,1532,150);
            txRectangle(MAX_X,150,1532,MAX_Y);
            txSetFillColour(TX_WHITE);
            txRectangle(0,150,MAX_X,MAX_Y);

            for (int i = 0; i < n_pics; i++)
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

            //��������� ����������� ��������
            drawCentralPictures(n_pics, center);

            //��������� �������� ��������
            for (int i = 0; i < N_PICS; i++)
            {
                if (txMouseButtons() == 1 &&
                    txMouseX() >= pic[i].x && txMouseX() <= pic[i].x + 200 &&
                    txMouseY() >= pic[i].y && txMouseY() <= pic[i].y + 100 && category == pic[i].category )
                {
                    center[n_pics] = {pic[i].address, pic[i].category, random(0,MAX_X - 200), random(150,840 - 100), pic[i].width, pic[i].height, pic[i].object, true, 200, 100};
                    n_pics++;
                    txSleep(200);
                }
            }


            //�������� �� �������������
            for (int i = 0; i < n_pics; i++)
            {
                if(n_active != i &&
                   center[n_active].x + 200 >= center[i].x &&
                   center[n_active].x       <= center[i].x + 200 &&
                   center[n_active].y + 100 >= center[i].y &&
                   center[n_active].y       <= center[i].y + 100)
                {
                    center[n_active].x = center[n_active].x + 100;
                    center[n_active].y = center[n_active].y + 100;
                    n_active = -1;
                }

            }


            //��������
            if(GetAsyncKeyState(VK_DELETE))
            {
                n_pics = n_pics - 1;
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

            //������������ ������ ��������
            if (Click(buttons[8].x, buttons[8].y))
            {
                ifstream file1("dungeonmaster.txt");

                //while(file1.good())
                {
                    n_pics = 1;
                    string s;
                    getline(file1, s);
                    center[0].x = atoi(s.c_str());
                    getline(file1, s);
                    center[0].y = atoi(s.c_str());
                    center[0].address = pic[0].address;
                    center[0].heightPic = getHeight(center[0].address);
                    center[0].widthPic = getWidth(center[0].address);
                    center[0].height = getHeight(center[0].address);
                    center[0].width = getWidth(center[0].address);
                    center[0].visible = true;
                    center[0].object = pic[0].object;
                }

                file1.close();
                txMessageBox("��������");
            }

            //������������ ����������
            if(Click(buttons[7].x, buttons[7].y))
            {
                std::ofstream out("dungeonmaster.txt");

                for (int i = 0; i < n_pics; i++)
                {
                    if (center[i].visible)
                    {
                    out << center[i].x << std::endl;
                    out << center[i].y << std::endl;
                    }
                }
                out.close();
                txMessageBox("����������");
            }

        }


        txSleep(20);
        txEnd();
    }


    for (int i = 0; i < N_PICS; i++)
        txDeleteDC(pic[i].object);

    for (int i = 0; i < n_pics; i++)
        txDeleteDC(center[i].object);

    return 0;
}
