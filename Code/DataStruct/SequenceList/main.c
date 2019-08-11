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
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SeqListPushBack(&ps, data);
			TestSeqList(&ps);
			break;
		case 2:
			printf("�Ƿ�ȷ��ɾ�� 1:��   0:��:>");
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
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SeqListPushFront(&ps, data);
			TestSeqList(&ps);
			break;
		case 4:
			printf("�Ƿ�ȷ��ɾ�� 1:��   0����:>");
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
			printf("������Ҫ��������ݺ�λ��:>");
			scanf("%d", &data);
			scanf("%d", &pos);
			SeqListInsert(&ps, pos, data);
			TestSeqList(&ps);
			break;
		case 6:
			printf("������Ҫɾ��Ԫ�ص�λ��:>");
			scanf("%d", &pos);
			SeqListErase(&ps, pos);
			TestSeqList(&ps);
			break;
		case 7:
			printf("������Ҫ���ҵ�Ԫ��:>");
			scanf("%d", &data);
			SeqListFind(&ps, data);
			break;
		case 8:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &data);
			printf("�Ƿ�ȷ��ɾ�� 1:��   0����:>");
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
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &data);
			printf("ȷ��Ҫɾ�����еĸ�ֵԪ��!!!��1:��   0����:>");
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
			printf("ȷ��Ҫ�������Ԫ��!!!��1:��   0����:>");
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
			printf("������Ҫ����˳���!!!��1:��   0����:>");
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
			printf("ѡ�����������ѡ��.");
			break;
		}
	} while (select);
	return 0;
}
