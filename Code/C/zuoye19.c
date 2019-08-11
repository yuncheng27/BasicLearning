////1.模拟实现strncpy
//#include<stdio.h>
//#include<assert.h>
//#include<windows.h>
//char* mystrncpy(char *dst, const char *src, int len)
//{
//	assert(dst != NULL && src != NULL);
//	char *tmp = dst;
//	int i = 0;
//	while (i < len && *tmp != '\0' && *src != '\0')
//	{
//		*tmp = *src;
//		*tmp++;
//		*src++;
//	    i++;
//	}
//	if (*(tmp) != '\0')
//		*tmp = '\0';
//	return dst;
//}
//
//int main()
//{
//	char src[] = "ABCDEFG";
//	char dst[] = "HHHHHHH";
//	mystrncpy(dst, src,7);
//	puts(dst);
//	system("pause");
//	return 0;
//}
//
////2.模拟实现strncat
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//char *MyStrncat(char *dst, const char *src, int  n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (src[i] != '\0')
//		{
//			dst[n + i] = src[i];
//		}
//	}
//	dst[n + i] = '\0';
//	return dst;
//}
//int main()
//{
//	char dst[50] = "hello ";
//	char src[] = "world!";
//	int n = strlen(dst);
//	MyStrncat(dst, src,n);
//	puts(dst);
//	system("pause");
//	return 0;
//}
//
//
///*3.模拟实现strncm*/
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//#include<windows.h>
//char *MyStrncmp(char *a, const char *b, int n)
//{
//	int i = 0;
//	assert((a != NULL) && (b != NULL));
//	while (*a != '\0' && *b != '\0' && i < n)
//	{
//		if (*a - *b > 0)
//		{
//			return 1;
//		}
//		if (*a - *b < 0)
//		{
//			return -1;
//		}
//		a++;
//		b++;
//		i++;
//	}
//	if (*a == '\0' && *b != '\0')
//	{
//		return - 1;
//	}
//	if (*a != '\0' && *b == '\0')
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	char a[] = "hello";
//	char b[] = "hello";
//	int n = strlen(a);
//	int ret = MyStrncmp(a,b,n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
