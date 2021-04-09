#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peek();

int counter=0;


typedef struct node {
    int data;
    struct node *link; 
}node;

node *top = NULL;

void main()
{
    int choice;
    while(1) {
        printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for peek\t");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            default:
                exit(1);
        }
        
    }
}

void push() {
    node *newnode = NULL;
    newnode=(node*)malloc(sizeof(node));
if(newnode!=NULL) {
    printf("\nEnter data to be entered\t");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(top!=NULL)
        newnode->link=top;
    top=newnode;
}
    else
    printf("\nStack Overflow!\n");

    } 

void pop() {
if(top!=NULL) {
    node *temp=top;
    top=top->link;
    free(temp);
}
else 
    printf("\nStack Underfow!\n");
}

void peek() {
    if(top!=NULL)
        printf("\n\t%d\n",top->data);
    else
        printf("\n<-Empty->\n");
}