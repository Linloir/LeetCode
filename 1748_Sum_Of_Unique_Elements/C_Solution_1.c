/*** 
 * Author       : Linloir
 * Date         : 2022-02-06 09:46:04
 * LastEditTime : 2022-02-06 09:51:28
 * Description  : [6/2/2022 daily] C Solution 1 to Leetcode 1748
 */

int sumOfUnique(int* nums, int numsSize) {
    int flag[101] = {0};
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        if(flag[nums[i]] == 1){
            sum -= nums[i];
            flag[nums[i]]++;
        }
        else if(flag[nums[i]] == 0){
            sum += nums[i];
            flag[nums[i]]++;
        }
        else{
            flag[nums[i]]++;
        }
    }
    return sum;
}