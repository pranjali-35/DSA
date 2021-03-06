///difference with linear queue : 
1. condition to check queue is full 
2. update value of rear in enqueue befor performing enqueue
3. print the last element after the loop in display and 
  initialize i as local varaible in display function instead of defining in loop
4.in linear queue, front is always 0 and rear cannot have value less than front but
  in circular queue, front is not always 0 and rear can have index less than front.


#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max], front = -1, rear = -1;

void enqueue(){
    if((front == 0 && rear == max-1) || (front == rear+1)){
        printf("Queue is full\n");
        return;
    }rear = (rear+1)%max;
    int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    queue[rear] = element;
    
    if(front == -1)
        front = 0;
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }printf("Poped element is : %d\n",queue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }front = (front+1)%max;
}

void display(){
    int i;
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }for(i = front ; i != rear ; i = (i+1)%max){
        printf("%d ",queue[i]);
    }printf("%d\n",queue[i]);
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
    int choice;
    do{
        printf("\nChoose : 1.Enqueue 2.Dequeue 3.Display 4.Peak 5.Exit : ");
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
