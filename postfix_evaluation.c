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
