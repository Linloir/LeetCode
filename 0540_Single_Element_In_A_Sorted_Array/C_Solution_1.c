/*** 
 * Author       : Linloir
 * Date         : 2022-02-14 19:40:57
 * LastEditTime : 2022-02-15 01:09:56
 * Description  : [14/2/2022 daily] | LeetCode 540 | Medium | C Solution 1
 */

int singleNonDuplicate(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(mid & 1){
            //Should be the same as prev num
            if(nums[mid - 1] != nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            //Should be the same as next num
            if(nums[mid] != nums[mid + 1]){
                right = mid;
            }
            else{
                left = mid + 2;
            }
        }
    }
    return left;
}
