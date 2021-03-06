#include <stdio.h>
#include <stdlib.h>
#define max 100

int stack[max],choice, top = -1;

void push()
{
    if(top == max-1){
        printf("Stack is full\n");
        exit(0);
    }int element;
    printf("Enter element to push into stack : ");
    scanf("%d",&element);
    top++;
    stack[top] = element;
}

void pop()
{
    if(top == -1){
        printf("Stack is empty\n");
        exit(0);
    }printf("Poped element is : %d\n",stack[top]);
    top--;
}

void display()
{
    if(top == -1){
        printf("Stack is empty\n");
        exit(0);
    }int temp = top;
    while(temp != -1){
        printf("%d ",stack[temp]);
        temp--;
    }
}

void peek()
{
    if(top == -1){
        printf("Stack is empty\n");
        exit(0);
    }printf("Peek element is : %d\n",stack[top]);
}

int main()
{
    do{
        printf("Choose : 1.Push\n2.Pop\n3.Display\n.4.Peek\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default :
                exit(0);
        }
    }while(choice != 5);
    return 0;
}
