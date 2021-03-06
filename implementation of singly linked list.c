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
    struct node *next;
};
//struct node *head;

int count_node(struct node **head){
    if(head == NULL){
        return 0;
    }int count = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = *head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }return count;
}

void insert_begin(struct node **head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("No memory available\n");
        return;
    }printf("Enter the data to be inserted : ");
    scanf("%d",&(ptr->data));
    ptr->next = *head;
    *head = ptr;
}

void insert_end(struct node **head){
    struct node *temp, *newnode = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Enter the data you want to store : ");
        scanf("%d",&(newnode->data));
        *head = newnode;
        newnode->next = NULL;
        return;
    }
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }printf("Enter the data you want to store : ");
    scanf("%d",&(newnode->data));
    temp->next = newnode;
    newnode->next = NULL;
}

void random_insert(struct node **head){                   //check for pos = 2
    int pos;
    printf("Enter the position at which you want to enter the data : ");
    scanf("%d",&pos);
    if(pos == 1){
        insert_begin(head);
        return;
    }
    else if(pos > (count_node(head)+1)){
        printf("Can't insert data at position %d\n",pos);
        return;
    }if(pos == (count_node(head)+2)){
        insert_end(head);
        return;
    }struct node *temp,*newnode = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    printf("Enter data to be inserted at position %d : ",pos);
    scanf("%d",&(newnode->data));
    pos -= 2;
    while(pos--){
        temp = temp->next;
    }newnode->next = temp->next;
    temp->next = newnode;
}

void display(struct node **head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_begin(struct node **head){
    if(head == NULL){                       //Empty linked list
        printf("Empty linked list\n");
        return;
    }
    
    struct node *t;
    t = *head;
    
    if(t->next == NULL){                //Single node in linked list
        free(head);
        return;
    }struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    *head = t->next;
    free(temp);
}

void delete_end(struct node **head){
    struct node *temp,*temp1 = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = NULL;
    free(temp);
}

void random_delete(struct node **head){
    int pos;
    printf("Enter position from where you want to delete : ");
    scanf("%d",&pos);
    if(pos == 1){                           //Deletion of first node
        delete_begin(head);
        return;
    }if(pos == count_node(head)){               //Deletion of last node
        delete_end(head);
        return;
    }struct node *temp,*temp1 = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    pos--;
    while(pos--){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = temp->next;
    free(temp);
}

void search(struct node **head){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }int element;
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    int count = 0;
    int count_n = count_node(head);
    for(int i = 0 ; i < count_n ; i++){
        if(temp->data == element){
            printf("Element found at position %d\n",i+1);
            return;
        }temp = temp->next;
    }printf("Element not found in linked list\n");
}

int main()
{
    struct node *head = NULL;
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
                insert_begin(&head);
                break;
            case 2:
                insert_end(&head);
                break;
            case 3:
                random_insert(&head);
                break;
            case 4:
                display(&head);
                break;
            case 5:
                delete_begin(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                random_delete(&head);
                break;
            case 8:
                count = count_node(&head);
                printf("Number of nodes present : %d\n",count);
                break;
            case 9:
                search(&head);
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);

    return 0;
}
