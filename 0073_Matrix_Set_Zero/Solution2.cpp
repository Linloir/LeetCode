#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int rowNum = matrixSize;
    int colNum = matrixColSize[0];
    int rowHasZero = 0;
    int colHasZero = 0;
    for(int i = 0; i < rowNum; i++){
        for(int j = 0; j < colNum; j++){
            if(i == 0){
                if(matrix[i][j] == 0){
                    rowHasZero = 1;
                }
            }
            if(j == 0){
                if(matrix[i][j] == 0){
                    colHasZero = 1;
                }
            }
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < rowNum; i++){
        for(int j = 1; j < colNum; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(rowHasZero){
        for(int i = 0; i < colNum; i++){
            matrix[0][i] = 0;
        }
    }
    if(colHasZero){
        for(int i = 0; i < rowNum; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int** matrix = (int**)malloc(sizeof(int*) * m);
    int* matrixColSize = (int*)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++){
        matrix[i] = (int*)malloc(sizeof(int) * n);
        matrixColSize[i] = n;
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    setZeroes(matrix, m, matrixColSize);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}