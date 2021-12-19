#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *root = NULL;

void insert_end(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : ");
    scanf("%d",&(newnode->data));
    
    if(head == NULL){               //First node
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        root = newnode;
        return;
    }newnode->prev = root;
    root->next = newnode;
    root = newnode;
    newnode->next = NULL;
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }struct node *temp;
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_end(){
    if(head == NULL){                       //empty list
        printf("List is empty\n");
        return;
    }if(head->next == NULL){                //single node
        free(head);
        return;
    }struct node *temp;
    temp = root;
    temp->prev->next = NULL;
    root = temp->prev;
    free(temp);
}

void reverse(){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }struct node *current_node, *next_node, *prev_node;
    current_node = head;
    next_node = head;
    prev_node = NULL;
    while(next_node != NULL){
        current_node->prev = current_node->next;
        next_node = next_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }root = head;
    head = prev_node;
}

int main(){
    int choice = 1;
    do{
        printf("\nEnter your choice :\n0.Exit\n1.Insertion \n2.Deletion\n3.Display\n4.Reverse the linked list\n");
        scanf("%d",&choice);
        int count;
        switch(choice){
            case 0:
                break;
            case 1:
                insert_end();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);

    return 0;
}
