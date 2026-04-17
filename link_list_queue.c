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
