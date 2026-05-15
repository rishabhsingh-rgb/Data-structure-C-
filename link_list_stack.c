#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void peek();

struct node
{
    int value;
    struct node *next;
}*top=NULL;

void push()
{
    int item;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter item to push: ");
    scanf("%d",&item);
    temp->value=item;
    temp->next=top;
    top=temp;
    printf("%d Pushed successfully.\n",item);
    
}
void pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        printf("%d popped from stack.\n",top->value);
        temp=top;
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is %d.\n",top->value);
    }
}

void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp=top;
        printf("Stack is:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->value);
            temp=temp->next;
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
