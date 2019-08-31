////1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。
//#include<stdio.h>
//#include<windows.h>
//
//void find_num(int *arr, int size)
//{
//	int count = 0;
//	int i = 0, j = 0, flag = 0;
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
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 2,3,5,7,11,13,17,2,3,7,17,13 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	find_num(arr, size);
//	system("pause");
//	return 0;
//}
//
//
////2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
//#include<stdio.h>
//
//#define M 20
//void num_sodawater()
//{
//	int sw = M;
//	int num = M;
//	while (sw > 1)
//	{
//		num += sw/2;
//		sw = sw/2 +sw%2;
//	}
//	printf("可以喝汽水:%d\n", num);
//}
//
//int main()
//{
//	num_sodawater();
//	system("pause");
//	return 0;
//}
//
//
////3.模拟实现strcpy
//#include<stdio.h>
//#include<assert.h>
//
//char *my_strcpy(char *dst, const char *src) 
//{
//	   assert(dst != NULL);
//	   assert(src != NULL);
//	   char *ret = dst;
//       while (*dst = *src)
//            * dst++, *src++;
//       return ret; 
//}
//
//int main()
//{
//	char dst[] = "anfafkdsfsl";
//	char src[] = "aaflpajapdd";
//	my_strcpy(dst, src);
//	return 0;
//}
//
////4.模拟实现strcat
//#include<stdio.h>
//#include<assert.h>
//void *my_strcat(char *dst, const char *src)
//{
//         char *ret = dst;
//         assert(dst != NULL);
//         assert(src != NULL);
//         while (*dst)
//         {
//                 dst++;
//         }
//         while (*dst = *src)
//         {
//				* dst++;
//				* src++;
//         }
//         return ret;
//}
//int main()
//{
//	char dst[] = "anfafkdsfsl";
//	char src[] = "aaflpajapdd";
//	my_strcat(dst, src);
//	return 0;
//}