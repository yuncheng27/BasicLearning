#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>


//1.дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
//int count_one_bits(unsigned int num,int count)
//{
//	while (num) 
//	{
//      count++;
//	  num = num&(num - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int num = -1;
//	int i = 0;
//	int count = 0;
//	int number = count_one_bits(num,count);
//	printf("��������1�ĸ��� = %d\n", number);
//	system("pause");
//	return 0;
//}


//2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
//void count_bits(unsigned number, int count)
//{
//	int i = 0;
//	int arr[32] = {0};
//	for (i = 0; i < 32; i++)
//	{
//		arr[i] = number % 2;
//		number = number / 2;
//		count++;
//	}
//	printf("�������У�\n");
//	for (i = count-1; i >=0; i -= 2)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("ż�����У�\n");
//	for (i = count-2; i >= 0; i -= 2)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int number =123;
//	int count = 0;
//	count_bits(number,count);
//	system("pause");
//	return 0;
//}

//3. ���һ��������ÿһλ��
//void every_bit(int num,int *arr)
//{
//	int i = 0,n = 0;
//	while(num > 0){
//		arr[i] = num % 10;
//		num = num/10;
//		i++;
//	} 
//	for (; n < i; n++)
//	{
//		printf("%d ", arr[n]);
//	}
//}
//
//int main()
//{
//	int num = 11223344;
//	int arr[8];
//	every_bit(num,arr);
//	system("pause");
//	return 0;
//}


//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
//void differ_bit(int num1,int num2)
//{
//	int arr1[32];
//	int arr2[32];
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		arr1[i] = num1 % 2;
//		num1 /= 2;
//	}
//	for (i = 0; i < 32; i++)
//	{
//		arr2[i] = num2 % 2;
//		num2 /= 2;
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (arr1[i] != arr2[i])
//			count++;
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int num1 = 1999;
//	int num2 = 2299;
//	differ_bit(num1,num2);
//	system("pause");
//	return 0;
//}


//5.д�����ܽ�C���Բ��������������ӷ����ң�������Ⱥ�