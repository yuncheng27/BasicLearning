#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ������һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
//��������ǰ������ż�����Ӻ���ǰ������������

//void ReOrder(int *arr, int size)
//{
//	int i = 0,tmp = 0;
//	int *p = arr;
//	int *q = arr + size - 1;
//	while(p < q)
//	{
//		if (0 == *p % 2)
//		{
//			if (1 == *q % 2)
//			{
//                tmp = *p;
//				*p = *q;
//				*q = tmp;
//			}
//			else
//			{
//				--q;
//			}
//		}
//		else
//		{
//			++p;
//		}
//	}
//	for (; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	ReOrder(arr, size);
//	system("pause");
//	return 0;
//}


//2.���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//2 3 4
//3 4 5      
//
//1 3 4
//2 4 5
//4 5 6
//���������ص�����ʹ�ýṹ�嶨��
//#define true 1
//#define false 0
//
//#define N 3
//#define M 3
//typedef int bool;
//
//bool  FindNum(int arr[][N],int num,int *i,int *j)
//{
//	if ((num < arr[0][0]) || (num > arr[M - 1][N - 1]))
//	{
//		printf("invalid number!\n");
//		return false;
//	}
//	int row = 0;
//	int col = N - 1;
//	while ((row < M) && (col >= 0))
//	{
//		if (num == arr[row][col])
//		{
//			*i = row;
//			*j = col;
//			return true;
//		}
//		else if (num < arr[row][col])
//		{
//			col--;
//		}
//		else if(num > arr[row][col])
//		{
//			row++;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	int num = 0,i = 0,j = 0;
//	printf("please input your number(1~5): ");
//	scanf("%d", &num);
//	int arr[3][3] = { {1,2,3} ,{2,3,4} ,{3,4,5} };
//	bool b = FindNum(arr,num,&i,&j);
//	if (b)
//	{
//		printf("%d %d \n", i, j);
//	}
//	system("pause");
//	return 0;
//}