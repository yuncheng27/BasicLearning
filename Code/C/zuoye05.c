#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>


//1.��ɲ�������Ϸ
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


//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
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
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±���%d\n", mid);
//	}
//	system("pause");
//	return 0;
//}


//3.��д����ģ��������������ĳ���������������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
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


//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
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