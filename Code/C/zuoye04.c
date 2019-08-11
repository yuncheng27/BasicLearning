#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>



//1.在屏幕上输出以下菱形图案：
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*

//int main()
//{
//	int i = 0;
//	char arr2[] = "*************";
//	char arr1[] = "             ";
//	char arr3[] = "             ";
//	int start = 0;
//	int end = strlen(arr1) - 1;
//	int mid = (strlen(arr1) / 2);
//	int k = strlen(arr1) - mid;
//	for (; i < k;i++)
//	{
//		Sleep(1000);
//		arr1[mid + i] = arr2[mid + i];
//		arr1[mid - i] = arr2[mid - i];
//		printf("%s\n", arr1);
//	}
//	while (start <= end)
//	{
//		Sleep(1000);
//		arr2[start] = arr3[start];
//		arr2[end] = arr3[end];
//		start++;
//		end--;
//		printf("%s\n", arr2);
//	}
	//system("pause");
	//return 0;
//}



//2.求出0〜999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，
//如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
///*
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
//是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。
//*/

//int main()
//{
//	int i = 0,a = 0, b = 0, c = 0;
//	for (i = 100; i <= 999; i++)
//	{
//		a = i / 100;
//		b = (i / 10) % 10;
//		c = i % 10;
//		if (i == a*a*a + b*b*b + c*c*c)
//		{
//			printf("%d\n", i);
//		}
//	}
//	system("pause");
//	return 0;
//}


//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int n = 0, i = 0, num = 0,sum = 0;
//	printf("please enter your namber(1~9)：");
//	scanf("%d", &n);
//	for (; i < 5; i++)
//	{
//		num += n;
//		n *= 10;
//		sum += num;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}



//4.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。
//int main() {
//	int ch = 0;
//	int count = 0;
//	printf("请输入一段字符以ctrl+z结束:\n");
//	while ((ch = getchar()) != EOF) {
//		if (ch == '{') {
//			count++;
//		}
//		if (ch == '}') {
//			if (count>0) {
//				count--;
//			}
//			else {
//				printf("不匹配!\n");//{{{{}}}}}{   }}}}}{{{{{
//				return 0;
//			}
//		}
//	}
//	if (count == 0) {
//		printf("匹配!\n");
//	}
//	else {
//		printf("不匹配!\n");
//	}
//	system("pause");
//	return 0;
//}
