//A simple C program to implement the  binary Tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void displayTree(node *root)
{
   if(!root)
      return;
   printf("%d\n",root->data);   
   displayTree(root->left);
   displayTree(root->right);
}

node *binaryTree()
{
    int choice;
    printf("Enter 1 to add nodes\nEnter 0 to exit\nEnter your choice\n");
    scanf("%d",&choice);
    if(!choice) return NULL;
    node *root = createNode();
    printf("Enter your choice for left node of %d\n",root->data);
    root->left = binaryTree();
    printf("Enter your choice for right node of %d\n",root->data);
    root->right = binaryTree();
    return root;
}

main()
{
    node *root = binaryTree();
    displayTree(root);
}