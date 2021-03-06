#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create_Node(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int key){
    if(root == NULL)                //empty tree || leave node
        return create_Node(key);
    if(key < root->data)
        root->left = insert(root->left,key);
    else if(key > root->data)
        root->right = insert(root->right,key);
    return root;
}

struct node *in_order_successor(struct node *node){
    struct node *current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *delete_Node(struct node *root, int key){
    if(root == NULL)
        return root;
        
    if(key < root->data)
        root->left = delete_Node(root->left,key);
    else if(key > root->data)
        root->right = delete_Node(root->right,key);
        
    else{
        //Node with no child || 1 child
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //Node with 2 children
        struct node *temp = in_order_successor(root->right);
        root->data = temp->data;
        root->right = delete_Node(root->right,temp->data);
    }return root;
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
        printf("\n\tMenu\n0.Exit\n1.Insert in bst\n2.Display preorder\n3.Display inorder\n4.Display postorder\n");
        printf("5.Deleting from bst\nEnter your choice : ");
        scanf("%d",&choice);
        int key;
        switch(choice){
            case 0:
                break;
            case 1:
                printf("Enter the data you want to insert : ");
                scanf("%d",&key);
                root = insert(root,key);
                //printf(root);
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
            case 5:
                printf("Enter data to be deleted : ");
                scanf("%d",&key);
                root = delete_Node(root,key);
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
        
    }while(choice != 0);
    
    return 0;
}
