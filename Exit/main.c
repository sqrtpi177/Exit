#include "main.h"
#include "game.h"
#include "util.h"

int main()
{
    init();//�ʱ�ȭ

    while (1)
    {
        drawTitle();//���� �׸���
        int menuCode = drawMenu();//�޴��� ���� ��ȯ

        if (menuCode == 0)//���ӽ���
        {
            int n = drawMapList();//�� ����Ʈ �׸���

            if (n == 0)//���� ����(�����)
            {
                drawStory();
                gLoop(0);
            }
            else if (n == 1)//���� ����(������)
            {
                gLoop(1);
            }
            else if (n == 2)
            {
                gLoop(2);
            }
        }
        else if (menuCode == 1) drawInfo();//���۹��
        else if (menuCode == 2) drawHelp();//����?
        else if (menuCode == 3) return 0;//����
        system("cls");
        setColor(white, black);
    }
    return 0;
}//main()
