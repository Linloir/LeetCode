#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int rowNum = matrixSize;
    int colNum = matrixColSize[0];
    int hasTarget = 0;

    //Has bug when matrix is [[1]] and target is 1
    //Code will not traverse first row if rowNum == 1
    // for(int i = 0; i < rowNum - 1; i++){
    //     if(matrix[i + 1][0] <= target){
    //         continue;
    //     }
    //     else{
    //         for(int j = 0; j < colNum; j++){
    //             if(matrix[i][j] == target){
    //                 hasTarget = 1;
    //                 break;
    //             }
    //         }
    //         break;
    //     }
    // }
    for(int i = 0; i < rowNum; i++){
        if(i < rowNum - 1 && matrix[i + 1][0] <= target){
            continue;
        }
        else{
            for(int j = 0; j < colNum; j++){
                if(matrix[i][j] == target){
                    hasTarget = 1;
                    break;
                }
            }
            break;
        }
    }
    return hasTarget;
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
    int target;
    scanf("%d", &target);
    int result = searchMatrix(matrix, m, matrixColSize, target);
    printf("%s\n", result ? "True" : "False");
    return 0;
}