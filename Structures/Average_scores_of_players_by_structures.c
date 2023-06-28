// A simple C program to compute the average scores of the n players in m matches 
#include<stdio.h>

typedef struct player
{
  char name[30];
  int score[10];
  float avg;
}play;

void read(play *, int, int);
void print(play *, int, int);
int main()
{
 play players[50];
 int n,m;
 printf("Enter the number of players\n");
 scanf("%d",&n);

 printf("Enter the number of matches\n");
 scanf("%d",&m);

 printf("Enter the details of the player\n");
 read(players,n,m);
 printf("Details of the player are:-\n");
 print(players,n,m);

 return 0;
}

void read(play *players, int n, int m)
{
 for(int i=0; i<n; i++)
 {
   printf("Enter the name of player %d\n",i+1);
   scanf("%s",players[i].name);

   players[i].avg = 0;
   for(int j=0; j<m; j++)
   {
      printf("Enter the score of '%s' in match no %d\n",players[i].name,j+1);
      scanf("%d",&players[i].score[j]);
      players[i].avg += players[i].score[j];
   }
   players[i].avg = (players[i].avg)/m;
 }
}

void print(play *players, int n, int m)
{
  for(int i=0; i<n; i++)
  {
    printf("Name : %s\n",players[i].name);
    printf("Average score in %d matches = %0.3f\n\n",m,players[i].avg);
  }

}
