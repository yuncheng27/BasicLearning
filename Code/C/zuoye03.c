#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//1.将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//int main()
//{
//	int i = 0, temp = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		arr1[i] = arr1[i] ^ arr2[i];
//		arr2[i] = arr1[i] ^ arr2[i];
//		arr1[i] = arr1[i] ^ arr2[i];
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	system("pause");
//	return 0;
//}

//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ⋯⋯ + 1 / 99 - 1 / 100 的值。
//int main()
//{
//	int n = 0;
//	float sum = 0, a = 0;
//	for (n = 1; n <= 100; n++)
//	{
//		if (n % 2 == 1)
//		{
//			a = 1;
//		}
//		else
//		{
//			a = -1;
//		}
//		sum += a/ n;
//	}
//	printf("%.8f\n", sum);
//	system("pause");
//	return 0;
//}


//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100;i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (1 % 100 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}