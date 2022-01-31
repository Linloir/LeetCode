#include <stdio.h>
#include <stdlib.h>

int BinarySearchRow(int** matrix, int left, int right, int target){
    if(left > right){
        return -1;
    }
    else if(left == right){
        if(matrix[left][0] <= target){
            return left;
        }
        else{
            return -1;
        }
    }
    int mid = (left + right + 1) / 2;
    if(matrix[mid][0] == target){
        return mid;
    }
    else if(matrix[mid][0] > target){
        return BinarySearchRow(matrix, left, mid - 1, target);
    }
    else{
        return BinarySearchRow(matrix, mid, right, target);
    }
}

bool BinarySearchCol(int* row, int left, int right, int target){
    if(left > right){
        return 0;
    }
    int mid = (left + right) / 2;
    if(row[mid] == target){
        return 1;
    }
    else if(row[mid] > target){
        return BinarySearchCol(row, left, mid - 1, target);
    }
    else{
        return BinarySearchCol(row, mid + 1, right, target);
    }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    //Binary search the last row beginning with an element that is no larger than target
    int row = BinarySearchRow(matrix, 0, matrixSize - 1, target);
    if(row == -1){
        return 0;
    }
    //Binary search the row and find target if existed
    bool result = BinarySearchCol(matrix[row], 0, matrixColSize[row] - 1, target);
    //Return result
    return result;
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