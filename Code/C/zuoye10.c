#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<math.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//�磺��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�2550136832

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


//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
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


//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

//void find_num(int *arr, int size)
//{
//	int count = 0;
//	int i = 0,j = 0,flag = 0;
//	printf("�ɵ����ֵ������У�");
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



//4.��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
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