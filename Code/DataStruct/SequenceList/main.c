#define _CRT_SECURE_NO_WARNINGS 1
#include "SXB.h"

static void menu()
{
	printf("#############################################\n");
	printf("####    0. exit           1. PushBack    ####\n");
	printf("####    2. PopBack        3. PushFront   ####\n");
	printf("####    4. PopFront       5. Insert      ####\n");
	printf("####    6. Erase          7. Find        ####\n");
	printf("####    8. Remove         9. RemoveAll   ####\n");
	printf("####    10. Sort          11. Clear      ####\n");
	printf("####    12. Destroy                      ####\n");
	printf("#############################################\n");
	printf("Please choose:>>>");
}

int main()
{
	SeqList ps;
	SeqListInit(&ps);
	DataType data;
	int pos;
	int select = 0;
	int flag = 0;

	do
	{
		menu();
		scanf("%d", &select);

		switch (select)
		{
		case 0:
			break;
		case 1:
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			TestSeqList(&ps);
			break;
		case 2:
			printf("是否确认删除 1:是   0:否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListPopBack(&ps);
				TestSeqList(&ps);
				break;
			}
			else
			{
				break;
			}
		case 3:
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListPushFront(&ps, data);
			TestSeqList(&ps);
			break;
		case 4:
			printf("是否确认删除 1:是   0：否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListPopFront(&ps);
				TestSeqList(&ps);
				break;
			}
			else
			{
				break;
			}
		case 5:
			printf("请输入要插入的数据和位置:>");
			scanf("%d", &data);
			scanf("%d", &pos);
			SeqListInsert(&ps, pos, data);
			TestSeqList(&ps);
			break;
		case 6:
			printf("请输入要删除元素的位置:>");
			scanf("%d", &pos);
			SeqListErase(&ps, pos);
			TestSeqList(&ps);
			break;
		case 7:
			printf("请输入要查找的元素:>");
			scanf("%d", &data);
			SeqListFind(&ps, data);
			break;
		case 8:
			printf("请输入要删除的元素:>");
			scanf("%d", &data);
			printf("是否确认删除 1:是   0：否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListRemove(&ps, data);
				break;
			}
			else
			{
				break;
			}
		case 9:
			printf("请输入要删除的元素:>");
			scanf("%d", &data);
			printf("确定要删除所有的该值元素!!!？1:是   0：否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListRemoveAll(&ps, data);
				break;
			}
			else
			{
				break;
			}
		case 10:
			BubbleSort(&ps);
			break;
		case 11:
			printf("确定要清空所有元素!!!？1:是   0：否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListClear(&ps);
				break;
			}
			else
			{
				break;
			}
		case 12:
			printf("您即将要销毁顺序表!!!？1:是   0：否:>");
			scanf("%d", &flag);
			if (flag)
			{
				SeqListDestroy(&ps);
				break;
			}
			else
			{
				break;
			}
		default:
			printf("选择错误！请重新选择.");
			break;
		}
	} while (select);
	return 0;
}
