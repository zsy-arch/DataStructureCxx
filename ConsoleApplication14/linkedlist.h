#pragma once
#include <malloc.h>

#define ElementType int

typedef struct Node Node;

struct Node
{
	ElementType data;
	Node* next;
};

void InitList(Node** pList)
{
	if (pList == NULL) return;
	*pList = (Node*)malloc(sizeof(Node));
	(*pList)->next = NULL;
}

size_t FindNode(Node* pNode, Node* target)
{
	int i = -1;
	if (pNode == NULL) return i;
	Node* tmp = pNode;
	while (tmp != NULL)
	{
		i++;
		if ((void*)tmp == (void*)target) return i;
		tmp = tmp->next;
	}
}

Node* IndexOf(Node* pNode, size_t i)
{
	if (pNode == NULL || i == -1) return pNode;
	size_t j = 0;
	Node* tmp = pNode;
	while (tmp != NULL)
	{
		if (i == j)
		{
			return tmp;
		}
		j++;
		tmp = tmp->next;
	}
	return NULL;
}

size_t Length(Node* pNode)
{
	if (pNode == NULL) return -1;
	size_t len = 0;
	Node* tmp = pNode->next;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return len;
}

void Insert(Node* pNode, size_t i, ElementType data)
{
	Node* node = IndexOf(pNode, i);
	if (node == NULL) return;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	newNode->next = node->next;
	newNode->data = data;
	node->next = newNode;
}

void Remove(Node* pNode, size_t i)
{
	Node* node = IndexOf(pNode, i - 1);
	if (node == NULL) return;
	if (node->next == NULL) return;
	node->next = node->next->next;
}

void ShowAll(Node* p)
{
	if (p == NULL) return;
	Node* tmp = p->next;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}