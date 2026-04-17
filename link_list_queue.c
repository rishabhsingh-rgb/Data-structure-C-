#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int item)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=new;
        printf("%d enqueued successfully.\n",item);
    }
    else
    {
        rear->next=new;
        rear=new;
        printf("%d enqueued successfully.\n",item);
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL )
    {
        printf("Queue is empty.\n");
    }
    else if(front==rear)
    {
        printf("%d dequeued successfully.\n",front->data);
        front=rear=NULL;
        free(temp);
    }
    else
    {
        printf("%d dequeued successfully.\n",front->data);
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
       printf("Queue is:-\n");
       while(temp!=NULL)
       {
        printf("%d\n",temp->data);
        temp=temp->next;
       }
    }   
}

int main()
{
    int item,choice;
    while(1)
    {
        printf("\n-----QUEUE MENU-----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("0.Exit\n");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
              printf("Enter item to enqueue:- ");
              scanf("%d",&item);
              enqueue(item);
              break;
            case 2:
              dequeue();
              break;
            case 3:
              display();
              break;
            case 0:
              return 0;
            default:
              printf("Invalid choice!!\n");        
        }
    }
    return 0;
}
