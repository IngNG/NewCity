/// \file main.cpp
/// \brief ������� ����
#include "TXLib.h"
#include "Picture.cpp"
#include "Button.cpp"




int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);



    int center_x = 0;
    string category = "Home";
    int i = 0;
    int n_active = -30;
    //��� ������ ��� ����������?
    bool Mnogoetajka1 = false;
    //� ���?
    bool LKM = false;

    Picture pic[6060];
    int N_PICS = fillVariants(N_PICS, pic);

    int n_variants = 0;
    Picture center[2000];

    const int N_Button = 9;
    Button buttons[N_Button];
    buttons[0] = {"����",TX_CYAN,TX_YELLOW, "����"};
    buttons[1] = {"�����",TX_GREEN,TX_ORANGE, "�����"};
    buttons[2] = {"������",TX_BLUE,TX_MAGENTA, "������"};
    buttons[3] = {"�������",TX_MAGENTA,TX_BLUE, "�������"};
    buttons[4] = {"������",TX_ORANGE,TX_GREEN, "������"};
    buttons[5] = {"�����������",TX_YELLOW,TX_CYAN, "�����������"};
    buttons[6] = {"?",TX_WHITE,TX_BLACK};
    buttons[7] = {"����������",TX_WHITE,TX_BLACK};
    buttons[8] = {"��������",TX_WHITE,TX_BLACK};

    ///������������ ������
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
            txDrawText(1000, 600, 1200, 700, "������!");
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

            if (txMouseButtons() == 1 &&
                txMouseX() >= 1000 && txMouseY() >= 600 &&
                txMouseX() <= 1200 && txMouseY() <= 700)
            {
                PAGE = "��������";
                txSleep(500);
            }

        }
        if (PAGE == "��������")
        {
            if (Click(buttons[6].x, buttons[6].y))
            {
                PAGE = "�������";
                txSleep(500);
            }

            txSetFillColour(TX_GRAY);
            txSetColour(TX_BLACK);
            txRectangle(0,0,1532,150);
            txSetFillColour(TX_WHITE);
            txRectangle(0,150,MAX_X,MAX_Y);


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

            //��������� ����������� ��������
            drawCentralPictures(n_variants, center, center_x);

            category = selectCategory(N_Button, buttons, category);

            txSetFillColour(TX_GRAY);
            txRectangle(MAX_X,150,1532,MAX_Y);

            drawRightPictures(N_PICS, pic, category);



            ///��������� �������� ��������
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


            ///�������� �� �������������
            for (int i = 0; i < n_variants; i++)
            {
                for(int k = 0; k < n_variants; k++)
                {
                    if(k != i &&
                        center[i].x < center[k].x + center[k].widthPic  &&
                        center[k].x < center[i].x + center[i].widthPic  &&
                        center[i].y < center[k].y + center[k].heightPic &&
                        center[k].y < center[i].y + center[i].heightPic &&
                        center[k].category != "������")
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

            ///�������� �� �����
            if(GetAsyncKeyState(VK_LEFT))
            {
                center_x = center_x + 5;
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {
                center_x = center_x - 5;
            }

            ///��������
            if(GetAsyncKeyState(VK_DELETE))
            {
                n_variants = n_variants - 1;
            }

            ///���������� � ���������� ��������
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
            ///����� �� �������
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gameOver = true;
            }

            ///������������ ������ ��������
            if (Click(buttons[8].x, buttons[8].y))
            {
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
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Text\0*.txt";
                ofn.nFilterIndex = 1;
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                // ����������� ����������� ���� "�������".

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
                            //������
                            getline(file1, s);
                            center[n_variants].widthPic = atoi(s.c_str());
                            // ������
                            getline(file1, s);
                            center[n_variants].heightPic = atoi(s.c_str());
                            //�����
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

            ///������������ ����������
            if(Click(buttons[7].x, buttons[7].y))
            {
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
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Text\0*.txt";
                ofn.nFilterIndex = 1;
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                // ����������� ����������� ���� "�������".

                if (GetSaveFileName(&ofn)==TRUE)
                {
                    ofstream out(ofn.lpstrFile);

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

            }


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
