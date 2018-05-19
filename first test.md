## 编程
### 1. 字符串替换
实现一个函数将指定字符串中的某个字符串使用指定的字符串替换掉。
例如，有字符串“I love xiyou3g, xiyou3g666”, 将其中的xiyou3g替换成xiyoumobile,结果为"I love xiyoumobile, xiyoumobile666"。



```c
#include<stdio.h>
#include<string.h>
int main() 
{
	char c[100000],a[100],d[100];
	gets(a); 
	gets(d);
	gets(c);
	for(int i = 0; i < (int)strlen(c) ; i++)
	{
		if (c[i] == 18) continue;
		if (strncmp (&c[i],a,strlen(a)) == 0)
		{
			c[i] = 17;
			for (int j = i + 1; j < i + strlen(a); j++)
			{
				c[j] = 18;
			} 
		}
	 } 
	 for (int i = 0; i < strlen(c) ; i++)
	 {
	 	if (c[i] == 18) continue;
	 	if (c[i] != 17) printf("%c", c[i]);
	 	if (c[i] == 17) printf("%s",d);
	 }
} 
```



### 2. 链表逆置
将一个链表的顺序反过来。
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node * next;
} *LinkList, LNode;

void CreateListTail(LinkList * L, int n);

void listReverse(LinkList * L);

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
    // listReverse(&L);

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
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node * next;
} *LinkList, LNode;

void CreateListTail(LinkList * L, int n);

void listReverse(LinkList * L);

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
    p = L->next;
         while (p) {
        printf("%d ", p->data);
        p = p->next;
    }

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
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void listReverse(LinkList * L) {
	LinkList prev , end, t;
	int i;
	prev = (*L)->next;
	end = (*L)->next;
	for (i = 0;end != NULL;i++)
	{
		end = end->next;
	}

	for (int j = 0; j < i / 2; j++)
	{
		end = (*L)->next;
		prev = (*L)->next;
		for(int k = 1; k < (i-j);k++)
		{
			end = end->next;
		}

		for(int m = 0; m < j   ;m++)
		{
			prev = prev->next;
		}

		t->data = end->data;
		end->data = prev->data;
		prev->data = t->data;	
	}

	}

```

``` c
 						// 用交换指针法和头插法逆置。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node * next;
} *LinkList, LNode;

void CreateListTail(LinkList * L, int n);

void listReverse(LinkList * L);


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
       p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');

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
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
//void listReverse(LinkList * L)									// 交换指针 
//{
//	   LinkList current = (*L)->next, prev = NULL, next;
//	  
//	   while(current != NULL)
//	   {
//	   		next = current->next;
//	   		current->next = prev;
//	   		prev = current;
//	   		current = next;
//	   }
//	   (*L)->next = prev; 
//}

void listReverse(LinkList * L)				// 先传入数组保存，再头插法重新建立链表。 
{
	LinkList  b[15];
	LinkList current = (*L)->next , prev;
	 
	for (int i = 0; current != NULL; i++)
	{	
		b[i] = current;
		current = current->next;
	}
	prev = *L;
	(*L)->next = NULL; 
	for (int i = 0; i < 10; i++)
	{
		current = b[i];
		current->next = prev->next;
		prev->next = current;
	}
} 
```



### 3. 文件的复制

使用带有参数的main函数，如果不会的使用不带参数的main也可以。
将一个指定的文件复制到指定的文件中。

```c
#include<stdio.h> 
int main(int argc, char** argv) {
	FILE * fp = NULL, * fp2 = NULL;
	char c[1000], name[100];
	if ((fp = fopen("14.txt", "rt")) == NULL) {
		return 0;
	} 
	if ((fp2 =  fopen(argv[1],"w")) == NULL) {
		return 0;
	} 
	
	int i =0;

	while (1) {
		c[i] = fgetc(fp);
		fputc(c[i], fp2);
		if (c[i] == EOF  ) {
			break;
		}
		i++;
}


	c[i] = '\n';


	fclose(fp);
	fclose(fp2);
	return 0;
}
```



### 4. 大数相加
给定两个16进制数字，这两个数字都特别的大，现在将两个数字相加，输出最后的结果。

```c
#include<stdio.h>
#include<string.h>
int main() {
	char a[10000] = {0}, b[10000] = {0} , d[10000];
	char c;
	int n,m,z,prev;
	scanf("%s",a);
	scanf("%s",b);

	if (strlen(a) < strlen(b))
	{
		for (int i = 0; i < strlen(a); i++)
		{
			c = a[i];
			a[i] = b[i];
			b[i] = c;
		}
	}
	prev = 0;
	for (int i = (int)strlen(b) - 1, j = (int)strlen(a) - 1; j >= 0; i-- ,j--)
	{
		if(a[j] == 'a' ||a[j] == 'A') m = 10;
		if(a[j] == 'b' ||a[j] == 'B') m = 11;
		if(a[j] == 'c' ||a[j] == 'C') m = 12;
		if(a[j] == 'd' ||a[j] == 'D') m = 13;
		if(a[j] == 'e' ||a[j] == 'E') m = 14;
		if(a[j] == 'f' ||a[j] == 'F') m = 15;
		if (i < 0) n = 0;
		else {
		if(b[i] == 'a' ||b[i] == 'A') n = 10;
		if(b[i] == 'b' ||b[i] == 'B') n = 11;
		if(b[i] == 'c' ||b[i] == 'C') n = 12;
		if(b[i] == 'd' ||b[i] == 'D') n = 13;
		if(b[i] == 'e' ||b[i] == 'E') n = 14;
		if(b[i] == 'f' ||b[i] == 'F') n = 15;
		if(b[i] >= '0' &&b[i] <= '9') n = b[i] - '0';
		}
		if(a[j] >= '0' &&a[j] <= '9') m = a[j] - '0';
		z = (n + m +  + prev) % 16;
		if (z == 10) d[j] = 'a';
		if (z == 11) d[j] = 'b';
		if (z == 12) d[j] = 'c';
		if (z == 13) d[j] = 'd';
		if (z == 14) d[j] = 'e';
		if (z == 15) d[j] = 'f';
		if(z <= 9 && z >= 0) 
		d[j] = z + '0';
		prev = (n + m) / 16;
	} 
	if (prev != 0)
	{
		if (prev == 10) printf("a");
		if (prev == 11) printf("b");
		if (prev == 12) printf("c");
		if (prev == 13) printf("d");
		if (prev == 14) printf("e");
		if (prev == 15) printf("f");
		if(prev <= 9 && z >= 0) printf("%d",prev);
	}
	for (int i = 0 ; i < strlen(a) ;i++)
	{
		printf("%c", d[i]);
	}
}
```

```c
					// 更改了ABCDE转换整数的方法。
#include<stdio.h>
#include<string.h>
int main() {
	char a[10000] = {0}, b[10000] = {0} , d[10000];
	char c;
	int n,m,z,prev;
	scanf("%s",a);
	scanf("%s",b);

	if (strlen(a) < strlen(b))
	{
		for (int i = 0; i < strlen(a); i++)
		{
			c = a[i];
			a[i] = b[i];
			b[i] = c;
		}
	}
	prev = 0;
	for (int i = (int)strlen(b) - 1, j = (int)strlen(a) - 1; j >= 0; i-- ,j--)
	{
		if(a[j] >= 'a' && a[j] <= 'z') m = a[j] - 'a' + 10;
		if(a[j] >= 'A' && a[j] <= 'Z') m = a[j] - 'A' + 10;
		if (i < 0) n = 0;
		else {
		if(b[i] >= 'a' && b[i]  <= 'z') n = b[i]  - 'a' + 10;
		if(b[i] >= 'A' && b[i]  <= 'Z') n = b[i]  - 'A' + 10;
		if(b[i] >= '0' &&b[i] <= '9') n = b[i] - '0';
		}
		if(a[j] >= '0' &&a[j] <= '9') m = a[j] - '0';
		z = (n + m +  + prev) % 16;
		if( z >= 10 && z <= 15) d[j] =  z - 10 + 'a'; 
		if(z <= 9 && z >= 0) 
		d[j] = z + '0';
		prev = (n + m) / 16;
	} 
	if (prev != 0)
	{
		if(prev >= 10 && prev <= 15) printf("%c", prev - 10 + 'a'); 
		if(prev <= 9 && z >= 0) printf("%d",prev);
	}
	for (int i = 0 ; i < strlen(a) ;i++)
	{
		printf("%c", d[i]);
	}
}
```

