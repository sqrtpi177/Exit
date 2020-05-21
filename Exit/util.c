#include "util.h"

void init()//�ʱ�ȭ
{
    system("mode con cols=56 lines=20 | title EXIT");

    //Ŀ�� �����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

    setColor(white, black);
    //���� ����
    srand(time(NULL));
}//init()

void gotoxy(int x, int y)//Ŀ�� �̵�
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}//gotoxy(int x, int y)

void setColor(int forground, int background)//���� ����
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}//setColor(int forground, int background)
