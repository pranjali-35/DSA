#include <stdio.h>
#include <stdlib.h>

struct node1{
    int data;
    struct node1 *next;
};struct node1 *head1;

struct node2{
    int data;
    struct node2 *next;
};struct node2 *head2;

//First list
int count_node(){
    if(head1 == NULL){
        return 0;
    }int count = 0;
    struct node1 *temp = (struct node1 *)malloc(sizeof(struct node1));
    temp = head1;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }return count;
}

void insert_begin(){
    struct node1 *ptr = (struct node1*)malloc(sizeof(struct node1));
    if(ptr == NULL){
        printf("No memory available\n");
        return;
    }printf("Enter the data to be inserted : ");
    scanf("%d",&(ptr->data));
    ptr->next = head1;
    head1 = ptr;
}

void insert_end(){
    struct node1 *temp, *newnode = (struct node1*)malloc(sizeof(struct node1));
    if(head1 == NULL){
        printf("Enter the data you want to store : ");
        scanf("%d",&(newnode->data));
        head1 = newnode;
        newnode->next = NULL;
        return;
    }
    temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }printf("Enter the data you want to store : ");
    scanf("%d",&(newnode->data));
    temp->next = newnode;
    newnode->next = NULL;
}

void random_insert(){                   //check for pos = 2
    int pos;
    printf("Enter the position at which you want to enter the data : ");
    scanf("%d",&pos);
    if(pos == 1){
        insert_begin();
        return;
    }else if(pos > (count_node()+1)){
        printf("Can't insert data at position %d\n",pos);
        return;
    }if(pos == (count_node()+2)){
        insert_end();
        return;
    }struct node1 *temp,*newnode = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    printf("Enter data to be inserted at position %d : ",pos);
    scanf("%d",&(newnode->data));
    pos -= 2;
    while(pos--){
        temp = temp->next;
    }newnode->next = temp->next;
    temp->next = newnode;
}

void display(){
    if(head1 == NULL){
        printf("List is empty\n");
        return;
    }struct node1 *temp = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_begin(){
    if(head1 == NULL){                       //Empty linked list
        printf("Empty linked list\n");
        return;
    }if(head1->next == NULL){                //Single node in linked list
        free(head1);
        return;
    }struct node1 *temp = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    head1 = head1->next;
    free(temp);
}

void delete_end(){
    struct node1 *temp,*temp1 = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = NULL;
    free(temp);
}

void random_delete(){
    int pos;
    printf("Enter position from where you want to delete : ");
    scanf("%d",&pos);
    if(pos == 1){                           //Deletion of first node
        delete_begin();
        return;
    }if(pos == count_node()){               //Deletion of last node
        delete_end();
        return;
    }struct node1 *temp,*temp1 = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    pos--;
    while(pos--){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = temp->next;
    free(temp);
}

void search(){
    if(head1 == NULL){
        printf("Empty linked list\n");
        return;
    }int element;
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    struct node1 *temp = (struct node1*)malloc(sizeof(struct node1));
    temp = head1;
    int count = 0;
    int count_n = count_node();
    for(int i = 0 ; i < count_n ; i++){
        if(temp->data == element){
            printf("Element found at position %d\n",i+1);
            return;
        }temp = temp->next;
    }printf("Element not found in linked list\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//Second list
int count_node2(){
    if(head2 == NULL){
        return 0;
    }int count = 0;
    struct node2 *temp = (struct node2 *)malloc(sizeof(struct node2));
    temp = head2;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }return count;
}

void insert_begin2(){
    struct node2 *ptr = (struct node2*)malloc(sizeof(struct node2));
    if(ptr == NULL){
        printf("No memory available\n");
        return;
    }printf("Enter the data to be inserted : ");
    scanf("%d",&(ptr->data));
    ptr->next = head2;
    head2 = ptr;
}

void insert_end2(){
    struct node2 *temp, *newnode = (struct node2*)malloc(sizeof(struct node2));
    if(head2 == NULL){
        printf("Enter the data you want to store : ");
        scanf("%d",&(newnode->data));
        head2 = newnode;
        newnode->next = NULL;
        return;
    }temp = head2;
    while(temp->next != NULL){
        temp = temp->next;
    }printf("Enter the data you want to store : ");
    scanf("%d",&(newnode->data));
    temp->next = newnode;
    newnode->next = NULL;
}

void random_insert2(){                   //check for pos = 2
    int pos;
    printf("Enter the position at which you want to enter the data : ");
    scanf("%d",&pos);
    if(pos == 1){
        insert_begin();
        return;
    }else if(pos > (count_node2()+1)){
        printf("Can't insert data at position %d\n",pos);
        return;
    }if(pos == (count_node2()+2)){
        insert_end();
        return;
    }struct node2 *temp,*newnode = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    printf("Enter data to be inserted at position %d : ",pos);
    scanf("%d",&(newnode->data));
    pos -= 2;
    while(pos--){
        temp = temp->next;
    }newnode->next = temp->next;
    temp->next = newnode;
}

void display2(){
    if(head2 == NULL){
        printf("List is empty\n");
        return;
    }struct node2 *temp = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_begin2(){
    if(head2 == NULL){                       //Empty linked list
        printf("Empty linked list\n");
        return;
    }if(head2->next == NULL){                //Single node in linked list
        free(head2);
        return;
    }struct node2 *temp = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    head2 = head2->next;
    free(temp);
}

void delete_end2(){
    struct node2 *temp,*temp1 = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = NULL;
    free(temp);
}

void random_delete2(){
    int pos;
    printf("Enter position from where you want to delete : ");
    scanf("%d",&pos);
    if(pos == 1){                           //Deletion of first node
        delete_begin();
        return;
    }if(pos == count_node2()){               //Deletion of last node
        delete_end();
        return;
    }struct node2 *temp,*temp1 = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    pos--;
    while(pos--){
        temp1 = temp;
        temp = temp->next;
    }temp1->next = temp->next;
    free(temp);
}

void search2(){
    if(head2 == NULL){
        printf("Empty linked list\n");
        return;
    }int element;
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    struct node2 *temp = (struct node2*)malloc(sizeof(struct node2));
    temp = head2;
    int count = 0;
    int count_n = count_node2();
    for(int i = 0 ; i < count_n ; i++){
        if(temp->data == element){
            printf("Element found at position %d\n",i+1);
            return;
        }temp = temp->next;
    }printf("Element not found in linked list\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void merge(){
    struct node1 *temp;
    temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }temp->next = head2;
}

int main()
{
    int choice;
    do{
        printf("\nEnter your choice :\n0.Exit\n1.Insertion at begnning\n2.Insertion at end\n3.Random insertion\n");
        printf("4.Display list\n5.Deletion from beginning\n6.Deletion from end\n7.Random deletion\n");
        printf("8.Count the number of nodes\n9.Search an element\n");
        
        printf("\n10.Insertion at begnning\n11.Insertion at end\n12.Random insertion\n");
        printf("13.Display list\n14.Deletion from beginning\n15.Deletion from end\n16.Random deletion\n");
        printf("17.Count the number of nodes\n18.Search an element\n19.Merge\n");
        
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
                search();
                break;
            
            case 10:
                insert_begin2();
                break;
            case 11:
                insert_end2();
                break;
            case 12:
                random_insert2();
                break;
            case 13:
                display2();
                break;
            case 14:
                delete_begin2();
                break;
            case 15:
                delete_end2();
                break;
            case 16:
                random_delete2();
                break;
            case 17:
                count = count_node2();
                printf("Number of nodes present : %d\n",count);
                break;
            case 18:
                search2();
                break;
            
            case 19:
                merge();
                break;
            default:
                printf("Enter a valid value\n");
        }
    }while(choice != 0);
    
    return 0;
}
