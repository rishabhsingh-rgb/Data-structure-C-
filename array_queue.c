#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if(rear==N-1)
    {
        printf("Queue is full.\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=item;
        printf("%d enqueued successfully.\n",item);
    }
    else
    {
        rear++;
        queue[rear]=item;
        printf("%d enqueued successfully.\n",item);
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty.\n");
    }
    else if(front==rear)
    {
        printf("%d dequeued successfully.\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d dequeued successfully.\n",queue[front]);
        front++;
    }
}
