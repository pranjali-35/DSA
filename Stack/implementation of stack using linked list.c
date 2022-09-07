#include <stdio.h>  
#include <stdlib.h>  

struct node   
{  
    int val;  
    struct node *next;  
};  
struct node *head;

void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
        printf("Memory Unavailable\n");   
    else{  
        printf("Enter the value : ");  
        scanf("%d",&val);  
        if(head == NULL){         
            ptr->val = val;  
            ptr->next = NULL;  
            head = ptr;  
        }else{  
            ptr->val = val;  
            ptr->next = head;  
            head = ptr;  
        } 
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
        printf("Underflow\n");  
    else{  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
    }  
}  

void display()  
{  
    int i;  
    struct node *ptr;  
    ptr = head;  
    if(ptr == NULL)  
        printf("Stack is empty\n");  
    else{  
        while(ptr != NULL){  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}  

void main ()  
{  
    int choice = 1;     
    while(choice != 0)  
    {  
        printf("Enter your choice :\n1.Push\n2.Pop\n3.Display\n0.Exit : ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 0:   
                break; 
            case 1:  
                push();  
                break;  
            case 2:  
                pop();  
                break;  
            case 3:  
                display();  
                break;  
            default:  
                printf("Please Enter valid choice\n");  
        }  
    }  
}  
