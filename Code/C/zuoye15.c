////1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡�
//#include<stdio.h>
//#include<windows.h>
//
//void find_num(int *arr, int size)
//{
//	int count = 0;
//	int i = 0, j = 0, flag = 0;
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
////2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
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
//	printf("���Ժ���ˮ:%d\n", num);
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
////3.ģ��ʵ��strcpy
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
////4.ģ��ʵ��strcat
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