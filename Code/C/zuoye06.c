#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//2.��д���룬��ʾ����ַ��������ƶ������м���(P37)
//int main()
//{
//	char arr1[] = "welcome to lua's blog!";
//	char arr2[] = "######################";
//	int start = 0;
//	int end = strlen(arr1) - 1;
//	printf("%s\r", arr2);
//	while (start <= end)
//	{
//		Sleep(1000);
//		arr2[start] = arr1[start];
//		arr2[end] = arr1[end];
//		start++;
//		end--;
//		printf("%s\r", arr2);
//	}
//	system("pause");
//	return 0;
//}


//3.��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼����
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

//4.���� n�Ľ׳�
//int main()
//{
//	int n = 0;
//	int result = 1;
//	printf("please enter your number:");
//	scanf("%d",&n);
//	do
//	{
//		result *= n;
//		n--;
//	} while (n > 1);
//	//for (; n > 1; n--)
//	//{
//	//	result *= n;
//	//}
//	printf("the result is: %d\n", result);
//	system("pause");
//	return 0;
//}


//5.���� 1!+2!+3!+����+10!
//int main()
//{
//	int i,j, result = 1, sum = 0;
//	printf("please enter your number:");
//	scanf("%d", &i);
//	for (; i > 0; i--)
//	{
//		for (j = i; j > 1; j--)
//		{
//			result *= j;
//		}
//		sum += result;
//		result = 1;
//	}
//	printf("the sum is: %d\n", sum);
//	system("pause");
//	return 0;
//}



//6.��һ�����������в��Ҿ����ĳ������n
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


//7.��������Ϸʵ��
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