#include "util.h"

void init()//초기화
{
    system("mode con cols=56 lines=20 | title EXIT");

    //커서 지우기
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

    setColor(white, black);
    //난수 정의
    srand(time(NULL));
}//init()

void gotoxy(int x, int y)//커서 이동
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}//gotoxy(int x, int y)

void setColor(int forground, int background)//색깔 지정
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}//setColor(int forground, int background)
