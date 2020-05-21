#include "game.h"
#include "util.h"

//�� �迭
//0: �� ����, 1: ��, s: ����, f: ��, p: ��Ż ����, q: ��Ż ��, k: ����, d: ��� ��, m: ����, w: ���� t: ����, a: ��, b: ����, c: �ñر�

char tempMap[14][56];//�� �ӽ�����

//�������� 1
char map1[14][56] =
{
    {"11111111111111111111111111111111111111111111111111111111"},
    {"10000001w0000000001000001001000001a000000000000000000001"},
    {"10q01001111111110010011110010010011111111001111001111001"},
    {"100010000000000000100100t00100100000000000010c10010k1001"},
    {"11111111111110011110010010011m11111111111001001001001001"},
    {"100000000000100m0000000010010000000000001111001001001001"},
    {"10011111110011111110011110011111111111001000001001001001"},
    {"10010000000010000a100100000000k10000010011t1111001001001"},
    {"1001000111d110011110011111001111001000001000000001000001"},
    {"10k10001000010010000000001001000001001111001111111111111"},
    {"1111000100p01001111111100100100100100100100100000b000001"},
    {"10s0000100001000000000000100111100100100100100000100f001"},
    {"1000000100001000000000000100000d0010w100000d000001000001"},
    {"11111111111111111111111111111111111111111111111111111111"}
};//map1

//�������� 2
char map2[14][56] =
{
    {"11111111111111111111111111111111111111111111111111111111"},
    {"1000001q000000010000000k001000000001000000001a0100000001"},
    {"10m100111111110100111111001001111001001111001001001111m1"},
    {"1001001000000101001000000010010w10t10010w00010010c100001"},
    {"1m010010k00001010000011111100100100100100000101111100111"},
    {"10010011111001010000010k00m000001t01t11111000m0000000101"},
    {"10m100000010000d0010010000100000100100000100111100111101"},
    {"1k01000000111111111001111111111110t1001001001w0100001001"},
    {"111100100010a00000100m0000100100000100100100100111001001"},
    {"10000011111111100010010000d001001111001d110010000t000001"},
    {"1001001000000010001001000010010010a0001001001111111111b1"},
    {"10s100d000p0001000100111111001001111111001001000f0d00m01"},
    {"100100100000001000000t000w1000000000000001001000001000k1"},
    {"11111111111111111111111111111111111111111111111111111111"}
};//map2

//������
char map3[14][56] =
{
    {"11111111111111111111111111111111111111111111111111111111"},
    {"1k00b000d0010000000t0010q00000010k0000001000000000000001"},
    {"1000100010010001111000100000000100000000b0000000000000c1"},
    {"1111111010010001mc10001111111001111001111111111001111111"},
    {"100000101000000100100010000000010c10000010000000010000c1"},
    {"10010w00111111010m100010011110t10011110011b1111111001111"},
    {"100111111000a10100100010010k1001000000001001k00000001k01"},
    {"1000000010011101m0100010w1001t01111111001001111111101101"},
    {"11m111001000000100000011111m100100000000100k0000000d0001"},
    {"1000c100111111111111b110000000t1001111111111111111111d11"},
    {"11111100100000010000001001111111001000001t0001m000100001"},
    {"10s0000010p0000d000000100d00000000100f00d00t0b00m0db0001"},
    {"1000000010000001000k001001000000001000001t0001mc00100001"},
    {"11111111111111111111111111111111111111111111111111111111"}
};//map3

void gLoop(int mapCode)//���� ����
{
    int x, y;//�÷��̾� ��ǥ
    int stat = 0;
    int key = 0;//���� ����
    int playing = 1;//�÷��� ����
    int health = 3;//ü��
    int weapon = 0;//����
    int armor = 0;//��
    int skill = 0;//�ñر�

    //�� ����
    if (mapCode == 0) memcpy(tempMap, map1, sizeof(tempMap));
    else if (mapCode == 1) memcpy(tempMap, map2, sizeof(tempMap));
    else if (mapCode == 2) memcpy(tempMap, map3, sizeof(tempMap));
    drawMap(&x, &y);

    while (playing == 1)//���� ��
    {
        drawUI(&stat, &key, &health, &weapon, &armor, &skill);

        switch (keyControl())//Ű���� �Է� ó��
        {
        case UP:
            move(&x, &y, 0, -1, &stat, &key, &playing, &health, &weapon, &armor, &skill);
            break;

        case DOWN:
            move(&x, &y, 0, 1, &stat, &key, &playing, &health, &weapon, &armor, &skill);
            break;

        case LEFT:
            move(&x, &y, -1, 0, &stat, &key, &playing, &health, &weapon, &armor, &skill);
            break;

        case RIGHT:
            move(&x, &y, 1, 0, &stat, &key, &playing, &health, &weapon, &armor, &skill);
            break;

        case SUBMIT:
            playing = 3;//����� Game Clear �ߴ� �� ����
        }
    }
    if (playing == 0)//���� Ŭ����
    {
        setColor(white, black);
        gotoxy(22, 8);
        printf("Game Clear!");
        gotoxy(5, 15);
        printf("                ");
        gotoxy(5, 16);
        printf("Ż�� ����!    ");
        gotoxy(5, 17);
        printf("                ");
        Sleep(500);

        Beep(_CC, 75);
        Beep(_CC, 200);
        Sleep(1500);

        if (mapCode == 2) drawEnding();
    }
    else if (playing == 2)//���� ����
    {
        setColor(white, black);
        gotoxy(22, 8);
        printf("Game Over!");

        gotoxy(5, 15);
        printf("                ");
        gotoxy(5, 16);
        printf("Ż�� ����!    ");
        gotoxy(5, 17);
        printf("                ");
        Sleep(500);

        //music from Super Mario
        Beep(_UB, 100);
        Beep(_F, 75);
        Sleep(100);
        Sleep(200);
        Beep(_F, 100);
        Beep(_F, 100);
        Sleep(50);

        Beep(_E, 100);
        Beep(_D, 100);
        Sleep(100);
        Sleep(150);

        Beep(_C, 100);
        Sleep(50);
        Sleep(500);
    }
    //else if(playing == 3) �ܼ� ����
}//gLoop(int mapCode)

void move(int* x, int* y, int _x, int _y, int* stat, int* key, int* playing, int* health, int* weapon, int* armor, int* skill)//�̵� �Լ�
{
    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black);

    if (mapObject == '0')//�� ����
    {
        tempMap[*y][*x] = '0';
        gotoxy(*x, *y);
        printf(" ");

        tempMap[*y + _y][*x + _x] = 's';
        setColor(cyan, black);
        gotoxy(*x + _x, *y + _y);
        printf("@");

        *x += _x;
        *y += _y;
    }

    else if (mapObject == 'k')//����
    {
        *stat = 1;
        *key += 1;
        tempMap[*y + _y][*x + _x] = '0';
        gotoxy(*x + _x, *y + _y);
        printf(" ");
        Beep(_G, 100);
    }
    else if (mapObject == 'd')//��� ��
    {
        if (*key > 0)//���� ���������� üũ
        {
            *stat = 3;
            *key -= 1;
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
            Beep(_C, 100);
        }
        else *stat = 2;
    }

    else if (mapObject == 'p')//��Ż
    {
        *stat = 4;
        tempMap[*y][*x] = '0';
        setColor(white, black);
        gotoxy(*x, *y);
        printf(" ");

        int px, py;//��Ż ��ġ ã��
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 56; j++)
            {
                if (tempMap[i][j] == 'q')
                {
                    px = j;
                    py = i;
                }
            }
        }

        Beep(_C, 150);
        Beep(_D, 150);
        Beep(_E, 150);
        Sleep(300);

        tempMap[py][px + 1] = 's';
        setColor(cyan, black);
        gotoxy(px + 1, py);
        printf("@");

        *x = px + 1;
        *y = py;
    }

    else if (mapObject == 'w')
    {
        *stat = 5;
        *weapon += 1;//���� 1 ȹ��
        tempMap[*y + _y][*x + _x] = '0';
        gotoxy(*x + _x, *y + _y);
        setColor(white, black);
        printf(" ");
        Beep(_G, 100);
    }
    else if (mapObject == 'm')//����
    {
        if (*weapon > 0)//���Ⱑ ���� ��
        {
            *stat = 6;
            *weapon -= 1;//���� 1 �Ҹ�
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
            Beep(_CC, 75);
            Beep(_CC, 200);
        }
        else
        {
            *stat = 9;
            if (*health - 1 == 0) *playing = 2;//���� ���� ó��
            *health -= 1;//ü�� 1 ����
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
            Beep(_A, 100);
            Beep(_E, 100);
        }
    }

    else if (mapObject == 'a')//��
    {
        *stat = 7;
        *armor += 1;//�پ 1 ȹ��
        tempMap[*y + _y][*x + _x] = '0';
        setColor(white, black);
        gotoxy(*x + _x, *y + _y);
        printf(" ");
        Beep(_G, 100);

    }
    else if (mapObject == 't')//����
    {
        if (*armor > 0)//���� ���� ��
        {
            *stat = 8;
            *armor -= 1;//�� 1 �Ҹ�
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
            Beep(_CC, 100);
            Beep(_CC, 100);
        }
        else
        {
            *stat = 9;
            if (*health - 1 == 0) *playing = 2;//���� ���� ó��
            *health -= 1;//ü�� 1 ����
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
            Beep(_A, 100);
            Beep(_E, 100);
        }
    }

    else if (mapObject == 'c')//�ñر�
    {
        *stat = 10;
        *skill += 1;//�ñر� ȹ��
        tempMap[*y + _y][*x + _x] = '0';
        setColor(white, black);
        gotoxy(*x + _x, *y + _y);
        printf(" ");
        Beep(_G, 100);
        Beep(_G, 100);
    }
    else if (mapObject == 'b')//����
    {
        for (int c = 0; c < 3; c++)
        {
            int pcol = 0, bcol = 0;
            pcol = rand() % 15 + 1;//������ ���� ���� +1
            bcol = rand() % 15 + 1;//������ ���� ���� +1

            setColor(pcol, black);
            gotoxy(*x, *y);
            printf("?");

            setColor(bcol, black);
            gotoxy(*x + _x, *y + _y);
            printf("?");

            Beep(_G, 100);
            setColor(white, black);
            Sleep(1000);
        }

        if (*skill == 1)//�ñر� ����
        {
            *stat = 11;
            *skill -= 1;
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf("-");

            setColor(cyan, black);
            gotoxy(*x, *y);
            printf("@");

            Beep(_CC, 75);
            Beep(_CC, 200);
        }
        else *playing = 2;//���� ���� ó��
    }
    else if (mapObject == 'f') *playing = 0;//�� ��Ż: ���� Ŭ���� ó��
}//move(int* x, int* y, int _x, int _y, int* key, int* playing)

int keyControl()//Ű���� �̺�Ʈ ó��
{
    char temp = _getch();//Ű���� �Է�
    if (temp == 'w' || temp == 'W') return UP;
    else if (temp == 'a' || temp == 'A') return LEFT;
    else if (temp == 's' || temp == 'S') return DOWN;
    else if (temp == 'd' || temp == 'D') return RIGHT;
    else if (temp == ' ') return SUBMIT;
}//keyControl()

void drawTitle()//���� �׸���
{
    printf("\n\n\n\n");
    printf("              #####   #   #   #####   #####\n");
    printf("              #        # #      #       #  \n");
    printf("              #####     #       #       #  \n");
    printf("              #        # #      #       #  \n");
    printf("              #####   #   #   #####     #  \n");
}//drawTitle()

int drawMenu()//�޴� �׸���
{
    int x = 24, y = 12;
    setColor(white, black);

    gotoxy(x - 2, y);//x-2�� ����: Ŀ��
    printf("> ���ӽ���");
    gotoxy(x, y + 1);
    printf("���۹��");
    gotoxy(x, y + 2);
    printf("����?");
    gotoxy(x, y + 3);
    printf("  ���� ");

    //Ŀ�� �̵� ó��
    while (1)
    {
        int n = keyControl();//Ű���� �Է�
        switch (n)
        {
        case UP:
            if (y > 12)//y: 12~15
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
                Beep(_C, 100);
            }
            break;

        case DOWN:
            if (y < 15)//y: 12~15
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
                Beep(_C, 100);
            }
            break;

        case SUBMIT:
            Beep(_G, 100);
            return y - 12;// 0, 1, 2, 3 ��ȯ
        }
    }
}//drawMenu()

int drawMapList()//�� ����Ʈ �׸���
{
    int x = 20, y = 9;
    system("cls");
    setColor(white, black);

    printf("\n\n\n\n\n");
    printf("                        [�� ����]\n\n");

    gotoxy(x - 2, y);//x-2�� ����: Ŀ��
    printf("> 1. ������ �̷�");
    gotoxy(x, y + 2);
    printf("2. Ȳȥ�� ���");
    gotoxy(x, y + 4);
    printf("3. ������ ���");
    gotoxy(x, y + 6);
    printf("     �ڷ�");

    while (1)
    {
        int n = keyControl();//Ű���� �Է�
        switch (n)
        {
        case UP:
            if (y > 9)//y: 9~16
            {
                gotoxy(x - 2, y);
                printf(" ");
                y -= 2;
                gotoxy(x - 2, y);
                printf(">");
                Beep(_C, 100);
            }
            break;

        case DOWN:
            if (y < 16)//y: 9~16
            {
                gotoxy(x - 2, y);
                printf(" ");
                y += 2;
                gotoxy(x - 2, y);
                printf(">");
                Beep(_C, 100);
            }
            break;

        case SUBMIT:
            Beep(_G, 100);
            return (y - 9) / 2;//0, 1, 2, 3 ��ȯ
        }
    }
}//drawMapList()

void drawStory()
{
    while (1)
    {
        system("cls");
        gotoxy(3, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(10, 7);
        setColor(white, black);
        printf("���Ⱑ �����?");

        if (keyControl() == SUBMIT) break;
    }
    Beep(_A, 200);
    Beep(_A, 200);
    while (1)
    {

        for (int i = 0; i < 11; i++)
        {
            if (i % 2 == 0)
            {
                system("cls");
                gotoxy(5, 12);
                setColor(lightred, black);
                printf("X");

                gotoxy(3, 10);
                setColor(lightred, black);
                printf("Y");

                gotoxy(3, 12);
                setColor(cyan, black);
                printf("@");

                gotoxy(10, 7);
                setColor(lightred, black);
                printf("����!!!");

                Sleep(100);
            }
            else
            {
                system("cls");
                gotoxy(7, 12);
                setColor(lightred, black);
                printf("X");

                gotoxy(5, 10);
                setColor(lightred, black);
                printf("Y");

                gotoxy(5, 12);
                setColor(cyan, black);
                printf("@");

                gotoxy(10, 7);
                setColor(lightred, black);
                printf("����!!!");

                Sleep(100);
            }

        }

        if (keyControl() == SUBMIT) break;
    }
    while (1)
    {
        system("cls");
        gotoxy(5, 12);
        setColor(lightred, black);
        printf("X");

        gotoxy(3, 10);
        setColor(lightred, black);
        printf("Y");

        gotoxy(1, 12);
        setColor(lightgray, black);
        printf("X");

        gotoxy(3, 14);
        setColor(lightgray, black);
        printf("Y");

        gotoxy(3, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(10, 7);
        setColor(white, black);
        printf("�׷�...���ʿ� ����(X)�� ��(Y)�� �־�...");

        if (keyControl() == SUBMIT) break;
    }
    while (1)
    {
        system("cls");
        gotoxy(3, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(10, 7);
        setColor(white, black);
        printf("���� �̰��� �����߰ھ�...");

        if (keyControl() == SUBMIT) break;
    }
}//drawStory()

void drawEnding()
{
    //ù ȭ��
    system("cls");
    //�� �׸���
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    gotoxy(3, 12);
    setColor(cyan, black);
    printf("@");
    gotoxy(10, 6);
    setColor(white, black);
    printf("���� ���ΰ�?");
    _getch();

    //�ι�° ȭ��
    system("cls");
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    gotoxy(3, 12);
    setColor(cyan, black);
    printf("@");
    gotoxy(7, 12);
    setColor(lightred, black);
    printf("T");
    gotoxy(10, 6);
    setColor(white, black);
    printf("���!");
    _getch();

    //����° ȭ��
    while (1)
    {
        system("cls");
        for (int x = 1; x < 52; x++)
        {
            gotoxy(x, 10);
            if (x % 10 == 3) setColor(yellow, black);
            else setColor(white, white);
            printf("#");
        }
        for (int x = 1; x < 52; x++)
        {
            gotoxy(x, 14);
            if (x % 10 == 3) setColor(yellow, black);
            else setColor(white, white);
            printf("#");
        }
        gotoxy(3, 12);
        setColor(cyan, black);
        printf("@");
        gotoxy(7, 12);
        setColor(lightred, black);
        printf("T");
        gotoxy(10, 6);
        setColor(white, black);
        printf("��ȣ�� ���! ��ȣ�� 1234�̴�.");
        gotoxy(10, 7);
        printf("�Է������� ���͸� ������.");
        gotoxy(10, 8);
        char pass[20];
        scanf("%s", pass);

        if (strcmp(pass, "1234") == 0) break;//��й�ȣ ��ġ
        else//��й�ȣ ����ġ
        {
            gotoxy(10, 12);
            printf("Ʋ�ȴ�! ��ȣ�� 1234�̴�.");
            Sleep(1000);
        }
    }

    //�׹�° ȭ��
    system("cls");
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }

    gotoxy(3, 12);
    setColor(cyan, black);
    printf("@");

    gotoxy(7, 12);
    setColor(lightred, black);
    printf("T");

    gotoxy(10, 6);
    setColor(white, black);
    printf("ũ��...��ȣ�� �˾Ƴ��ٴ�...");
    gotoxy(10, 7);
    printf("��¿ �� ������ �����ְڴ�.");
    _getch();

    //�ټ���° ȭ��(�̵�)
    system("cls");
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(yellow, black);
        else setColor(white, white);
        printf("#");
    }
    for (int i = 3; i < 52; i++)
    {
        gotoxy(i, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(i - 1, 12);
        setColor(white, black);
        printf(" ");
        Sleep(75);
    }

    //������° ȭ��(�̵�)
    system("cls");
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(lightblue, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(lightblue, black);
        else setColor(white, white);
        printf("#");
    }
    for (int i = 3; i < 52; i++)
    {
        gotoxy(i, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(i - 1, 12);
        setColor(white, black);
        printf(" ");
        Sleep(75);
    }

    //�ϰ���° ȭ��(�̵�)
    system("cls");
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 10);
        if (x % 10 == 3) setColor(lightred, black);
        else setColor(white, white);
        printf("#");
    }
    for (int x = 1; x < 52; x++)
    {
        gotoxy(x, 14);
        if (x % 10 == 3) setColor(lightred, black);
        else setColor(white, white);
        printf("#");
    }
    for (int i = 3; i < 52; i++)
    {
        gotoxy(i, 12);
        setColor(cyan, black);
        printf("@");

        gotoxy(i - 1, 12);
        setColor(white, black);
        printf(" ");
        Sleep(75);
    }

    //������° ȭ��(���� �̵�)
    system("cls");
    for (int y = 1; y < 18; y++)
    {
        gotoxy(26, y);
        if (y % 5 == 3) setColor(lightred, black);
        else setColor(white, white);
        printf("#");
    }
    for (int y = 1; y < 18; y++)
    {
        gotoxy(30, y);
        if (y % 5 == 3) setColor(lightred, black);
        else setColor(white, white);
        printf("#");
    }
    for (int i = 17; i > 0; i--)
    {
        gotoxy(28, i);
        setColor(cyan, black);
        printf("@");

        gotoxy(28, i + 1);
        setColor(white, black);
        printf(" ");
        Sleep(75);
    }

    //������ ȭ��(THE END)
    Sleep(500);
    Beep(_CC, 75);
    Beep(_CC, 200);
    while (1)
    {
        system("cls");
        setColor(white, black);
        printf("\n\n\n");
        printf("     #####   #   #   #####     #####   #   #   ###\n");
        printf("       #     #   #   #         #       ##  #   #  #\n");
        printf("       #     #####   #####     #####   # # #   #   #\n");
        printf("       #     #   #   #         #       #  ##   #  #\n");
        printf("       #     #   #   #####     #####   #   #   ###\n");

        printf("\n\n\n\n\n\n\n");

        printf("                          ");
        setColor(cyan, black);
        printf("@\n");

        setColor(white, black);
        printf(" ##   ##   ##  ##   ##   ##   ##   ##   ##   ##     ## \n");
        printf(" ##################################################### \n");

        //�Ķ�
        setColor(lightblue, black);
        gotoxy(25, 13);
        printf("####");
        gotoxy(23, 14);
        printf("##");
        gotoxy(29, 14);
        printf("##");
        gotoxy(21, 15);
        printf("##");
        gotoxy(31, 15);
        printf("##");

        //�ʷ�
        setColor(lightgreen, black);
        gotoxy(24, 12);
        printf("######");
        gotoxy(22, 13);
        printf("###");
        gotoxy(29, 13);
        printf("###");
        gotoxy(21, 14);
        printf("##");
        gotoxy(31, 14);
        printf("##");
        gotoxy(20, 15);
        printf("##");
        gotoxy(32, 15);
        printf("##");

        //���
        setColor(yellow, black);
        gotoxy(22, 11);
        printf("##########");
        gotoxy(20, 12);
        printf("####");
        gotoxy(30, 12);
        printf("####");
        gotoxy(19, 13);
        printf("###");
        gotoxy(32, 13);
        printf("###");
        gotoxy(18, 14);
        printf("###");
        gotoxy(33, 14);
        printf("###");
        gotoxy(17, 15);
        printf("###");
        gotoxy(34, 15);
        printf("###");

        //����
        setColor(lightred, black);
        gotoxy(20, 10);
        printf("##############");
        gotoxy(18, 11);
        printf("####");
        gotoxy(32, 11);
        printf("####");
        gotoxy(16, 12);
        printf("####");
        gotoxy(34, 12);
        printf("####");
        gotoxy(15, 13);
        printf("####");
        gotoxy(35, 13);
        printf("####");
        gotoxy(14, 14);
        printf("####");
        gotoxy(36, 14);
        printf("####");
        gotoxy(14, 15);
        printf("###");
        gotoxy(37, 15);
        printf("###");
        if (keyControl() == SUBMIT) break;
    }
}//drawEnding()

void drawInfo()//���� �׸���
{
    system("cls");
    setColor(white, black);

    printf("\n\n\n\n\n");
    printf("                        [���۹�]\n\n\n");
    printf("                    �̵�: W, A, S, D\n\n");
    printf("            ����, ����ȭ�� �̵�: �����̽���\n\n\n\n\n");

    printf("     �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

    while (1)
    {
        if (keyControl() == SUBMIT)
        {
            Beep(_G, 100);
            break;
        }
    }
}//drawInfo()

void drawHelp()//���� �׸���
{
    system("cls");
    setColor(white, black);

    printf("\n\n");
    printf("                        [����]\n\n");
    printf("           Exit�� �̷θ� Ż���ϴ� �����Դϴ�.\n");
    printf("  ����� ���� ���� ����� ���͸� � ���� ����\n");
    printf("  ���� ������ ������ ����������. ü���� 3�� �־�����\n");
    printf("  ���������� ������ ��ٸ��� �ֽ��ϴ�.\n\n");

    //�� �߰��� ���� �� ���
    //����, ��� ��
    printf("                   ");
    setColor(yellow, black);
    printf("*");
    setColor(white, black);
    printf(", ");
    setColor(brown, black);
    printf("+");
    setColor(white, black);
    printf(": ����, ���� ��\n");

    //�̵� ��Ż
    printf("                   ");
    setColor(lightblue, black);
    printf("0");
    setColor(white, black);
    printf(", ");
    setColor(yellow, black);
    printf("0");
    setColor(white, black);
    printf(": �̵� ��Ż\n");

    //����, ����
    printf("                   ");
    setColor(lightgray, black);
    printf("X");
    setColor(white, black);
    printf(", ");
    setColor(lightred, black);
    printf("X");
    setColor(white, black);
    printf(": ����, ����\n");

    //��, ����
    printf("                   ");
    setColor(lightgray, black);
    printf("Y");
    setColor(white, black);
    printf(", ");
    setColor(lightred, black);
    printf("Y");
    setColor(white, black);
    printf(": ��, ����\n");

    //�ñر�, ����
    printf("                   ");
    setColor(lightpurple, black);
    printf("!");
    setColor(white, black);
    printf(", ");
    setColor(lightred, cyan);
    printf("T");
    setColor(white, black);
    printf(": �ñر�, ����\n");

    //�÷��̾�
    printf("                   ");
    setColor(cyan, black);
    printf("@");
    setColor(white, black);
    printf(": �÷��̾�\n");

    //�� ��Ż
    printf("                   ");
    setColor(lightgreen, black);
    printf("0");
    setColor(white, black);
    printf(": �� ��Ż\n\n");

    printf("      �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

    while (1)
    {
        if (keyControl() == SUBMIT)
        {
            Beep(_G, 100);
            break;
        }
    }
}//drawHelp()


void drawMap(int* x, int* y)//�� �׸���
{
    int h, w;
    system("cls");

    for (h = 0; h < 14; h++)
    {
        for (w = 0; w < 56; w++)
        {
            char temp = tempMap[h][w];

            if (temp == '0')//�� ����
            {
                setColor(black, black);
                printf(" ");
            }
            else if (temp == '1')//��
            {
                setColor(white, white);
                printf("#");
            }
            else if (temp == 's')//����(�÷��̾�)
            {
                *x = w;
                *y = h;
                setColor(cyan, black);
                printf("@");
            }
            else if (temp == 'f')//�� ��Ż
            {
                setColor(lightgreen, black);
                printf("0");
            }
            else if (temp == 'k')//����
            {
                setColor(yellow, black);
                printf("*");
            }
            else if (temp == 'd')//��� ��
            {
                setColor(brown, black);
                printf("+");
            }
            else if (temp == 'p')//��Ż ����
            {
                setColor(lightblue, black);
                printf("0");
            }
            else if (temp == 'q')//��Ż ��
            {
                setColor(yellow, black);
                printf("0");
            }
            else if (temp == 'm')//����
            {
                setColor(lightred, black);
                printf("X");
            }
            else if (temp == 'w')//����
            {
                setColor(lightgray, black);
                printf("X");
            }
            else if (temp == 't')//����
            {
                setColor(lightred, black);
                printf("Y");
            }
            else if (temp == 'a')//��
            {
                setColor(lightgray, black);
                printf("Y");
            }
            else if (temp == 'b')//����
            {
                setColor(lightred, cyan);
                printf("T");
            }
            else if (temp == 'c')//�ñر�
            {
                setColor(lightpurple, black);
                printf("!");
            }
        }
        printf("\n");//����
    }
    setColor(white, black);
}//drawMap(int* x, int* y)

void drawUI(int* stat, int* key, int* health, int* weapon, int* armor, int* skill)//UI �׸���
{
    setColor(white, black);
    //����â �����
    gotoxy(5, 15);
    printf("                ");
    gotoxy(5, 16);
    printf("                ");
    gotoxy(5, 17);
    printf("                ");

    gotoxy(5, 16);
    if (*stat == 0) printf("���Ⱑ �����?");

    else if (*stat == 1) printf("���� ȹ��!    ");
    else if (*stat == 2) printf("���谡 ����.  ");
    else if (*stat == 3) printf("���� ������!   ");

    else if (*stat == 4) printf("�̵� �Ϸ�!    ");

    else if (*stat == 5) printf("���� ȹ��!    ");
    else if (*stat == 6) printf("���� óġ!   ");
    else if (*stat == 7) printf("�� ȹ��!   ");
    else if (*stat == 8) printf("���� ���!    ");
    else if (*stat == 9) printf("�ƾ�!       ");

    else if (*stat == 10)
    {
        gotoxy(5, 15);
        printf("�ñر� ȹ��!   ");
        gotoxy(5, 16);
        printf("���� ������    ");
        gotoxy(5, 17);
        printf("�ο� �� �־�!  ");
    }

    else if (*stat == 11) printf("���� óġ!    ");

    //ü�� ���
    setColor(lightred, black);
    gotoxy(22, 15);
    printf("ü��: %d", *health);

    //���� ���� ���
    setColor(lightgray, black);
    gotoxy(22, 16);
    printf("����: %d", *weapon);

    //�� ���� ���
    setColor(lightgray, black);
    gotoxy(22, 17);
    printf("��: %d", *armor);

    //���� ���� ���
    setColor(yellow, black);
    gotoxy(36, 16);
    printf("����: %d��", *key);

    //�ñر� ���� ���
    setColor(lightpurple, black);
    gotoxy(36, 17);
    if (*skill == 1) printf("�ñر�: ����");
    else printf("�ñر�: ����");
}//drawUI(int* key, int* health, int* weapon, int* armor, int* skill)
