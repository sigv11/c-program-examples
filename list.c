/*
 * list.c - linked list operations
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
struct node* insert_first(struct node* h, int data)
{
	struct node* d = newnode(data);

	if(h == NULL)
		return d;

	d->next = h;

	return d;
}

/*
 * add item to list
 */
struct node* insert_last(struct node* h, int data)
{
	if(h == NULL)
		return newnode(data);

	h->next = insert_last(h->next, data);

	return h;
}

/*
 * cases:
 * list is empty
 * node cannot be found
 * data is the first node
 * data is a middle node
 * data is the last node
 */
struct node* insert_after(struct node* h, struct node* n, int data)
{
	struct node* t = h;
	if(h == NULL)
		return h;

	while(t != NULL) {
		if(t->data == data) {
			break;
		}
		t = t->next;
	}

	if(t == NULL)
		return h;

	if(t->next == NULL) {
		t->next = n;
	} else {
		n->next = t->next->next;
		t->next = n;
	}

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

struct node* delete_first(struct node *h)
{
	struct node *t;

	if(h == NULL)
		return h;

	t = h;
	h = h->next;
	free(t);

	return h;
}

struct node* delete_last(struct node *h)
{
	struct node *t = h;

	if(t == NULL)
		return t;

	if(t->next == NULL) {
		free(t);
		return NULL;
	}

	while(t->next->next != NULL) {
		t = t->next;
	}

	t->next = t->next->next;
	free(t->next);

	return h;
}

	void
print_operations()
{
	printf("1.  Print list\n");
	printf("2.  Reverse list\n");
	printf("3.  Insert first\n");
	printf("4.  Insert last\n");
	printf("5.  Insert at position\n");
	printf("6.  Insert before position\n");
	printf("7.  Insert after position\n");
	printf("8.  Insert after node\n");
	printf("9.  Insert before node\n");
	printf("10. Delete first\n");
	printf("11. Delete last\n");
	printf("12. Delete at position\n");
	printf("13. Delete before position\n");
	printf("14. Delete after position\n");
	printf("15. Delete after node\n");
	printf("16. Delete before node\n");
	printf("17. Reverse list\n");
	printf("q. Exit\n");
}

	int
main(int argc, char *argv[])
{
	int i;

	struct node *h = NULL;
	for(i = 0; i < 10; i++)
		h = insert_last(h, i);

	print(h);

	h = reverse(h, NULL);
	print(h);

	h = reverse2(h);
	print(h);

	h = delete_first(h);
	print(h);

	h = delete_last(h);
	print(h);

	h = insert_first(h, 11);
	print(h);

	h = insert_last(h, 13);
	print(h);

	h = insert_after(h, newnode(14), 13);
	print(h);

	return 0;
}
