#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void peek();

typedef struct node {
    int data;
    struct node *link;
}node;

node *first=NULL;
node *last=NULL;

void main()
{
    int choice;
    while(1) {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for peek\t");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            default:
                exit(1);
        }
        
    }
}

void enqueue() {
    node *newnode=NULL;
        newnode=(node*)malloc(sizeof(node));
        if(newnode!=NULL) {
        newnode->link=NULL;
        printf("\nEnter data to be enqueued\t");
        scanf("%d",&newnode->data);
        if(first==NULL) 
            first=last=newnode;
        else
            last->link=newnode;
            last=newnode;
    }
    else
        printf("\nQueue is full!\n");
}

void dequeue() {
    node *temp=first;
    if(first==NULL) 
        printf("\nQueue is empty!\n");
    else
        {
        first=first->link;
        free(temp);
        }
}

void peek() {
    if(first!=NULL)
        printf("\n\t%d\n",first->data);
    else
        printf("\n<--Empty-->\n");
}