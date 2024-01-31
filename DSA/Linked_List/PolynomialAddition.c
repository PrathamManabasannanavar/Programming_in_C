//A simple C program to implement the polynomial Addition using Linkedlist 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff, expo;
    struct node *next;
} node;

node *createNode(int coeff, int expo)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->coeff = coeff;
    newNode->expo = expo;
    return newNode;
}

node *insertTerm(node *head, int coeff, int expo)
{
    node *newNode = createNode(coeff, expo);
    if(!head || expo > head->expo)
    {
        newNode->next = head;
        return newNode;
    }
    node *temp = head;
    while(temp->next && expo < temp->next->expo)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

node *addPolynomial(node *poly1, node *poly2)
{
    if(!poly1) return poly2;
    if(!poly2) return poly1;
    node *poly = NULL;
    while(poly1 && poly2)
    {
        if(poly1->expo == poly2->expo)
        {
            poly = insertTerm(poly, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->expo > poly2->expo)
        {
            poly = insertTerm(poly, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else
        {
            poly = insertTerm(poly, poly2->coeff, poly2->expo);
            poly2 = poly2->next;

        }
    }
    while(poly1)
    {
        poly = insertTerm(poly, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    while(poly2)
    {
        poly = insertTerm(poly, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }
    return poly;
}

void display(node *head)
{
    if(!head)
    {
        printf("0\n");
        return;
    }
    while(head)
    {
        printf("%dx^%d +",head->coeff, head->expo);
        head = head->next;
    }
    printf("\n");
}

node *createPolynomial()
{
    node *head = NULL;
    int choice, coeff, expo;
    while(1)
    {
        printf("Enter 1 to add terms\nEnter 2 to exit\nEnter 3 to display\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter coefficient and Exponent\n");
            scanf("%d %d",&coeff, &expo);
            head = insertTerm(head, coeff, expo);
            break;
        case 2:
            printf("\n");
            return head;
        case 3:
            printf("Polynomial is:\n");
            display (head);
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
}

main()
{
   printf("Enter 1st polynomial:-\n");
   node *poly1 = createPolynomial();
   printf("Enter 2nd polynomial:-\n");
   node *poly2 = createPolynomial();
   printf("Addition of two polynomial is:\n");
   node *poly = addPolynomial(poly1, poly2);
   display(poly);
}