#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if(front==(rear+1)%N)
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
        rear=(rear+1)%N;
        queue[rear]=item;
        printf("%d enqueued successfully.\n",item);
    }
}
