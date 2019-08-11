#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>


//1. 给定两个整形变量的值，将两个值的内容进行交换。
//int main()
//{
//	int num1, num2, num3;
//	printf("please enter two numbers:");
//	scanf("%d %d", &num1, &num2);
//	num3 = num1;
//	num1 = num2;
//	num2 = num3;
//	printf("After exchange,these numbers are:%d %d\n",num1,num2);
//	system("pause");
//	return 0;
//}


//2. 不允许创建临时变量，交换两个数的内容（附加题）
//int main()
//{
//		int num1, num2;
//		printf("please enter two numbers:");
//		scanf("%d %d", &num1, &num2);
//		num2 += num1;
//		num1 = num2 - num1;
//		num2 = num2 - num1;
//		printf("After exchange,these numbers are:%d %d\n",num1,num2);
//		system("pause");
//		return 0;
//}


//3.求10 个整数中最大值。
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int max = 0;
//	printf("please enter ten numbers:");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("The max number is:%d\n", max);
//	system("pause");
//	return 0;
//}


//4.将三个数按从大到小输出(冒泡排序法)
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = 0; j < sz - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[3];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("please enter three numbers:");
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	system("pause");
//	return 0;
//}



//5.求两个数的最大公约数。
//int main()
//{
//	int a, b;
//	printf("please enter two numbers:");
//	scanf("%d %d", &a, &b);
//	while (1)
//	{
//		if (a > b)
//		{
//			a -= b;
//		}
//		else if (b > a)
//		{
//			b -= a;
//		}
//		else break;
//	}
//	printf("the maxdata is:%d\n", b);
//	system("pause");
//	return 0;
//}
