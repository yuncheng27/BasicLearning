#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', row*col * sizeof(char));
}

void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("%c  | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
		{
			printf("---|---|---\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("player step, ");
	while (1)
	{
		printf("please input coordinate: ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("coordinate occupied!\n");
			}
		}
		else
		{
			printf("coordinate illegal!\n");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("computer step:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

//static int check_full(char board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (board[i][j] != ' ')
//				return 0;
//		}
//	}
//	return 1;
//}

//char check_win(char board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][1] != ' ')
//		{
//			return board[i][0];
//		}
//	}
//	for (int i = 0; i < col; i++)
//	{
//		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[1][i] != ' ')
//		{
//			return board[0][i];
//		}
//	}
//	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
//	{
//		return board[0][0];
//	}
//	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && board[1][1] != ' ')
//	{
//		return board[2][0];
//	}
//	if (check_full(board, row, col))
//	{
//		return "q";
//	}
//	return ' ';
//}

char check_win(char board[ROW][COL], int row, int col)//ÅÐ¶ÏÊäÓ®
{
	int i = 0;
	for (i = 0; i<row; i++)
	{
		int j = 0;
		for (j = 0; j<col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1])
				break;
		}
		if (j == col - 1)
			return board[i][0];
	}
	for (i = 0; i<col; i++)
	{
		int j = 0;
		for (j = 0; j<row - 1; j++)
		{
			if (board[j][i] != board[j + 1][i])
				break;
		}
		if (j == row - 1)
			return board[0][i];
	}
	for (i = 0; i<row - 1; i++)
	{
		if (board[i][i] != board[i + 1][i + 1])
			break;
	}
	if (i == row - 1)
		return board[0][0];
	for (i = 0; i<row - 1; i++)
	{
		if (board[i][row - 1 - i] != board[i + 1][row - 1 - i - 1])
			break;
	}
	if (i == row - 1)
		return board[row - 1][0];
	for (i = 0; i<row; i++)
	{
		int j = 0;
		for (j = 0; j<col; j++)
		{
			if (board[i][j] == ' ')
				return ' ';
		}
	}
	return 'q';
}