#include "main.h"
#pragma warning(disable:4996)

#ifndef KEY_CODE
#define KEY_CODE

//매크로 정의
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#endif // KEY_CODE

#ifndef SND_CODE
#define SND_CODE

#define _UB 493.8833

#define _C 523.2511
#define _D 587.3295
#define _E 659.2511
#define _F 698.4565
#define _G 783.9909
#define _A 880.0000
#define _B 987.7666

#define _CC 1046.502


#endif // SND_CODE

//맵 배열 선언
char map[14][56];

//함수 선언
void gLoop(int);
void move(int*, int*, int, int, int*, int*, int*, int*, int*, int*, int*);
int keyControl();
void drawTitle();
int drawMenu();
int drawMapList();
void drawStory();
void drawEnding();
void drawInfo();
void drawHelp();
void drawMap(int*, int*);
void drawUI(int*, int*, int*, int*, int*, int*);
