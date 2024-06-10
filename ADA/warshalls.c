//A simple C program to implement the warshalls algorithm
#include<stdio.h>
#define SIZE 5

void readMatrix(int (*matrix)[SIZE], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int (*matrix)[SIZE], int n){
    printf("   a b c d\n");
    for(int i=0; i<n; i++){
        printf("%c: ", (char)(i+'a'));
        for(int j=0; j<n; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int min(int a, int b){
    if(a < b) return a;
    return b;
}

void warshallsAlgorithm(int (*arr)[SIZE], int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
    
}

int main(){
    int matrix[SIZE][SIZE];
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter the adjacent matrix :\n");
    readMatrix(matrix, n);
    printf("The matrix is :\n");
    displayMatrix(matrix, n);
    warshallsAlgorithm(matrix, n);
    printf("The matrix after floyds algorithm is :\n");
    displayMatrix(matrix, n);
    return 0;
}