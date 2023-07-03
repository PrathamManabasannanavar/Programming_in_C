# A simple Python program to implement tic_tac_toe game
import sys

def board(li):
   count=1
   for i in li:
     print('|',i,'|',end='')
     if count%3==0:
       print('\n')
     count=count+1

def check_for_win(li,player):
   
    #for player 1
  if(player==1):
    if(li[0]=='X' and li[1]=='X' and li[2]=='X'):
        return 1
    elif(li[3]=='X' and li[4]=='X' and li[5]=='X'):
        return 1
    elif(li[6]=='X' and li[7]=='X' and li[8]=='X'):
        return 1
    elif(li[0]=='X' and li[4]=='X' and li[8]=='X'):
        return 1
    elif(li[2]=='X' and li[4]=='X' and li[6]=='X'):
        return 1
    elif(li[0]=='X' and li[3]=='X' and li[6]=='X'):
        return 1
    elif(li[1]=='X' and li[4]=='X' and li[7]=='X'):
        return 1
    elif(li[2]=='X' and li[5]=='X' and li[8]=='X'):
        return 1
       
    #for player 2
  else:
    if(li[0]=='O' and li[1]=='O' and li[2]=='O'):
        return 2
    elif(li[3]=='O' and li[4]=='O' and li[5]=='O'):
        return 2
    elif(li[6]=='O' and li[7]=='O' and li[8]=='O'):
        return 2
    elif(li[0]=='O' and li[4]=='O' and li[8]=='O'):
        return 2
    elif(li[2]=='O' and li[4]=='O' and li[6]=='O'):
        return 2
    elif(li[0]=='O' and li[3]=='O' and li[6]=='O'):
        return 2
    elif(li[1]=='O' and li[4]=='O' and li[7]=='O'):
        return 2
    elif(li[2]=='O' and li[5]=='O' and li[8]=='O'):
        return 2
    else:
        return 0
    
print('Welcome to Tic tac toe!!\n')
li=[1,2,3,4,5,6,7,8,9]
board(li)
player = 1
choice = 0

print('Enter the number between 1 and 9\n')
for j in range(0,4,1):

  if player==1:
   choice = int(input('Player 1 Enter your choice\n'))
   while(choice<1 or choice>9 or li[choice-1]=='X' or li[choice-1]=='O'):
       print('Enter the valid choice!!\n')
       choice = int(input('Player 1 Enter your choice\n'))
    
   for i in range(0,9,1):
     if choice==li[i]:
       li[choice-1]='X'
   board(li)
   if(check_for_win(li, player) == 1):
       print('Player1 won!!\n')
       sys.exit(0)
   player = 2
    
  if player==2:
   choice = int(input('Player 2 Enter your choice\n'))
   while(choice<1 or choice>9 or li[choice-1]=='X' or li[choice-1]=='O'):
       print('Enter the valid choice!!\n')
       choice = int(input('Player 2 Enter your choice\n'))
        
   for i in range(0,9,1):
     if choice==li[i]:
        li[choice-1]='O'
        
   board(li)
   if(check_for_win(li,player) == 2):
       print('\nPlayer2 won!!\n')
       sys.exit(0)
   player = 1


print("It's a draw!!");