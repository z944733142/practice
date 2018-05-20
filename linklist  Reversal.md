##  先创建一个链表，并随机赋值
``` c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node * next;
} *LinkList, LNode;

void CreateListTail(LinkList * L, int n);   // 创建链表

void listReverse(LinkList * L);             // 逆置链表

int main()
{
    LinkList L;
    CreateListTail(&L, 10);
    LNode * p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    listReverse(&L);

    return 0;
}

void CreateListTail(LinkList * L, int n) {
    srand(time(0));
    LinkList p, r;
    int i;
    *L = (LNode *) malloc(sizeof(LNode));
    r = *L;
    for (i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;                 // 给data随机赋值（1 ~ 100）便于测试
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
```
## 1. 直接值交换法。
		把第一个链表第一个节点的值于最后一个交换，第二个于倒数第二个交换，依次进行下去...........
``` c
void listReverse(LinkList * L) {
	LinkList prev , end, t;
	int i;
	prev = (*L)->next;
	end = (*L)->next;
	for (i = 0;end != NULL;i++)             // 求出链表长度
	{
		end = end->next;
	}
	for (int j = 0; j < i / 2; j++)
	{
		end = (*L)->next;
		prev = (*L)->next;
		for(int k = 1; k < (i-j);k++)        // 依次指向倒数第一个节点，倒数第二个，倒数第三个......
		{
			end = end->next;
		}
		for(int m = 0; m < j   ;m++)        // 依次指向第一个节点，第二个......
		{
			prev = prev->next;
		}
		t->data = end->data;
		end->data = prev->data;
		prev->data = t->data;	
	}
}
```
	与数组逆置的思想差不多，但太过繁琐。
## 2.头插法重建链表。
	将链表节点存入结构指针数组，之后用头插法重新建立链表。
```c
void listReverse(LinkList * L)				 
{
	LinkList  b[15];                       //结构指针数组
	LinkList current = (*L)->next , prev;
	 
	for (int i = 0; current != NULL; i++)  // 用结构指针数组记下各节点
	{	
		b[i] = current;
		current = current->next;
	}
	prev = *L;
	(*L)->next = NULL; 
	for (int i = 0; i < 10; i++)           // 头插法重建链表
	{
		current = b[i];
		current->next = prev->next;
		prev->next = current;
	}
} 
```

## 3.交换指针
	依次改变指针的指向，从而逆置链表。
``` c
void listReverse(LinkList * L)									// 交换指针 
{
	   LinkList current = (*L)->next, prev = NULL, next;
	  /*  初始化prev = NULL 使第一个节点逆置后指向空 */
	   while(current != NULL)
	   {
	   		next = current->next;     // 先记下该节点的next
		   	current->next = prev;     // 让该节点指向上一个节点
		   	prev = current;           // 记下该节点，作为下个节点的上一个
	   		current = next;           // 指针后移
	   }
	   (*L)->next = prev;             // 改变头指针指向
}
```