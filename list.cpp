#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

//头插法
LinkNode* CreateList_head(char *arr, int length)
{
	LinkNode *p, *L = NULL;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->next = NULL;
	for (int i = 0; i < length; i++)
	{
		L = (LinkNode*)malloc(sizeof(LinkNode));
		L->data = arr[i];
		L->next = p->next;
		p->next = L;
	}
	return p;
}

//尾插法
LinkNode* CreateList_tail(char *arr, int length)
{
	LinkNode *p, *r, *L = NULL;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->next = NULL;
	r = p;
	for (int i = 0; i < length; i++)
	{
		L = (LinkNode*)malloc(sizeof(LinkNode));
		L->data = arr[i];
		r->next = L;	
		r = L;
	}
	r->next = NULL;
	return p;
}

void InsertNode(LinkNode *L, ElemType data, int index)
{
	LinkNode *tmp = NULL;
	int i = 0;
	if (L == NULL)
		return;
	while (L != NULL && index > i)
	{
		i++;
		L = L->next;
	}
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = data;
	tmp = L->next;
	L->next = p;
	p->next = tmp;
}

void DeleteNodeByIndex(LinkNode *L, int index)
{
	LinkNode *tmp = NULL;
	int i = 1;
	if (L == NULL)
		return;
	while (L != NULL && index > i)
	{
		i++;
		L = L->next;
	}
	tmp = L->next;
	L->next = tmp->next;
	free(tmp);
}

void DeleteNodeByValue(LinkNode *L, ElemType value)
{
	LinkNode *tmp = NULL;
	LinkNode *pre = NULL;
	int i = 1;
	if (L == NULL)
		return;
	while (L->data != value)
	{
		pre = L;
		L = L->next;
	}
	tmp = pre->next;
	pre->next = tmp->next;
	free(tmp);
}

void TranverseList(LinkNode *L)
{
	while (L != NULL)
	{
		printf("%c", L->data);
		L = L->next;
	}
}

int main()
{
	char arr[5] = { 'A', 'B', 'C', 'D', 'E' };
	LinkNode *L = CreateList_head(arr, 5);
	LinkNode *L2 = CreateList_tail(arr, 5);
	printf("头插法: ");
	TranverseList(L->next);
	printf("\n");

	printf("尾插法: ");
	TranverseList(L2->next);
	printf("\n");

	InsertNode(L,'F',2);
	printf("插入数据: ");
	TranverseList(L->next);
	printf("\n");

	DeleteNodeByIndex(L, 6);
	printf("删除数据(通过索引): ");
	TranverseList(L->next);
	printf("\n");

	DeleteNodeByValue(L, 'F');
	printf("删除数据(通过数据): ");
	TranverseList(L->next);
	printf("\n");

	system("pause");
	return 0;
}

