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
