#include<stdio.h>
#include<stdlib.h>

void start(char*, char*);
void replace(int, int, char*);
int check_for_win(char*, int);

main()

{

 int i=0,j;
 char no[10]={'1','2','3','4','5','6','7','8','9', '\0'};
 char choice;

 printf("\n");
 for(j=0; j<3; j++)
 {
 printf("| %c | %c | %c |\n",no[i++],no[i++],no[i++]);
 printf("|   |   |   |\n");
 printf("_____________\n\n");
 }

 start(no,&choice);
}

void start(char* no, char *choice)
{
 int i=0,j,k,itr;
 //int count=0;
 int win=0;

 int player=1;//initialising player
 
 for(k=0; k<=4; k++)
 {
 
  if(player==1)
  {

   printf("Player 1 Enter the no\n");
   scanf(" %c",choice);
    
   for(itr=0; itr<10; itr++)
     if(no[itr]==*choice)
      {
      replace(itr,player,no);
      break;
      }
   printf("\n");

   i=0;
   for(j=0; j<3; j++)
   {
    printf("| %c | %c | %c |\n",no[i++],no[i++],no[i++]);
    printf("|   |   |   |\n");
    printf("_____________\n\n");
   }i=0;

  win = check_for_win(no,player);
   if(win==1)
   {
    printf("Player 1 won!!\n");
    exit(0);
   }
    
   player=2;
   //count++;
  }

  if(player==2)
  {
   if(k==4)
    break;
   printf("Player 2 Enter the no\n");
   scanf(" %c",choice);


   for(itr=0; itr<10; itr++)
     if(no[itr]==*choice)
      {
      replace(itr,player,no);
      break;
      }
    
   printf("\n");

   i=0;
   for(j=0; j<3; j++)
   {
    printf("| %c | %c | %c |\n",no[i++],no[i++],no[i++]);
    printf("|   |   |   |\n");
    printf("_____________\n\n");
   }i=0;
   
   win = check_for_win(no,player);
   if(win==1)
   {
    printf("Player 2 won!!\n");
    exit(0);
   }
   
   player=1;
   //count++;
  }
 }//end of for()

   
  printf("It's a draw!!\n");


}

void replace(int itr, int player, char *no)
{

 if(player==1)
  *(no + itr) = 'X';

 else if(player==2)
  *(no + itr) = 'O';

}
    
int check_for_win(char *a, int player)
{
 int i,j=0;
 
 if(player==1)
 {
  j=0;

 //horizontal comparison

 if(a[0]=='X' && a[1]=='X' && a[2]=='X')
  return 1;

 else if(a[3]=='X' && a[4]=='X' && a[5]=='X')
  return 1;

 else if(a[6]=='X' && a[7]=='X' && a[8]=='X')
  return 1;

 //Vertical comparison
  
  else if(a[0]=='X' && a[3]=='X' && a[6]=='X')
   return 1;

  else if(a[1]=='X' && a[4]=='X' && a[7]=='X')
   return 1;

  else if(a[2]=='X' && a[5]=='X' && a[8]=='X')
   return 1;

  //Diagonal comparison

  else if(a[0]=='X' && a[4]=='X' && a[8]=='X')
   return 1;

  else if(a[2]=='X' && a[4]=='X' && a[6]=='X')
   return 1;

  else
   return 0;
 }

 else if(player==2)
 {
  j=0;

 //horizontal comparison

 if(a[0]=='O' && a[1]=='O' && a[2]=='O')
  return 1;

 else if(a[3]=='O' && a[4]=='O' && a[5]=='O')
  return 1;

 else if(a[6]=='O' && a[7]=='O' && a[8]=='O')
  return 1;

 //Vertical comparison
  
  else if(a[0]=='O' && a[3]=='O' && a[6]=='O')
   return 1;

  else if(a[1]=='0' && a[4]=='0' && a[7]=='O')
   return 1;

  else if(a[2]=='O' && a[5]=='O' && a[8]=='O')
   return 1;

  //Diagonal comparison

  else if(a[0]=='O' && a[4]=='O' && a[8]=='O')
   return 1;

  else if(a[2]=='O' && a[4]=='O' && a[6]=='O')
   return 1;

  else
   return 0;
 }

}