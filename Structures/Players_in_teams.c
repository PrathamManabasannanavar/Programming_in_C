// A simple C program to compute the player details and group them into respective teams
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct player
{
    char name[30];
    char team[30];
    int player_no;
} player;

void read(player *, int);
void display(player *, int);
void check_team(player *, int, char (*)[12], int);
void read_teams(char (*)[12], int);

main()
{
    int n, teams;
    char team_names[20][12];

    printf("Enter the no of players\n");
    scanf("%d",&n);
    player *players = (struct player *)malloc(n * sizeof(player));

    printf("Enter the no of teams\n");
    scanf("%d",&teams);

    printf("Enter the teams:-\n");
    read_teams(team_names, teams);

    printf("Enter the player details:-\n");
    read(players, n);

    printf("Entered player details are:-\n");
    display(players, n);
    check_team(players, n, team_names, teams);
}

void read(player *players, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter player %d details\n",i+1);
        printf("Enter the name of player\n");
        scanf("%s",players[i].name);
        printf("Enter the player no\n");
        scanf("%d",&players[i].player_no);
        printf("Enter the team of the player\n");
        scanf("%s",players[i].team);
    }
}

void read_teams(char (*team)[12], int teams)
{
    for(int i=0; i<teams; i++)
    {
        printf("Enter the team no %d\n",i+1);
        scanf("%s",*(team+i));
    }
}

void check_team(player *players, int n, char (*team)[12], int m)
{
    for(int i=0; i<m; i++)
    {
        printf("The team %s players are:-\n",*(team+i));
        for(int j=0; j<n; j++)
        {
            if(strcmp(*(team+i), players[j].team) == 0)
                printf("%s\n",players[j].name);
        }
    }
}

void display(player *players, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Player %d details\n",i+1);
        printf("Name : %s\n",players[i].name);
        printf("Player no : %d\n",players[i].player_no);
        printf("Team name : %s\n\n",players[i].team);
    }
}
    