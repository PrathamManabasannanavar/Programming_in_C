//A simple C program to implement the Expression trees using Trees
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *stack[SIZE];
int top = -1;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void push(node *root)
{
    if(top == SIZE-1) return;
    stack[++top] = root;
}

node *pop()
{
    if(top == -1) return NULL;
    return stack[top--];
}

void infixExp(node *root)
{
    if(!root) return;
    printf("(");
    infixExp(root->left);
    printf("%c",root->data);
    infixExp(root->right);
    printf(")");
}

node *expressionTreeImp(char *str)
{
    node *num1=NULL, *num2=NULL, *root=NULL;
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            num2 = pop();
            num1 = pop();
            root = createNode(str[i]);
            root->left = num1;
            root->right = num2;
            push(root);
            continue;
        }
        root = createNode(str[i]);
        push(root);
    }
    return root;
}

main()
{
    char exp[SIZE];
    printf("Enter the valid Postfix expression\n");
    scanf("%s",exp);
    node *root = expressionTreeImp(exp);
    printf("Infix Expression is:\n");
    infixExp(root);
    printf("\n");
}