/* Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).*/

#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[50][50];
    int symmetric = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }

    if(symmetric)
        printf("Matrix is Symmetric");
    else
        printf("Matrix is Not Symmetric");

    return 0;
}