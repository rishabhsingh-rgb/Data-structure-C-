#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void push(int item);
void pop(char sym);

struct node
{
    int value;
    struct node *next;
}*top=NULL;

int stackSize = 0;

void push(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->value=item;
    temp->next=top;
    top=temp;
    stackSize++;
}
void pop(char sym)
{
    struct node *temp;
    int pop1,pop2;
    if(stackSize < 2)
    {
        printf("Error: insufficient operands for '%c'\n", sym);
        exit(1);
    }
    else if(top==NULL)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        temp=top;
        pop1=top->value;
        top=top->next;
        free(temp);
        temp=top;
        pop2=top->value;
        top=top->next;
        free(temp);
    }
    stackSize-=2;
    if(sym=='*')
    {
        push(pop2*pop1);
    }
    else if(sym=='/')
    {
        if(pop1==0)
        {
            printf("Error: division by zero\n");
            exit(1);
        }
        push(pop2/pop1);
    }
    else if(sym=='+')
    {
        push(pop2+pop1);
    }
    else if(sym=='-')
    {
        push(pop2-pop1);
    }
    else if(sym=='^')
    {
        push(pow(pop2,pop1));
    }
    else
    {
        printf("Invalid operator %c\n", sym);
        exit(1);
    }
}
