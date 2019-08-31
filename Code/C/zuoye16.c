//1.实现strcpy
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
//
////2.实现strcat
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

//3.实现strstr
//4.实现strchr
//char *my_strchr(const char *dst, int a)
//{
//	if (dst == NULL)
//	{
//		return NULL;
//	}
//	while (*dst != '\0')
//	{
//		if (*dst == (char)a)
//		{
//			return (char *)dst;
//		}
//		dst++;
//	}
//	return NULL;
//}

//5.实现strcmp
//6.实现memcpy
//7.实现memmove
#if 0
int my_strcmp(const char *src, const char *dst)
{
	int ret = 0;
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		++src, ++dst;
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	return(ret);
}
#endif

#if 0
char *my_strstr(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);
	char *cp = (char *)str1;
	char *substr = (char *)str2;
	char *s1 = NULL;

	if (*str2 == '\0')
		return NULL;

	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
}
#endif

#if 0
void *memcpy(void *dst, const void *src, size_t count)
{
	char *ret = dst;
	while (count--)
	{
		*(char *)dst = *(char *)src;
		src = (char *)src + 1;
		dst = (char *)dst + 1;
	}
	return(ret);
}
#endif


#if 0
void *memmove(char *dst, const char *src, size_t count)
{
	void *ret = dst;
	if (dst <= src || (char *dst) >= ((char *src) + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
		}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	return(ret);
}
#endif



