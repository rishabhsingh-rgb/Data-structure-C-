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
