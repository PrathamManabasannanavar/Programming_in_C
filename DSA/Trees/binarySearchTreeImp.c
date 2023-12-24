//A simple C program to implement the binary search Tree 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->left = newNode->right = NULL;
    printf("Enter the data:\n");
    scanf("%d",&newNode->data);
    return newNode;
}

int findPosition(node *root, node *newNode)
{
    if(!root) return 1;
    else if(root->data > newNode->data && findPosition(root->right, newNode))
        root->right = newNode;
    else if(root->data <= newNode->data && findPosition(root->left, newNode))
        root->left = newNode;
    return 0;
}

void inOrder(node *root)
{
    if(!root) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root ->right);
}

node *binarySearchTree()
{
    int choice;
    node *root = NULL;
    printf("Do you want to add nodes\nEnter 1 to add nodes\nEnter 0 to exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(!choice) return NULL;
    if(!root) root = createNode();
    while(1)
    {
        printf("Do you want to add nodes\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(!choice) return root;
        findPosition(root,createNode());
    }
    return root;
}

main()
{
    node *root = binarySearchTree();
    printf("\nInorder traversal is:\n");
    inOrder(root);
}