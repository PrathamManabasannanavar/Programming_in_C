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

void binaryTree(node *root)
{
    int choice;
    // for left node
    while(1)
    {
        printf("Enter:\n1 to add left node to %d\n0 to exit\n",root->data);
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 1 || choice == 0) break;
        printf("Invalid choice\n");
    }
    if(choice)
    {
        root->left = createNode();
        binaryTree(root->left);
    }
    //for right node
    while(1)
    {
        printf("Enter:\n1 to add right node to %d\n0 to exit\n",root->data);
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 1 || choice == 0) break;
        printf("Invalid choice\n");
    }
    if(!choice)
        return;
    root->right = createNode();
    binaryTree(root->right);
}

main()
{
    node *root = NULL;
    int choice;
    printf("Enter 1 to add root node\nEnter 0 to exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(!choice)
        root = NULL;
    else
    {
        root = createNode();
        binaryTree(root);
    }
    displayTree(root);
}