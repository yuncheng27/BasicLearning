#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
Contact con;

void Menu()
{
	printf("---------------------------------\n");
	printf("----  0. exit        1. Add  ----\n");
	printf("----  2. Del         3. Find ----\n");
	printf("----  4. Modi        5. Show ----\n");
	printf("----  6. Empty       7. Sort ----\n");
	printf("----  8. Save        9. Load ----\n");
	printf("---------------------------------\n");
	printf("Please choose:>>>");
}

void MyContact()
{
	int choose = 0;
	InitContact(&con);
	do {
		Menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			break;
		case 1:
			AddContact(&con);
			break;
		case 2:
			DeleteContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			EmptyContact(&con);
			break;
		case 7:
			SortContact(&con);
			break;
		case 8:
			SaveContact(&con);
			break;
		case 9:
			LoadContact(&con);
			break;
		default:
			break;
		}
	} while (choose);
}
int main()
{
	MyContact();
	system("pause");
	return 0;
}