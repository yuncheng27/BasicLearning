#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
//
//
////1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
////����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
//void chengfabiao(int n)
//{
//	int i = 0, j = 0, result = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			result = i*j;
//			printf("%d*%d=%d ", j, i, result);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("please enter your number:\n");
//	scanf("%d",&n);
//	chengfabiao(n);
//	system("pause");
//	return 0;
//}
//
//
////2.ʹ�ú���ʵ���������Ľ�����
//void exchenge(int num1,int num2)
//{
//	num2 += num1;
//	num1 = num2 - num1;
//	num2 = num2 - num1;
//	printf("After exchange,these numbers are:%d %d\n", num1, num2);
//}
//
//int main()
//{
//	int num1, num2;
//	printf("please enter two numbers:");
//	scanf("%d %d", &num1, &num2);
//	exchenge(num1,num2);
//	system("pause");
//	return 0;
//}
//
//
////3.ʵ��һ�������ж�year�ǲ������ꡣ
//void is_leap(int year)
//{
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//	{
//		printf("it is a leap year!");
//	}
//	else
//	{
//		printf("it isn't a leap year!");
//	}
//}
//
//int main()
//{
//	int year = 0;
//	printf("please enter a year:");
//	scanf("%d", &year);
//	is_leap(year);
//	system("pause");
//	return 0;
//}
//
//
//
////4.����һ�����飬
////ʵ�ֺ���init������ʼ�����顢
////ʵ��empty����������顢
////ʵ��reverse���������������Ԫ�ص����á�
////Ҫ���Լ���ƺ����Ĳ���������ֵ��
//void empty(int arr[],int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void init(int arr[],int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void reverse(int arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left <= right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = {3,3,3,3,3,3,3,3,3};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//    empty(arr,sz);	
//    init(arr,sz);
//	reverse(arr,sz);
//	system("pause");
//	return 0;
//}
//
//
////5.ʵ��һ���������ж�һ�����ǲ���������
//void is_prime(int num)
//{
//	int i = 0;
//	for (i = 2; i < num; i++)
//	{
//		if (num%i == 0)
//		{
//			printf("this number isn't a prime number!");
//			break;
//		}
//		else
//		{
//			printf("this number is a prime number!");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int num = 0;
//	printf("please enter a number:");
//	scanf("%d", &num);
//	is_prime(num);
//	system("pause");
//	return 0;
//}