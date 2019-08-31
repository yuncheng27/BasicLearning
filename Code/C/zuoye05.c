#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>


//1.完成猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("****************************\n");
//	printf("***   1.play     0.exit  ***\n");
//	printf("****************************\n");
//}
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("please enter the number you guess:");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("guess large!\n");
//		}
//		else if (input < random_num)
//		{
//			printf("guess small!\n");
//		}
//		else
//		{
//			printf("congratulations!,you get it!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("please choose:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("choose error,please try again!\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}


//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 10,11,12,13,14,15,16,17,18,19 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int key = 18;
//	int mid = 0;
//	mid = bin_search(arr, left, right, key);
//	if (mid == -1)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了，下标是%d\n", mid);
//	}
//	system("pause");
//	return 0;
//}


//3.编写代码模拟三次密码输入的场景。最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
//int main()
//{
//	char psw[20] = "";
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < 3; ++i)
//	{
//		printf("please input:");
//		scanf("%s", psw);
//		if (strcmp(psw, "11223344") == 0)
//			break;
//	}
//	if (i == 3)
//	{
//		printf("exit\n");
//	}
//	else
//	{
//		printf("log in\n");
//	}
//	system("pause");
//}


//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
//int main()
//{
//	int i = 0;
//	char arr[1];
//	char code;
//	printf("please enter your code:");
//	scanf("%c", &code);
//	if (code <= 90)
//	{
//		if (code >= 65)
//		{
//			code = code + 32;
//			printf("%c\n", code);
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	else if (code >= 97)
//	{
//		if (code <= 122)
//		{
//			code = code - 32;
//			printf("%c\n", code);
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}