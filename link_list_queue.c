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
