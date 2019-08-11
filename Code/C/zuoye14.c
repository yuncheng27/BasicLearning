//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include <string.h>
//#include<windows.h>
//void StrRotate(char *left, char *right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[10] = "ABCD";
//	int len = strlen(arr) - 1;
//	int k = 0;
//	char *pstart = &arr[0];
//	char *pend = arr + len;
//	scanf("%d", &k);
//	StrRotate(pstart, pstart + k - 1);
//	StrRotate(pstart + k, pend);
//	StrRotate(pstart, pend);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#define true 1
//#define false 0
//typedef int bool;
//
//bool IsRotate(char *arr1,char *arr2)
//{
//	char *pch;
//	strncat(arr1, arr1, strlen(arr1));
//	pch = strstr(arr1, arr2);
//	if (pch != NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char arr1[20] = "AABCD";
//	char arr2[10] = "BCDAA";
//	bool a = IsRotate(arr1,arr2);
//	printf("%d", a);
//	system("pause");
//	return 0;
//}