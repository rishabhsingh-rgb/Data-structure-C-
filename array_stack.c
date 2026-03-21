#include<stdio.h>
void push();
void pop();
void display();
void peek();
#define MAX 7
int stack[MAX];
int top=-1;

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        printf("Enter item to push: ");
        scanf("%d",&item);
        stack[top+1]=item;
        top+=1;
        printf("%d Pushed successfully.\n",item);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        printf("%d popped from stack.\n",stack[top]);
        top-=1;
    }
}

void peek()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is %d.\n",stack[top]);
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    while(1)
    {
        int choice;
        printf("\n----STACK MENU----\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Enter valid choice!\n");                    
        }
    }
    return 0;
}
