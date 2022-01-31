//Solution 3 is a improved version of solution 2
#include <stdio.h>
#include <stdlib.h>

int BinarySearchRow(int** matrix, int matrixSize, int target){
    //Target: Search the maximum row beginning with an element that is no larger than target
    int l = -1, r = matrixSize - 1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(matrix[mid][0] == target){
            return mid;
        }
        else if(matrix[mid][0] < target){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}

bool BinarySearchCol(int* row, int rowColumnSize, int target){
    //Target: Search target in array 'row', return true if existed
    int l = 0, r = rowColumnSize - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(row[mid] == target){
            return 1;
        }
        else if(row[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return 0;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    //Binary search the last row beginning with an element that is no larger than target
    int row = BinarySearchRow(matrix, matrixSize, target);
    if(row == -1){
        return 0;
    }
    //Binary search the row and find target if existed
    bool result = BinarySearchCol(matrix[row], matrixColSize[row], target);
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