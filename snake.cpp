// snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<time.h>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>
//��Ϸ�����б�
//1.̰�������������ƶ�
//2.̰���߳�ʳ�ﳤ��
//3.̰����ײǽ���Ե��Լ�GG
//4.��Ϸ��������ӡ�÷�

//�����ͼ�Ĵ�С

#define MAP_HEIGHT 20
#define MAP_WIDTH 60
void DrawChar(int x,int y,char ch)
{
	COORD pos;
	pos.X=x;
	pos.Y =y;
	//���ù��λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	putchar(ch);
}

typedef struct Position
{
	//x����
	int x;
	//y����
	int y;
}Position;

//̰���߽ṹ��
typedef struct Snake
{
	//̰���߳���
	int size;
	Position pos[MAP_WIDTH *MAP_HEIGHT];
}Snake;
Snake g_snake;

//ʳ��
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
	//һ��һ��
	for (int i=0;i<=MAP_HEIGHT;i++)
	{
		for(int j=0;j<=MAP_WIDTH;j++)
		{
			//�ұ߿�
			if(j==MAP_WIDTH)
			{
			printf("|\n");
			}
			else if (i==MAP_HEIGHT)
			{
				//�ױ�
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
	//���Ƶ�ͼ
	InitMap();
	InitSnake();
	InitFood();

}
void UpdateScreen()
{
	DrawSnake();
}

//w ��
//s ��
//a ��
//d ��
void SnakeMove(int key)
{
	int delta_x=0;
	int delta_y=0;
	



	if(key=='w'||key=='W')
	{
		delta_x=0;
		delta_y=-1;
	}
	else if (key=='s'||key=='s')
	{
		delta_x=0;
		delta_y=1;
	}
	else if (key=='a'||key=='A')
	{
		delta_x=-1;
		delta_y=0;
	}
	else if (key=='d'||key=='D')
	{
		delta_x=1;
		delta_y=0;
	}
	else
	{
		//��Ч����
		return;
	}
		//��һ���ڵ�=ǰһ���ڵ������
	//g_snake.size-1;���һ���ڵ������
	//i>0������ͷ�ڵ�
	DrawChar(g_snake.pos [g_snake.size -1].x ,g_snake.pos [g_snake.size -1].y ,' ');
	for(int i=g_snake.size -1;i>0;i--)
	{
		g_snake.pos[i].x=g_snake.pos[i-1].x ;
		g_snake.pos[i].y=g_snake.pos[i-1].y ; 
	      
	}
	g_snake.pos [0].x +=delta_x;
	g_snake.pos [0].y +=delta_y ;
}

//ͷ�ڵ��ʳ���������ͬ

void EatFood()
{
	if(g_snake.pos [0].x ==g_food.x &&g_snake.pos [0].y ==g_food.y )
	{
		g_snake.size++;
		//�¶���β�ڵ��ʳ�������һ��
		g_snake.pos [g_snake.size -1].x =g_food.x ;
		g_snake.pos [g_snake.size -1].y =g_food.y ;
		//InitFood();
	}
}

void GameLoop()
{
	int key=0;
	while(1)
	{
		//����������
		//����Ƿ��а�������
		if(_kbhit())
		{
			key=_getch();
		}
		if(key=='q'||key=='Q')
		{
		return;
		}
		//�����ƶ�̰����
		SnakeMove(key);
		//����ײǽ���¼�
		//���»���
		UpdateScreen();
		//��ʱ
		Sleep(100);
		
	}
}

void Score()
{
//��ӡ�÷�
}

int main(int argc, char* argv[])
{
	
//��ʼ��������ͼ
    Init();
//��Ϸ����ѭ��������������Ϸ������£�����ײǽ�¼�
    GameLoop();
//��ӡ�÷�
    Score();
	

	return 0;
}

