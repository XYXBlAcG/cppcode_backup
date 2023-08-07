#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ROW 22 //?????
#define COL 42 //?????

#define KONG 0 //???(?????)
#define WALL 1 //???
#define FOOD 2 //????
#define HEAD 3 //????
#define BODY 4 //????

#define UP 72 //???:?
#define DOWN 80 //???:?
#define LEFT 75 //???:?
#define RIGHT 77 //???:?
#define SPACE 32 //??
#define ESC 27 //??

//??
struct Snake
{
	int len; //??????
	int x; //?????
	int y; //?????
}snake;

//??
struct Body
{
	int x; //?????
	int y; //?????
}body[ROW*COL]; //??????????????

int face[ROW][COL]; //????????????

//????
void HideCursor();
//????
void CursorJump(int x, int y);
//?????
void InitInterface();
//????
void color(int c);
//????????
void ReadGrade();
//????????
void WriteGrade();
//????
void InitSnake();
//??????
void RandFood();
//???????
void JudgeFunc(int x, int y);
//???????
void DrawSnake(int flag);
//???
void MoveSnake(int x, int y);
//????
void run(int x, int y);
//????????
void Game();

int max, grade; //????
int main()
{
#pragma warning (disable:4996) //????
	max = 0, grade = 0; //?????
	system("title ???"); //??cmd?????
	system("mode con cols=84 lines=23"); //??cmd?????
	HideCursor(); //????
	ReadGrade(); //?????????max??
	InitInterface(); //?????
	InitSnake(); //????
	srand((unsigned int)time(NULL)); //?????????
	RandFood(); //??????
	DrawSnake(1); //???
	Game(); //????
	return 0;
}

//????
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //????????????
	curInfo.dwSize = 1; //???????,??????
	curInfo.bVisible = FALSE; //?????????
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //???????
	SetConsoleCursorInfo(handle, &curInfo); //??????
}
//????
void CursorJump(int x, int y)
{
	COORD pos; //????????????
	pos.X = x; //???
	pos.Y = y; //???
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //???????
	SetConsoleCursorPosition(handle, pos); //??????
}
//?????
void InitInterface()
{
	color(6); //????????
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL; //???????
				CursorJump(2 * j, i);
				printf("�");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL; //???????
				printf("�");
			}
			else
			{
				face[i][j] = KONG; //???????
			}
		}
	}
	color(7); //???????
	CursorJump(0, ROW);
	printf("????:%d", grade);
	CursorJump(COL, ROW);
	printf("??????:%d", max);
}
//????
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //????
	//?:SetConsoleTextAttribute???API(????????)
}
//????????
void ReadGrade()
{
	FILE* pf = fopen("?????????.txt", "r"); //??????????
	if (pf == NULL) //??????
	{
		pf = fopen("?????????.txt", "w"); //??????????
		fwrite(&max, sizeof(int), 1, pf); //?max????(??max?0),??????????0
	}
	fseek(pf, 0, SEEK_SET); //?????pf??????
	fread(&max, sizeof(int), 1, pf); //????????????max??
	fclose(pf); //????
	pf = NULL; //????????
}
//????????
void WriteGrade()
{
	FILE* pf = fopen("?????????.txt", "w"); //??????????
	if (pf == NULL) //??????
	{
		printf("??????????\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf); //?????????????
	fclose(pf); //????
	pf = NULL; //????????
}
//????
void InitSnake()
{
	snake.len = 2; //??????????2
	snake.x = COL / 2; //????????
	snake.y = ROW / 2; //????????
	//????????
	body[0].x = COL / 2 - 1;
	body[0].y = ROW / 2;
	body[1].x = COL / 2 - 2;
	body[1].y = ROW / 2;
	//????????????
	face[snake.y][snake.x] = HEAD;
	face[body[0].y][body[0].x] = BODY;
	face[body[1].y][body[1].x] = BODY;
}
//??????
void RandFood()
{
	int i, j;
	do
	{
		//???????????
		i = rand() % ROW;
		j = rand() % COL;
	} while (face[i][j] != KONG); //???????????,?????????
	face[i][j] = FOOD; //?????????
	color(12); //???????
	CursorJump(2 * j, i); //?????????????
	printf("?"); //????
}
//???????
void JudgeFunc(int x, int y)
{
	//?????????????,???
	if (face[snake.y + y][snake.x + x] == FOOD)
	{
		snake.len++; //????
		grade += 10; //??????
		color(7); //???????
		CursorJump(0, ROW);
		printf("????:%d", grade); //????????
		RandFood(); //????????
	}
	//????????????????,?????
	else if (face[snake.y + y][snake.x + x] == WALL || face[snake.y + y][snake.x + x] == BODY)
	{
		Sleep(1000); //????????
		system("cls"); //????
		color(7); //???????
		CursorJump(2 * (COL / 3), ROW / 2 - 3);
		if (grade > max)
		{
			printf("?????????,???????%d", grade);
			WriteGrade();
		}
		else if (grade == max)
		{
			printf("???????,??????", grade);
		}
		else
		{
			printf("?????,?????????%d", max - grade);
		}
		CursorJump(2 * (COL / 3), ROW / 2);
		printf("GAME OVER");
		while (1) //??????????
		{
			char ch;
			CursorJump(2 * (COL / 3), ROW / 2 + 3);
			printf("?????(y/n):");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				system("cls");
				main();
			}
			else if (ch == 'n' || ch == 'N')
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				exit(0);
			}
			else
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				printf("????,?????");
			}
		}
	}
}
//???????
void DrawSnake(int flag)
{
	if (flag == 1) //???
	{
		color(10); //???????
		CursorJump(2 * snake.x, snake.y);
		printf("�"); //????
		for (int i = 0; i < snake.len; i++)
		{
			CursorJump(2 * body[i].x, body[i].y);
			printf("?"); //????
		}
	}
	else //???
	{
		if (body[snake.len - 1].x != 0) //??len++??(0, 0)??????
		{
			//??????????
			CursorJump(2 * body[snake.len - 1].x, body[snake.len - 1].y);
			printf("  ");
		}
	}
}
//???
void MoveSnake(int x, int y)
{
	DrawSnake(0); //??????????
	face[body[snake.len - 1].y][body[snake.len - 1].x] = KONG; //????????????
	face[snake.y][snake.x] = BODY; //?????????????
	//????????????????
	for (int i = snake.len - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	//?????????????0????????
	body[0].x = snake.x;
	body[0].y = snake.y;
	//???????
	snake.x = snake.x + x;
	snake.y = snake.y + y;
	DrawSnake(1); //???????
}
//????
void run(int x, int y)
{
	int t = 0;
	while (1)
	{
		if (t == 0)
			t = 3000; //??t??,???????(???????????)
		while (--t)
		{
			if (kbhit() != 0) //??????,?????
				break;
		}
		if (t == 0) //??????
		{
			JudgeFunc(x, y); //????????,?????????
			MoveSnake(x, y); //???
		}
		else //?????
		{
			break; //??Game??????
		}
	}
}
//????????
void Game()
{
	int n = RIGHT; //?????,??????
	int tmp = 0; //????????
	goto first; //???????????????
	while (1)
	{
		n = getch(); //????
		//????,?????????????
		switch (n)
		{
		case UP:
		case DOWN: //??????�?�?�?�
			if (tmp != LEFT&&tmp != RIGHT) //?????????????�?�?�?�
			{
				n = tmp; //???????????????????????
			}
			break;
		case LEFT:
		case RIGHT: //??????�?�?�?�
			if (tmp != UP&&tmp != DOWN) //?????????????�?�?�?�
			{
				n = tmp; //???????????????????????
			}
		case SPACE:
		case ESC:
		case 'r':
		case 'R':
			break; //???????
		default:
			n = tmp; //?????,????????????
			break;
		}
	first: //???????????????
		switch (n)
		{
		case UP: //???:?
			run(0, -1); //????(??????0,??????-1)
			tmp = UP; //??????????
			break;
		case DOWN: //???:?
			run(0, 1); //????(??????0,??????1)
			tmp = DOWN; //??????????
			break;
		case LEFT: //???:?
			run(-1, 0); //????(??????-1,??????0)
			tmp = LEFT; //??????????
			break;
		case RIGHT: //???:?
			run(1, 0); //????(??????1,??????0)
			tmp = RIGHT; //??????????
			break;
		case SPACE: //??
			system("pause>nul"); //?????????
			break;
		case ESC: //??
			system("cls"); //????
			color(7); //???????
			CursorJump(COL - 8, ROW / 2);
			printf("  ????  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		case 'r':
		case 'R': //????
			system("cls"); //????
			main(); //???????
		}
	}
}