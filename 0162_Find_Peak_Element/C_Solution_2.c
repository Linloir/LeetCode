/*** 
 * Author       : Linloir
 * Date         : 2022-02-07 14:38:50
 * LastEditTime : 2022-02-07 15:10:31
 * Description  : Leetcode 162 | Medium | C Solution 2 | O(LogN)
 */

#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize){
    int l = 0, r = numsSize - 1;
    if(r == l){
        return l;
    }
    int l_sign = nums[l + 1] - nums[l] > 0 ? 1 : -1;
    int r_sign = nums[r] - nums[r - 1] > 0 ? 1 : -1;
    while(r - l >= 2){
        int mid = (l + r) / 2;
        int m_l_sign = nums[mid] - nums[mid - 1] > 0 ? 1 : -1;
        int m_r_sign = nums[mid + 1] - nums[mid] > 0 ? 1 : -1;
        if(m_l_sign > 0 && m_r_sign < 0){
            return mid;
        }
        else if(l_sign > 0 && m_l_sign < 0){
            r = mid;
            r_sign = m_l_sign;
            continue;
        }
        else if(r_sign < 0 && m_r_sign > 0){
            l = mid;
            l_sign = m_r_sign;
            continue;
        }
        else{
            if(l_sign < 0){
                return l;
            }
            else if(r_sign > 0){
                return r;
            }
        }
    }
    if(r - l == 1){
        return nums[l] > nums[r] ? l : r;
    }
    else{
        return l + 1;
    }
}
