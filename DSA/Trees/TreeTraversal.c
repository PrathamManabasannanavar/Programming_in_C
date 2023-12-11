//A simple C program to perform Inorder, PostOrder, and PreOrder traversal in a Binary Tree
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
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    return newNode;
}

void PreOrder(node *root)
{
    if(!root) return;
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(node *root)
{
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

void InOrder(node *root)
{
    if(!root) return;
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

node *TreeImp()
{
    node *head = NULL;
    int choice;
    printf("Enter 0 to not to add nodes\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(choice == 0) return NULL;
    head = createNode();
    printf("Enter choice for left node of %d\n",head->data);
    head->left = TreeImp();
    printf("Enter choice for right node of %d\n",head->data);
    head->right = TreeImp();
    return head;
}

main()
{
    node *root = TreeImp();
    printf("Inorder sequence:\n");
    InOrder(root);
    printf("\nPreorder sequence:\n");
    PreOrder(root);
    printf("\nPostorder sequence:\n");
    PostOrder(root);
    printf("\n");
}
