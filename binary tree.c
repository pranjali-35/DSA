#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create(){
    int x;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d",&x);
    if(x == -1){
        return NULL;
    }newnode->data = x;
    printf("Enter left child of %d : ",x);
    newnode->left = create();
    printf("Enter right child of %d : ",x);
    newnode->right = create();
    return newnode;
}

void preorder(struct node *root){
    if(root == NULL){
        //printf("Tree is empty\n");
        return;
    }printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL){
        //printf("Tree is empty\n");
        return;
    }inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        //printf("Tree is empty\n");
        return;
    }postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct node *root = NULL;
    
    int choice = 1;
    do{
        printf("\n\tMenu\n0.Exit\n1.Create binary tree\n2.Display preorder\n3.Display inorder\n4.Display postorder\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                break;
            case 1:
                root = create();
                break;
            case 2: 
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
        
    }while(choice != 0);
    
    return 0;
}
