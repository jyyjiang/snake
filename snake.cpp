// snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<time.h>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>
//游戏功能列表
//1.贪吃蛇上下左右移动
//2.贪吃蛇吃食物长大
//3.贪吃蛇撞墙，吃到自己GG
//4.游戏结束，打印得分

//定义地图的大小

#define MAP_HEIGHT 20
#define MAP_WIDTH 60
void DrawChar(int x,int y,char ch)
{
	COORD pos;
	pos.X=x;
	pos.Y =y;
	//设置光标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	putchar(ch);
}

typedef struct Position
{
	//x坐标
	int x;
	//y坐标
	int y;
}Position;

//贪吃蛇结构体
typedef struct Snake
{
	//贪吃蛇长度
	int size;
	Position pos[MAP_WIDTH *MAP_HEIGHT];
}Snake;
Snake g_snake;

//食物
Position g_food;

void InitFood()
{
	srand((unsigned)time( NULL ));
	g_food.x =rand()%MAP_WIDTH;
	g_food.y =rand()%MAP_HEIGHT;

	DrawChar(g_food.x,g_food.y ,'#');
}

void InitSnake()
{
	g_snake.size=2;
	g_snake.pos[0].x=MAP_WIDTH/2;
    g_snake.pos[0].y=MAP_HEIGHT/2;

	g_snake.pos[1].x=MAP_WIDTH/2-1;
	g_snake.pos[1].y=MAP_HEIGHT/2;

	g_snake.pos[2].x=MAP_WIDTH/2-2;
	g_snake.pos[2].y=MAP_HEIGHT/2;

}

void DrawSnake()
{
	for(int i=0;i<g_snake.size;i++)
	{
		if(i==0)
		{
			DrawChar(g_snake.pos[i].x,g_snake.pos[i].y,'*');
		}
		else
		{
			DrawChar(g_snake.pos[i].x,g_snake.pos[i].y,'#');
		}
	}
}


void InitMap()
{
	//一行一行
	for (int i=0;i<=MAP_HEIGHT;i++)
	{
		for(int j=0;j<=MAP_WIDTH;j++)
		{
			//右边框
			if(j==MAP_WIDTH)
			{
			printf("|\n");
			}
			else if (i==MAP_HEIGHT)
			{
				//底边
				printf("_");
			
			}
			else
			{
				printf(" ");
			}
		}
	}
}

void Init()
{
	//绘制地图
	InitMap();
	InitSnake();

}
void UpdateScreen()
{
	DrawSnake();
}
void GameLoop()
{
	int key=0;
	while(1)
	{
		//处理按键输入
		//检测是否有按键输入
		if(_kbhit())
		{
			key=_getch();
		}
		if(key=='q'||key=='Q')
		{
		return;
		}
		//处理撞墙等事件
		//更新画面
		UpdateScreen();
		//延时
		Sleep(100);
		
	}
}

void Score()
{
//打印得分
}

int main(int argc, char* argv[])
{
//初始化，画地图
    Init();
//游戏的主循环，按键处理，游戏画面更新，吃力撞墙事件
    GameLoop();
//打印得分
    Score();

	return 0;
}

