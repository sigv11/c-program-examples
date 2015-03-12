/*
 * listrev.c - reverse a dynamic linked list
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* newnode(int data)
{
	struct node* n = (struct node*) malloc(sizeof(struct node));
	if(n == NULL)
		return NULL;

	n->data = data;
	n->next = NULL;

	return n;
}

/*
 * add item to list
 */
struct node* append(struct node* h, int data)
{
	if(h == NULL)
		return newnode(data);

	h->next = append(h->next, data);

	return h;
}

/*
 * print list
 */
void print(struct node* h)
{
	if(h == NULL) {
		printf("NULL\n");
		return;
	}
	
	printf("[%d]->", h->data);
	print(h->next);
}

/*
 * reverse using recursion
 */
struct node* reverse(struct node *h, struct node *p)
{
	struct node *t = h;
	if(h == NULL)
		return NULL;

	if(h->next == NULL) {
		h->next = p;
		return h;
	}

	t = reverse(h->next, h);
	h->next = p;

	return t;
}

/*
 * reverse using iteration
 */
struct node* reverse2(struct node *h)
{
	struct node *a, *b, *c;

	if ( h == NULL || h->next == NULL)
		return h;

	for(a = h, b = h->next; b != NULL; ) {
		c = b->next;
		b->next = a;
		a = b, b = c;
	}
	h->next = 0;

	return a;
}


int
main(int argc, char *argv[])
{
	int i;

	struct node *h = NULL;
	for(i = 0; i < 10; i++)
		h = append(h, i);

	print(h);

        h = reverse(h, NULL);
	print(h);

	h = reverse2(h);
	print(h);

	return 0;
}
