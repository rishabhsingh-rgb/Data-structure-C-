#include <stdio.h>
#include <stdlib.h>
void new_list();
void traverse();
void insert_beg(int);
void insert_end(int);
void insert_pos(int, int);
void functions();
void insert_nodevalue(int, int);
void del_beg();
void del_end();
void del_pos(int);
void free_list();

struct node
{
	int value;
	struct node *next;
} *head = NULL;

void new_list()
{
	struct node *temp, *pre;
	int i, n;
	temp = pre = NULL;
	printf("How many nodes you want in your linked-list: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Memory allocation failed\n");
			exit(0);
		}
		printf("Enter the value of %d node: ", i + 1);
		scanf("%d", &temp->value);
		temp->next = NULL;
		if (head == NULL)
		{
			head = pre = temp;
		}
		else
		{
			pre->next = temp;
			pre = temp;
		}
	}
	printf("Your new list is created.\n\n");
}
