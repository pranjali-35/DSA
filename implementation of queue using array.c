#include <stdio.h>
#include <stdlib.h>
#define max 100

int queue[max], front = -1, rear = -1, choice;

void enqueue(){
    if(((rear+1)%100) == front){
        printf("Queue is full\n");
        return;
    }int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    rear = (rear+1)%100;
    queue[rear] = element;
    if(front == -1)
        front = 0;
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }if(front == rear){
        printf("The only element of the queue was : %d\n",queue[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Poped element is : %d\n",queue[front]);
    front = (front+1)%max;
    return;
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }int temp = front;
    while(temp != rear){
        printf("%d ",queue[temp]);
        temp--;
    }
}

void peak(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Element is : %d\n",queue[front]);
}

int main()
{
    do{
        printf("Choose : 1.Enqueue 2.Dequeue 3.Display 4.Peak 5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peak();
                break;
            default:
                exit(0);
        }
    }while(choice != 5);

    return 0;
}
