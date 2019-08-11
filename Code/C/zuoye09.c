#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//1. 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a < 6; a++)
//	{
//		for (b = 1; b < 6; b++)
//		{
//			for (c = 1; c < 6; c++)
//			{
//				for (d = 1; d < 6; d++)
//				{
//					for (e = 1; e < 6; e++)
//					{
//						if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)
//						{
//							if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
//							{
//								if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
//								{
//									if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
//									{
//										if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
//										{
//											if (a*b*c*d*e == 120)
//												printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}


//2.日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//int main()
//{
//	int a, b, c, d;
//	for (a = 0; a < 2; a++)
//	{
//		for (b = 0; b < 2; b++)
//		{
//			for (c = 0; c < 2; c++)
//			{
//				for (d = 0; d < 2; d++)
//				{
//					if ((a + b + c + d == 3)&&(b&&c == 0))
//					{
//                        printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
//					}	
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}


//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1

//void yang_hui(int *arr1,int *arr2,int size)
//{
//	int i = 0,j = 1;
//	while (j < 5)
//	{
//		for (i = 0; i < size; i++)
//		{
//			if (arr1[i] == 0)
//			{
//				printf(" ");
//			}
//			else
//			{
//				printf("%d", arr1[i]);
//			}
//		}
//		printf("\n");
//		for (i = 0; i < size; i++)
//		{
//			if (arr1[i] != 0)
//			{
//				arr2[i - 1] = arr1[i] + arr1[i - 2];
//				arr2[i + 1] = arr1[i] + arr1[i + 2];
//				arr2[i] = 0;
//			}
//		}
//		for (i = 0; i < size; i++)
//		{
//			arr1[i] = arr2[i];
//		}
//		j++;
//	}
//}
//
//
//int main()
//{
//	int arr1[] = {0,0,0,0,1,0,0,0,0};
//	int arr2[] = {0,0,0,0,0,0,0,0,0 };
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//	yang_hui(arr1,arr2, size);
//	system("pause");
//	return 0;
//}
