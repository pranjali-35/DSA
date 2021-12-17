/*Operation :
1.Insertion at begnning
2.Insertion at end
3.Insertion at specific position
4.Display
5.Deletion from begnning
6.Deletion from end
7.Deletion at specific position
8.Count number of nodes
9.Searching position of an element*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *root = NULL;

void insert_begin(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted : ");
    scanf("%d",&(newnode->data));
    
    if(head == NULL){               //First node
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        root = newnode;
        return;
    }head->prev = newnode;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
}

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

int count_nodes(){
    if(head == NULL){
        return 0;
    }struct node *temp;
    temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }return count;
}

void insert_random(){
    int pos;
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    if(pos>(count_nodes()+1) || pos<1){
        printf("Cannot insert node\n");
        return;
    }else if(pos == 1){
        insert_begin();
        return;
    }else if(pos == (count_nodes()+1)){
        insert_end();
        return;
    }struct node *temp, *newnode = (struct node*)malloc(sizeof(struct node));
    temp = head;
    printf("Enter the data you want to insert : ");
    scanf("%d",&(newnode->data));
    pos-=2;
    while(pos--){
        temp = temp->next;
    }temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
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

void delete_begin(){
    if(head == NULL){                       //empty list
        printf("List is empty\n");
        return;
    }if(head->next == NULL){                //single node
        free(head);
        return;
    }struct node *temp;
    temp = head;
    head->next->prev = NULL;
    head = head->next;
    free(temp);
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

void delete_random(){
    int pos;
    printf("Enter the position from you want to delete the data : ");
    scanf("%d",&pos);
    if(pos > count_nodes() || pos < 1){
        printf("Cannot delete node\n");
        return;
    }else if(pos == 1){
        delete_begin();
        return;
    }else if(pos == count_nodes()){
        delete_end();
        return;
    }struct node *temp;
    temp = head;
    pos--;
    while(pos--){
        temp = temp->next;
    }temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}

void search(){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }int element;
    printf("Enter the element whose position you want to know : ");
    scanf("%d",&element);
    struct node *temp;
    temp = head;
    int count = count_nodes();
    for(int i = 0 ; i < count ; i++){
        if(temp->data == element){
            printf("Element %d found at %d position\n",element,i+1);
            return;
        }temp = temp->next;
    }printf("Element %d does not exist in the linked list\n",element);
}

int main(){
    int choice;
    do{
        printf("\n\nEnter your choice :\n0.Exit\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion at specific position\n");
        printf("4.Display\n5.Deletion from beginning\n6.Deletion from end\n7.Deletion from specific position\n");
        printf("8.Count the number of nodes\n9.Searching for an element\n");
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
                insert_random();
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
                delete_random();
                break;
            case 8:
                count = count_nodes();
                printf("Number of nodes present : %d\n",count);
                break;
            case 9:
                search();
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);

    return 0;
}
