#include <stdio.h>
#include <stdlib.h>

int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int curMax = 0;
    int curMaxCount = 1;
    for(int i = 0; i < rectanglesSize; i++){
        int curLen = rectangles[i][0] < rectangles[i][1] ? rectangles[i][0] : rectangles[i][1];
        curMaxCount = curLen > curMax ? 1 : curLen == curMax ? curMaxCount + 1 : curMaxCount;
        curMax = curLen > curMax ? curLen : curMax;
    }
    return curMaxCount;
}