#include "../includes/tetripic.hpp"

int allocMatrix(int** &matrix, int row, int col) {
    int i = 0;

    matrix  = (int**)calloc(row,sizeof(int*));
    for(i = 0; i < row; i++){
        matrix[i] =  (int *)calloc(col, sizeof(int));
    }
    if (matrix)
        return 1;
    else
        return 0;
}

void freeMatrix(int** &matrix, int row) {
    int i;
    for(i = 0; i < row; i++){
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
}

void freeMatrix(char** &matrix, int row) {
    int i;
    for(i = 0; i < row; i++){
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
}

int reallocMatrix(int** &matrix, int row, int col) {
    int i = 0;

    matrix = (int **) realloc(matrix, sizeof(int *) * row);
    for (i = 0; i < row; i++)
        matrix[i] = (int *)realloc(matrix[i], sizeof(int) * col);
    if (matrix)
        return 1;
    else
        return 0;
}