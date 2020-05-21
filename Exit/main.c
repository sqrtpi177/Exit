#include "main.h"
#include "game.h"
#include "util.h"

int main()
{
    init();//초기화

    while (1)
    {
        drawTitle();//제목 그리기
        int menuCode = drawMenu();//메뉴가 값을 반환

        if (menuCode == 0)//게임시작
        {
            int n = drawMapList();//맵 리스트 그리기

            if (n == 0)//게임 시작(쉬운맵)
            {
                drawStory();
                gLoop(0);
            }
            else if (n == 1)//게임 시작(어려운맵)
            {
                gLoop(1);
            }
            else if (n == 2)
            {
                gLoop(2);
            }
        }
        else if (menuCode == 1) drawInfo();//조작방법
        else if (menuCode == 2) drawHelp();//도움말?
        else if (menuCode == 3) return 0;//종료
        system("cls");
        setColor(white, black);
    }
    return 0;
}//main()
