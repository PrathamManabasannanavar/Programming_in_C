/*A simple C program to compute and print the 
possible plain text of the given plain text by
Caesar Cypher method*/
#include<stdio.h>
#include<string.h>
main()

{
 char alp[50], char_copy[50];
 int i,j;

 printf("Enter the plain text\n");
 gets(alp);
  
 printf("The possible plain texts for given Cipher texts are:-\n");
 for(i=0; i<26; i++) //Getting the secret key to be added
 {
  strcpy(char_copy, alp);
  
  for(j=0; alp[j]!='\0'; j++) //
   char_copy[j]-=i;
  printf("%s",char_copy);
  printf("\n");
 }

}