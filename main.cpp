/// \file main.cpp
/// \brief ������� ����
#include "TXLib.h"
#include "Picture.cpp"
#include "Button.cpp"

int main()
{
    txCreateWindow (1532 , 840);
    txTextCursor (false);

    //�������� �����
    HDC picLeftRight = txLoadImage("������/dorogaLeftRight.bmp");
    HDC picLeftUp = txLoadImage("������/dorogaLeftUp.bmp");
    HDC picLeftDown = txLoadImage("������/dorogaLeftDown.bmp");
    HDC picRightDown = txLoadImage("������/dorogaRightDown.bmp");
    HDC picRightUp = txLoadImage("������/dorogaRightUp.bmp");
    HDC picUpDown = txLoadImage("������/dorogaUpDown.bmp");
    HDC pic4 = txLoadImage("������/doroga4.bmp");
    HDC pic3Up = txLoadImage("������/doroga3Up.bmp");
    HDC pic3Down = txLoadImage("������/doroga3Down.bmp");
    HDC pic3Right = txLoadImage("������/doroga3Right.bmp");
    HDC pic3Left = txLoadImage("������/doroga3Left.bmp");
    HDC picTupikUp = txLoadImage("������/dorogaTupikUp.bmp");
    HDC picTupikDown = txLoadImage("������/dorogaTupikDown.bmp");
    HDC picTupikRight = txLoadImage("������/dorogaTupikRight.bmp");
    HDC picTupikLeft = txLoadImage("������/dorogaTupikLeft.bmp");

    bool dorogi[30][30];
    bool drawDorogi = true;

    for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++)
        dorogi[i][j] = false;



    int center_x = 0;
    string category = "Home";
    int i = 0;
    int n_active = -30;



    Picture pic[6060];
    int N_PICS = fillVariants(pic);

    //�������� �� ����� ������
    Picture center[2000];
    int n_variants = 0;


    const int N_Button = 9;
    Button buttons[N_Button];
    buttons[0] = {"����",TX_CYAN,TX_YELLOW, "����"};
    buttons[1] = {"�����",TX_GREEN,TX_ORANGE, "�����"};
    buttons[2] = {"������",TX_BLUE,TX_MAGENTA, "������"};
    buttons[3] = {"�������",TX_MAGENTA,TX_BLUE, "�������"};
    buttons[4] = {"������",TX_ORANGE,TX_GREEN, "1"};
    buttons[5] = {"�����������",TX_YELLOW,TX_CYAN, "�����������"};
    buttons[6] = {"?",TX_WHITE,TX_BLACK};
    buttons[7] = {"����������",TX_WHITE,TX_BLACK};
    buttons[8] = {"��������",TX_WHITE,TX_BLACK};

    ///������������ ������
    for(int N = 0; N < N_Button; N++)
    {
        buttons[N].x = txGetExtentX() * 0.85 * N / N_Button;
        buttons[N].y = -5;
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
            txRectangle(0,0,1532,100);
            txSetFillColour(TX_WHITE);
            txRectangle(0,100,MAX_X,MAX_Y);

            ///��������� ������ �������� �� ������
            txSetFillColor(TX_RED);
            txRectangle(0, 755, 75, 840);
            txDrawText(0, 755, 75, 840, "<<<");
            txRectangle(1225, 755, 1300, 840);
            txDrawText(1225, 755, 1300, 840, ">>>");
            if (txMouseButtons() == 1 &&
                txMouseX() > 0 &&  txMouseX() < 75 &&
                txMouseY() > 755 &&  txMouseY() < 840)
            {
                center_x = center_x - 5;
            }

            if (txMouseButtons() == 1 &&
                txMouseX() > 1225 &&  txMouseX() < 1300 &&
                txMouseY() > 755 &&  txMouseY() < 840)
            {
                center_x = center_x + 5;
            }

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

            category = selectCategory(N_Button, buttons, category);



            //��������� �������� ��������
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

            drawDorogi = false;
            if (category == "1")
            {
                drawDorogi = true;
            }

            int x = round((txMouseX() + center_x) / 100);
            int y = round(txMouseY() / 100);

            if (txMouseButtons() == 1 && drawDorogi && txMouseY() > 100)
                dorogi [x][y] = true;
            if (txMouseButtons() == 2)
                dorogi [x][y] = false;

            for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
            if(dorogi[i][j])
            {
                if (dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic4);

                else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Up);
                else if(dorogi[i+1][j] && dorogi[i-1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Down);
                else if(dorogi[i+1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Right);
                else if(dorogi[i-1][j] && dorogi[i][j-1] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, pic3Left);

                else if(dorogi[i-1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftUp);
                else if(dorogi[i-1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftDown);
                else if(dorogi[i+1][j] && dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picRightDown);
                else if(dorogi[i+1][j] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picRightUp);

                else if (dorogi[i][j+1] && dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picUpDown);
                else if (dorogi[i+1][j] && dorogi[i-1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picLeftRight);

                else if (dorogi[i-1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikRight);
                else if (dorogi[i+1][j])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikLeft);
                else if (dorogi[i][j+1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikUp);
                else if (dorogi[i][j-1])
                    txBitBlt(txDC(), 100 * i - center_x,100 * j, 100, 100, picTupikDown);
            }

            //��������
            if(GetAsyncKeyState(VK_SNAPSHOT))
            {
                ScreenCapture(0, 150, MAX_X, 700, "screen.bmp", txWindow());
                txMessageBox ("�������� �������.");
            }

            //��������
            if(GetAsyncKeyState(VK_DELETE))
            {
                n_variants = n_variants - 1;
            }

            //���������� � ���������� ��������
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
            //����� �� �������
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gameOver = true;
            }

            //������������ ������ ��������
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
                        if (s == "� ������ ������")
                        {
                            for(int i = 0; i < 30; i++)
                            {
                                for(int j = 0; j < 30; j++)
                                {
                                    char ch = file1.get();
                                    dorogi[j][i] = (ch == '1');
                                }
                                file1.get();
                            }
                            getline(file1, s);
                        }
                        else if (s.length()  > 0)
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

            //������������ ����������
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
                            out << center[i].x << endl;
                            out << center[i].y << endl;
                            out << center[i].widthPic << endl;
                            out << center[i].heightPic << endl;
                            out << center[i].address << endl;
                        }
                    }

                    out << "� ������ ������" << endl;
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 0; j < 30; j++)
                            out << dorogi[j][i];
                        out << endl;
                    }
                    out.close();
                }
            }

            //��������� ����������� ��������
            drawCentralPictures(n_variants, center, center_x);

            //�������� ��������
            txSetFillColour(TX_GRAY);
            txRectangle(MAX_X,100,1532,MAX_Y);

            drawRightPictures(N_PICS, pic, category);
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
