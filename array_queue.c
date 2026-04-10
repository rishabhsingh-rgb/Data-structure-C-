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

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
       printf("Queue is:-\n");
       for(i=front;i<=rear;i++)
       {
           printf("%d\n",queue[i]);
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
