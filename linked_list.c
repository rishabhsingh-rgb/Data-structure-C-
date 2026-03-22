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
void functions()
{
	while(1)
	{  int choice, item, pos, value;
	    printf("\nWhat you want to do?\nPress 1 for printing the list.\nPress 2 for inserting a new node at beginning of list.\n");
		printf("Press 3 for inserting a new node at end of list.\n");
		printf("Press 4 for inserting a new node at desired location.\n");
	    printf("Press 5 for inserting a new node after certain value(alredy existing in list).\n");
	    printf("Press 6 for deleting a node from beginning.\n");
	    printf("Press 7 for deleting a node from end.\n");
	    printf("Press 8 for deleting a node from certain position.\n");
	    printf("Press 0 to exit.\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);
		printf("\n");
	 switch (choice)
	 {
	    case 0:
		{   
			free_list(); 
	    	exit(0);
		}	
	    case 1:
	    {
		    traverse();
		    break;
	    }
	    case 2:
	    {
		    printf("Enter the value to insert at beginning: ");
		    scanf("%d", &item);
		    insert_beg(item);
		    break;
	    }
	        case 3:
	    {
		    printf("Enter the value to insert at end: ");
		    scanf("%d", &item);
		    insert_end(item);
		    break;
	    }
	    case 4:
    	{
	    	printf("Enter the value and position of node you want to insert: ");
	    	scanf("%d %d", &item, &pos);
		    insert_pos(item, pos);
		    break;
    	}
	    case 5:
	    {
		    printf("Enter the value to insert and value after which to insert: ");
		    scanf("%d %d", &item, &value);
		    insert_nodevalue(value, item);
		    break;
	    }
	    case 6:
	    {
	    	del_beg();
	    	break;
    	}
	    case 7:
    	{
	    	del_end();
	    	break;
    	}
	    case 8:
    	{
	    	printf("Enter the position of node which you want to delete: ");
	    	scanf("%d", &pos);
	    	del_pos(pos);
	    	break;
	    }
    	default:
	    {
	    	printf("\nInvalid choice.");
	    	break;
    	}
	 }
   }
}

void free_list()
{
    struct node*temp;

    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void traverse()
{
	struct node *temp;
	char choice2;
	temp = head;
	if (head == NULL)
	{
		printf("List is empty.\n");
		printf("Do you want to create a new list? Press 'y' for yes and 'n' for no: ");
		scanf(" %c", &choice2);
		if (choice2 == 'y' || choice2=='Y')
		{
			new_list();
			return;
		}
		else
		    return;
	}
	else
	{ 
	   printf("Your list is:\n");
	   while (temp != NULL)
	  {
		  printf("%d->", temp->value);
		  temp = temp->next;
	  }
	  printf("NULL\n");

    }		
}
void insert_beg(int item)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	new->value = item;
	new->next = head;
	head = new;
	printf("%d is inserted at beginning of the list.\n", item);
}	
void insert_end(int item)
{
	struct node *new, *temp;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	new->value = item;
	temp = head;

	if(head==NULL)
	{
		head=new;
		printf("%d is inserted at the end of the list.\n", item);
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->next = NULL;
	printf("%d is inserted at the end of the list.\n", item);
	
}
void insert_pos(int value, int pos)
{
	struct node *new, *temp;
	int i;
	if(head==NULL&&pos!=1)
    {
        printf("List is empty.\n");
        return;
    }
	if(pos==1)
    {
        insert_beg(value);
        return;
    }
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	new->value = value;
	temp = head;
	
	for (i=1;i<pos-1;i++)
	{
		if (temp->next==NULL)
		{
			printf("List is shorter to insert.\n");
			free(new);
			return;
		}
		temp = temp->next;
	}
	new->next = temp->next;
	temp->next = new;
	printf("%d is inserted at %d position.\n", value, pos);
	
}
void insert_nodevalue(int value, int item)
{
	struct node *new, *temp;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	new->value = item;
	temp = head;
	while (temp != NULL && temp->value != value)
		temp = temp->next;
	if (temp == NULL)
	{
		printf("Value after which you want to insert new value does not exist in list.\n\n");
		free(new);
		return;
	}
	new->next = temp->next;
	temp->next = new;
	printf("%d is inserted after %d.\n", item, value);
	
}
void del_beg()
{
	struct node *temp;
	temp = head;
	char choice;
	if (head == NULL)
	{
		printf("List is empty.\n");
		printf("Do you want to create a new list? Press 'y' for yes and 'n' for no: ");
		scanf(" %c", &choice);
		if (choice == 'y' || choice=='Y')
	    {
			new_list();
			return;
		}
		else
			return;
	}
	head = head->next;
	free(temp);
	printf("Successfully deleted the first node of the list.\n");
}
