#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, val;
} Sparse;

void createSparseMatrix(int matrix[][10], int rows, int cols, Sparse sparse[]) {
    int k = 1;
    sparse[0].row = rows;
    sparse[0].col = cols;
    
    int nonZeroCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = matrix[i][j];
                k++;
                nonZeroCount++;
            }
        }
    }
    sparse[0].val = nonZeroCount;
}

void displaySparseMatrix(Sparse sparse[]) {
    printf("\nSparse Matrix Representation (Row, Column, Value):\n");
    for (int i = 0; i <= sparse[0].val; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

int main() {
    int matrix[10][10], rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Sparse sparse[MAX];

    createSparseMatrix(matrix, rows, cols, sparse);
    displaySparseMatrix(sparse);

    return 0;
}
