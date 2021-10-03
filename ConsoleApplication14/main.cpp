#pragma warning(disable: 4996)
#include <stdio.h>
#include "linkedlist.h"

int main()
{
	Node* list;
	InitList(&list);
	Insert(list, 0, 10);
	Insert(list, 0, 20);
	ShowAll(list);
	Insert(list, 1, 100);
	ShowAll(list);
	Remove(list, 0);
	ShowAll(list);
	return 0;
}
