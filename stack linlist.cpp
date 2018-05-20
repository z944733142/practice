#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char c;
	struct node *next;
}node, *pt;

typedef struct stack {
	pt top;
	int count;
}stack;

void creat (stack * p);
void in (char c, stack * p);
void out (char * c, stack * p);
void print(pt current);
int main ()
{
	char c;
	stack p;
	creat(&p);
	while(scanf("%c", &c) != EOF)
	{
		getchar();
		in(c, &p);
		print(p.top);
	}
		while(1)
	{ 
		getchar();
		out(&c, &p);
		if (c == 32) break;
		printf("%c\n", c);
		print(p.top);
	}
}

void creat (stack * p)
{
	(*p).top = NULL;
	(*p).count = 0;
}

void in (char c, stack * p)
{
	pt current;
	current = (pt) malloc (sizeof(node));
	current->next = (*p).top;
	current->c = c;
	(*p).top = current;
	(*p).count++;
}


void out (char * c, stack * p)
{
	pt prev; 
	prev = (*p).top; 
	*c = (*p).top->c;
	if ((*p).top->next == NULL)
	{
		*c = 32;
		return ;
	}
	(*p).top = (*p).top->next;
	(*p).count--;
	free(prev) ; 
}

void print(pt current)
{
	while (current != NULL)
	{
		putchar(current->c) ;
		current = current->next;
	} 
	printf("\n");
}


