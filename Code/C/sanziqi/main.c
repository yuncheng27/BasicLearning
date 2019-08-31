#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("****** 1.begin  0.exit ******\n");
	printf("*****************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);

	while (1)
	{
		player_move(board, ROW, COL);
		ret = check_win(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		display_board(board, ROW, COL);
		computer_move(board, ROW, COL);
		ret = check_win(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		display_board(board, ROW, COL);
	}

	if (ret == 'X')
	{
		printf("you win!\n");
		display_board(board, ROW, COL);
	}
	else if (ret == '0')
	{
		printf("you lose!\n");
		display_board(board, ROW, COL);
	}
	else if (ret == 'q')
	{
		printf("Dogfall!\n");
		display_board(board, ROW, COL);
	}
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("please choose: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit game.\n");
			break;
		default:
			printf("choose false!\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}