//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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