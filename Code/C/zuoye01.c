#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


//打印100~200 之间的素数 
//int main()
//{
//	int i = 0;
//	for ( i = 100; i < 200; i++)
//	{
//		int j = 0;
//		for ( j = 2; j <=i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d\n", i);
//		}
//	}
//	system("pause");
//	return 0;
//}


//输出乘法口诀表
//int main()
//{
//	int i, j, k;
//	int n = 9;
//	for ( i = 1; i <=n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			k = i*j;
//			printf("%d*%d=%d ", i, j, k);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//判断1000年---2000年之间的闰年 
//int main()
//{
//	int i;
//	printf("please enter year:\n");
//	scanf("%d", &i);
//	if ((i % 4 == 0 && (i % 100 != 0)) || (i % 400 == 0))
//	{
//		printf("%d is a leap year\n", i);
//	}
//	else
//	{
//		printf("%d isn't a leap year\n", i);
//	}
//	system("pause");
//}

// the blog site: www.tingyucanhe.com/blog