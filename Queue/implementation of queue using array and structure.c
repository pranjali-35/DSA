#include <stdio.h>
#include <stdlib.h>

struct number{
    int data;
};

void enqueue(struct number *queue, int *front, int *rear){
    if((((*rear)+1)%100) == (*front)){
        printf("Queue is full\n");
        return;
    }int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    *rear = (*rear+1)%100;
    queue[*rear].data = element;
    if(*front == -1)
        *front = 0;
}

void dequeue(struct number *queue, int *front, int *rear){
    if(*front == -1){
        printf("Queue is empty\n");
        return;
    }if(*front == *rear){
        printf("The only element of the queue was : %d\n",queue[*front].data);
        *front = -1;
        *rear = -1;
        return;
    }
    printf("Poped element is : %d\n",queue[*front].data);
    *front = (*front+1)%10;
    return;
}

void display(struct number *queue, int front, int rear){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }for(int i = front ; i <= rear ; i++){
        printf("%d ",queue[i].data);
    }printf("\n");
}

void peak(struct number *queue, int *front){
    if(*front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Element is : %d\n",queue[*front].data);
}

int main()
{
    struct number queue[10];
    int front = -1,rear = -1;
    int choice;
    
    do{
        printf("Choose : 1.Enqueue 2.Dequeue 3.Display 4.Peak 5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(queue,&front,&rear);
                break;
            case 2:
                dequeue(queue,&front,&rear);
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 4:
                peak(queue,&front);
                break;
            default:
                exit(0);
        }
    }while(choice != 5);

    return 0;
}
