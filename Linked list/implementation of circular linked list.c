//Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *root = NULL;

void insert_begin(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : ");
    scanf("%d",&(newnode->data));
    if(head == NULL){
        newnode->next = newnode;
        head = newnode;
        root = newnode;
        return;
    }newnode->next = head;
    head = newnode;
    root->next = newnode;
}

void insert_end(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : ");
    scanf("%d",&(newnode->data));
    if(head == NULL){
         newnode->next = newnode;
        head = newnode;
        root = newnode;
        return;
    }newnode->next = head;
    root->next = newnode;
    root = newnode;
}

int count_node(){
    if(head == NULL){
        return 0;
    }struct node *temp;
    temp = head;
    int count = 0;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }count++;
    return count;
}

void random_insert(){
    int pos;
    printf("Enter the position where you want to insert data : ");
    scanf("%d",&pos);
    if(pos < 1 || pos >= count_node()+2){
        printf("Cannot insert node\n");
        return;
    }if(pos == 1){
        insert_begin();
        return;
    }if(pos == count_node()+1){
        insert_end();
        return;
    }struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : ");
    scanf("%d",&(newnode->data));
    pos -= 2;
    struct node *temp;
    temp = head;
    while(pos--){
        temp = temp->next;
    }newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin(){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }struct node *temp;
    temp = head;
    
    if(head->next == head){
        head = NULL;
        root = NULL;
        free(temp);
        return;
    }
    
    head = temp->next;
    root->next = head;
    free(temp);
}

void delete_end(){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }struct node *temp, *temp1;
    temp = root;
    temp1 = head;
    
    if(head->next == head){
        head = NULL;
        root = NULL;
        free(temp);
        return;
    }
    
    while(temp1->next != root){
        temp1 = temp1->next;
    }temp1->next = head;
    root = temp1;
    free(temp);
}

void random_delete(){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }int pos;
    printf("Enter position where you want to delete data : ");
    scanf("%d",&pos);
    if(pos < 1 || pos > count_node()){
        printf("Cannot delete node\n");
        return;
    }if(pos == 1){
        delete_begin();
        return;
    }else if(pos == count_node()){
        delete_end();
        return;
    }struct node *temp, *temp1;
    temp = head;
    pos--;
    while(pos--){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = temp->next;
    free(temp);
}

void display(){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }struct node *temp;
    temp = head;
    while(temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }printf("%d\n",temp->data);
}

int main()
{
    int choice;
    do{
        printf("\nEnter your choice :\n0.Exit\n1.Insertion at begnning\n2.Insertion at end\n3.Random insertion\n");
        printf("4.Display list\n5.Deletion from beginning\n6.Deletion from end\n7.Random deletion\n");
        printf("8.Count the number of nodes\n9.Search an element\n");
        scanf("%d",&choice);
        
        int count;
    
        switch(choice){
            case 0:
                break;
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                random_insert();
                break;
            case 4:
                display();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                random_delete();
                break;
            case 8:
                count = count_node();
                printf("Number of nodes present : %d\n",count);
                break;
            case 9:
                //search();
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);

    return 0;
}
