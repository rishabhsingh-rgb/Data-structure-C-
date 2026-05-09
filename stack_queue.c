#include<stdio.h>
#define MAX 100

int stack1[MAX];
int stack2[MAX];
int top1=-1,top2=-1;

void push1(int value)
{
    if(top1==MAX-1)
    {
        printf("Overflow condition(S1).\n");
    }
    else
    {
        top1++;
        stack1[top1]=value;
        printf("%d enqueued successfully.\n",value);

    }
}

void push2(int value)
{
    if(top2==MAX-1)
    {
        printf("Overflow condition(S2).\n");
    }
    else
    {
        top2++;
        stack2[top2]=value;
    }
}

int pop1()
{
    int data;
    if(top1==-1)
    {
        return -1;
    }
    else
    {
        data=stack1[top1];
        top1--;
        return data;
    }
}

void pop2()
{
    int data;
    if(top2==-1 && top1==-1)
    {
        printf("Queue is empty.\n");
        return;
    }
    if(top2==-1)
    {
        while(top1!=-1)
        {
            push2(pop1());
        }
    }

    data=stack2[top2];
    printf("%d dequeued successfully.\n",data);
    top2--;
    
}

void display()
{
    int i;
    if(top1==-1 && top2==-1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue is: ");
    for(i=top2;i>-1;i--)
    {
        printf("%d ",stack2[i]);
    }
    for(i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
    printf("\n");
}


int main()
{
    int choice,value;
    while(1)
    {
        printf("\n=====Queue-Menu=====\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("0.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter value: ");
                scanf("%d",&value);
                push1(value);
                break;
            case 2:
                pop2();
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
