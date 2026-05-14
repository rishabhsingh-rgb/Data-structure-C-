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
