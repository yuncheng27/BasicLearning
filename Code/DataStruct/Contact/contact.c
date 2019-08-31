#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//打印函数
void PrintContact(Contact *p)
{
	ShowContact(p);
}

//对于一个联系人是否存在封装成一个函数
int Find(Contact *p, char *pName)
{
	int i = 0;
	for (; i < (p->count); i++)
	{
		if (0 == strcmp(p->list[i].name, pName))            
		{
			return i;
		}
	}
	return - 1;
}

//初始化
void InitContact(Contact *p)
{
	int count = sizeof(p->list);
	p->count = 0;    //初始化通讯录中存储0条联系人信息
	memset(p->list, 0, count);     //初始化内容全为零     The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c
}

//1.添加联系人信息
//char name[NameSize];
//char gender[GenSize];
//int age;
//char number[NumSize];
//char addr[AddrMAX];
void AddContact(Contact *p)
{
	printf("please input the name:\n");
	scanf("%s", &p->list[p->count].name);
	printf("please input the gender:\n");
	scanf("%s", &p->list[p->count].gender);
	printf("please input the age:\n");
	scanf("%d", &p->list[p->count].age);
	printf("please input the phone number:\n");
	scanf("%s", &p->list[p->count].number);
	printf("please input the contact's address:\n");
	scanf("%s", &p->list[p->count].addr);
	if (p->count > InitCapa)
	{
		printf("Sorry,the contact table already full!\n");
	}
	else
	{
		printf("Add success!\n");
		p->count++;
	}
}

//2.删除指定联系人信息
void DeleteContact(Contact *p)
{
	int pos = -1;
	int flag = 0;
	char name[NameSize];
	printf("please input the name you want to delete:\n");
	scanf("%s", &name);
	pos = Find(p, name);
	if (-1 != pos)
	{
		printf("Are you sure??!, Yes please input '1'  No please input '0':\n");
		scanf("%d", &flag);
		if (1 == flag)
		{
			p->list[pos] = p->list[pos + 1];
			p->count--;
			printf("delete success!\n");
		}
		else
		{
			printf("delete fail!\n");
		}
	}
	else
	{
		printf("Sorry, this name doesn't exists!\n");
	}
}

//3.查找指定联系人信息
//char name[NameSize];
//char gender[GenSize];
//int age;
//char number[NumSize];
//char addr[AddrMAX];
void FindContact(Contact *p)
{
	int pos = -1;
	char name[NameSize];
	printf("please input the name you want to find:\n");
	scanf("%s", &name);
	pos = Find(p, name);
	if (-1 != pos)
	{
		printf("name:%s\n", p->list[pos].name);
		printf("gender:%s\n", p->list[pos].gender);
		printf("age:%d\n", p->list[pos].age);
		printf("phone number:%s\n", p->list[pos].number);
		printf("address:%s\n", p->list[pos].addr);
	}
	else
	{
		printf("Sorry, this name doesn't exists!\n");
	}
}

void ModiMenu()
{
	printf("---------------------------------\n");
	printf("----  0. exit        1. name ----\n");
	printf("----  2. gender      3. age  ----\n");
	printf("----  4. number      5. addr ----\n");
	printf("---------------------------------\n");
	printf("Please choose:>>>");
}
//4.修改指定联系人信息
void ModifContact(Contact *p)
{
	int pos = -1;
	char name[NameSize];
	printf("please input the name you want to find:\n");
	scanf("%s", &name);
	pos = Find(p, name);
	if (-1 != pos)
	{
		printf("name:%s\n", p->list[pos].name);
		printf("gender:%s\n", p->list[pos].gender);
		printf("age:%d\n", p->list[pos].age);
		printf("phone number:%s\n", p->list[pos].number);
		printf("address:%s\n", p->list[pos].addr);
		int choose = 0;
		do {
			ModiMenu();
			scanf("%d", &choose);
			switch (choose)
			{
			case 0:
				break;
			case 1:
				printf("please input the name:\n");
				scanf("%s", &p->list[pos].name);
				break;
			case 2:
				printf("please input the gender:\n");
				scanf("%s", &p->list[pos].gender);
				break;
			case 3:
				printf("please input the age:\n");
				scanf("%d", &p->list[pos].age);
				break;
			case 4:
				printf("please input the phone number:\n");
				scanf("%s", &p->list[pos].number);
				break;
			case 5:
				printf("please input the contact's address:\n");
				scanf("%s", &p->list[pos].addr);
				break;
			default:
				break;
			}
		} while (choose);
	}
	else
	{
		printf("Sorry, this name doesn't exists!\n");
	}
}


//5.显示所有联系人信息
void ShowContact(Contact *p)
{
	if (0 != p->count)
	{
		for (int pos = 0; pos < (p->count); ++pos)
		{
			printf("name:%s\n", p->list[pos].name);
			printf("gender:%s\n", p->list[pos].gender);
			printf("age:%d\n", p->list[pos].age);
			printf("phone number:%s\n", p->list[pos].number);
			printf("address:%s\n", p->list[pos].addr);
			printf("\n");
		}
	}
	else
	{
		printf("Sorry, there have nothing information!\n");
	}
}



//6.清空所有联系人
void EmptyContact(Contact *p)
{
	p->count = 0;
}


//7.以名字排序所有联系人
void SortContact(Contact *p)    //冒泡法
{
	for (int i = 0; i < p->count; ++i)
	{
		for (int j = 0; j < p->count - 1 - i; ++j)
		{
			if (strcmp(p->list[j].name, p->list[j + 1].name) > 0)
			{
				Infom tmp;
				tmp = p->list[j];
				p->list[j] = p->list[j + 1];
				p->list[j + 1] = tmp;
			}
		}
	}
}


//8.保存联系人到文件
void SaveContact(Contact *p)
{
	FILE *pfw = fopen(FILEPATH, "w");
	if (NULL == pfw)
	{
		printf("Sorry, open file error!\n");
		exit(0);
	}
	else
	{
		for (int i = 0; i < p->count; ++i)
		{
			fwrite(&p->list[i], sizeof(Infom), 1, pfw);
		}
	}
	fclose(pfw);
}


//9.加载联系人
void LoadContact(Contact *p)
{
	FILE *pfr = fopen(FILEPATH, "r");
	if (NULL == pfr)
	{
		printf("Sorry, open file error!\n");
		exit(0);
	}
	else
	{
		Infom pe = {0};
		int i = 0;
		while (fread(&pe, sizeof(Infom), 1, pfr))
		{
			p->list[i] = pe;
			++i;
			p->count++;
		}
	}
	fclose(pfr);
}