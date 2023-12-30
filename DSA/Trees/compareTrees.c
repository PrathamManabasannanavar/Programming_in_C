//A simple C program to compare two trees
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

int compareTrees(node *root1, node *root2)
{
    if(!root1 && !root2) return 1;
    if(!root1 || !root2) return 0;
    return (root1->data == root2->data && compareTrees(root1->left, root2->left ) && compareTrees(root1->right, root2->right));
}

void inOrder(node *root)
{
    if(!root) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

node *treeImp(node *root)
{
    int choice;
    printf("Enter 1 to add nodes\nEnter 0 to exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(!choice) return NULL;
    root = createNode();
    printf("Enter the left node of %d\n",root->data);
    root->left = treeImp(root->left);
    printf("Enter the right node of %d\n",root->data);
    root->right = treeImp(root->right);
    return root;
}

main()
{
    printf("Enter the 1st Tree\n");
    node *root1 = treeImp(root1);
    printf("Enter the 2nd Tree\n");
    node *root2 = treeImp(root2);
    printf("\n1st Tree:- ");
    inOrder(root1);
    printf("\n2nd Tree:- ");
    inOrder(root2);
    if(compareTrees(root1, root2))
        printf("\nTrees are equal\n");
    else
        printf("\nTrees are not equal\n");
}