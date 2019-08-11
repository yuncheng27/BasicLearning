#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<math.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//如：在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：2550136832

//unsigned int reverse_bit(unsigned int value)
//{
//	int arr[32];
//	int tmp = 0,i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = sz-1;i>=0; i--)
//	{
//		arr[i] = value % 2;
//		value = value / 2;
//	}
//	for (i = 0;i < sz/2;i++)
//	{
//		tmp = arr[i];
//		arr[i] = arr[sz - 1 - i];
//		arr[sz - 1 - i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		value += arr[i] * pow(2, sz-i-1);
//	}
//	printf("the reverse value is:%u\n", value);
//	return value;
//}
//
//int main()
//{
//	int value;
//	printf("please input value: ");
//	scanf("%d", &value);
//	reverse_bit(value);
//	system("pause");
//	return 0;
//}


//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//int main()
//{
//	float a, b;
//	float c = 0;
//	printf("please input two numbers: ");
//	scanf("%f %f", &a, &b);
//	if (a >= b)
//	{
//		c = a - b;
//		c = c / 2;
//		a = a - c;
//	}
//	else
//	{
//		c = b - a;
//		c = c / 2;
//		a = a + c;
//	}
//	printf("the mean number is:%.4f", a);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int a, b;
//	int c = 0;
//	printf("please input two numbers: ");
//	scanf("%d %d", &a, &b);
//	c = a + b;
//	c = c >> 1;
//	printf("the mean number is:%d", c);
//	system("pause");
//	return 0;
//}


//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

//void find_num(int *arr, int size)
//{
//	int count = 0;
//	int i = 0,j = 0,flag = 0;
//	printf("成单出现的数字有：");
//	for (; i < size; i++)
//	{
//		count = 0;
//		for (j = 0; j < size; j++)
//		{
//			flag = arr[i] ^ arr[j];
//			if (flag == 0)
//			{
//				count++;
//			}
//		}
//		if (count == 1)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,3,5,7,11,13,17,2,3,7,17 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	find_num(arr, size);
//	system("pause");
//	return 0;
//}



//4.有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//	student a am i
//	i ma a tneduts
//	i am a student

//void exchange(char *arr, int size)
//{
//	int tmp = 0;
//	int i = 0,j = 0,k = 0;
//	int count = 0,flag = 0;
//	for (; i < size/2; i++)
//	{
//		tmp = arr[i];
//		arr[i] = arr[size - 1 - i];
//		arr[size - 1 - i] = tmp;
//
//	}
//	//printf("%s", arr);
//	for (i = 0; i < size; i++)
//	{
//		if ((arr[i] == ' '))
//		{
//			j = i - count;
//			count = count / 2;
//			count = count + j;
//			for (; j < count; j++)
//			{
//				tmp = arr[j];
//				arr[j] = arr[i - 1 - flag];
//				arr[i - 1 - flag] = tmp;
//				flag++;
//			}
//			count = 0;
//		}
//		else if (i +1 == size)
//		{
//			count++;
//			i = i + 1;
//			j = i - count;
//			count = count / 2;
//			count = count + j;
//			for (; j < count; j++)
//			{
//				tmp = arr[j];
//				arr[j] = arr[i- flag];
//				arr[i-flag] = tmp;
//				flag++;
//			}
//			count = 0;
//		}
//		else
//		{
//			count++;
//		}
//	}
//	printf("%s", arr);
//}
//
//int main()
//{
//	char arr[] = { "student a am i" };
//	int size = strlen(arr);
//	exchange(arr, size);
//	system("pause");
//	return 0;
//}