#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void insert_end(){
    struct node *temp, *newnode = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Enter the data you want to store : ");
        scanf("%d",&(newnode->data));
        head = newnode;
        newnode->next = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }printf("Enter the data you want to store : ");
    scanf("%d",&(newnode->data));
    temp->next = newnode;
    newnode->next = NULL;
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void reverse(){
    struct node *prev_node, *current_node, *next_node;
    current_node = head;
    next_node = head;
    prev_node = NULL;
    while(next_node != NULL){
        next_node = next_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }head = prev_node;
}

int main(){
    int choice;
    do{
        printf("Enter your choice :\n0.Exit\n1.Insertion at end\n2.Display\n3.Reverse the linked list\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                break;
            case 1:
                insert_end();
                break;
            case 2:
                display();
                break;
            case 3:
                reverse();
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);

    return 0;
}
