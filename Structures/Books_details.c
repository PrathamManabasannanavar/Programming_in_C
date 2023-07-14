// A simple C program to compute the book details of the Library
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 50

typedef struct books_details
{
  char title[30], author[30], publisher[30];
  int copies;
  float cost;
}books;

void read(books *, int);
void print(books *, int);
int check_stock(books *, int, char *, char *);
void display_details(books *, int);
int search(books *, int);
int book_copies(books *, int);

main()
{
  books book[size];
  int n;

  printf("Enter the no of books\n");
  scanf("%d",&n);
  printf("Enter the book details\n");
  read(book, n);
  printf("Entered book details are:-\n");
  print(book, n);
  search(book,n);
}

void read(books *book, int n)
{
  for(int i=0; i<n; i++)
  {
    printf("Enter the book no %d details\n",i+1);
    printf("Enter the title of the book\n");
    scanf("%s",book[i].title);
    printf("Enter the author of the book\n");
    scanf("%s",book[i].author);
    printf("Enter the Publisher of the book\n");
    scanf("%s",book[i].publisher);
    printf("Enter the no of copies of the book\n");
    scanf("%d",&book[i].copies);
    printf("Enter the cost of each book\n");
    scanf("%f",&book[i].cost);
  }
}

void print(books *book, int n)
{
  for(int i=0; i<n; i++)
  {
     printf("Title : %s\n",book[i].title);
     printf("Author : %s\n",book[i].author);
     printf("Publisher : %s\n",book[i].publisher);
     printf("Copies : %d\n",book[i].copies);
     printf("Cost of each book : %fRs\n\n",book[i].cost);
  }
}

int search(books *book, int n)
{
  char title[30], author[30];
  while(1)
  {
     int choice;
     printf("Enter 1 to continue searching...\nEnter 2 to exit\n");
     scanf("%d",&choice);
     if(choice == 2)
     {
        printf("You exited!!\n");
        exit(0);
     }
     else if(choice != 1)
     {
        printf("Enter valid choice!!\n");
        continue;
     }
    
    printf("Enter title and author name of the book\n");
    scanf("%s %s",title,author);
    int index = check_stock(book, n, title, author);
    if(index == -1)
    {
       printf("Book not found!!\n");
       continue;
    }
    else
    {
       printf("Book found. The book details are:-\n");
       display_details(book, index);
       book_copies(book, index); 
    }
  }

}

int check_stock(books *book, int n, char *title, char *author)
{
  for(int i=0; i<n; i++)
     if(strcmp(book[i].title, title) == 0 && strcmp(book[i].author, author) == 0)
       return i;
  return -1;
}

int book_copies(books *book, int index)
{
 int copies, choice;
 float price;
  while(1)
  {

     printf("Enter the no of copies you need\n");
     scanf("%d",&copies);
     if(copies <= book[index].copies)
     {
        book[index].copies -= copies;
        printf("Total cost = %fRs\n",book[index].cost * copies);
        return 0;
     }
    
     printf("There are only %d copies left in stock\n",book[index].copies);
     printf("If you want to buy within %d remaining copies enter 1 else Enter 0 to exit\n",book[index].copies);
     scanf("%d",&choice);
     if(choice != 1)
       return 0;
  }

}

void display_details(books *book, int index)
{
   printf("Title : %s\n",book[index].title);
   printf("Author : %s\n",book[index].author);
   printf("Publisher : %s\n",book[index].publisher);
   printf("Copies : %d\n",book[index].copies);
   printf("Cost of each book : %fRs\n\n",book[index].cost);
}