/*** 
 * Author       : Linloir
 * Date         : 2022-02-19 23:01:40
 * LastEditTime : 2022-02-20 00:11:46
 * Description  : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long LL;

LL goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int count[100001] = {0};
    bool found[100001] = {0};
    for(int i = nums1Size - 1; i >= 0; i--){
        found[nums1[i]] = true;
        for(int j = nums1Size - 1; j >= 0; j--){
            if(found[nums2[j]]){
                count[nums1[i]]++;
            }
            if(nums1[i] == nums2[j]){
                break;
            }
        }
    }
    LL res = 0;
    for(int i = 0; i < nums1Size; i++){
        if(count[nums1[i]] >= 3){
            for(int j = i + 1; j < nums1Size; j++){
                if(count[nums1[j]] >= 2){
                    bool test = false;
                    for(int k = 0; k < nums1Size; k++){
                        if(nums2[k] == nums1[j]){
                            break;
                        }
                        if(nums2[k] == nums1[i]){
                            test = true;
                            break;
                        }
                    }
                    if(test)
                        res += count[nums1[j]] - 1;
                }
                else{
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    return res;
}
