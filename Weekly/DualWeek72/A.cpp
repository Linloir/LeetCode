/*** 
 * Author       : Linloir
 * Date         : 2022-02-19 22:31:08
 * LastEditTime : 2022-02-20 00:11:48
 * Description  : 
 */

#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int>& nums, int k){
    int count = 0;
    vector<vector<int>>flags;
    flags.resize(101);
    for(int i = 0; i < nums.size(); i++){
        flags[nums[i]].push_back(i);
    }
    for(int i = 0; i <= 100; i++){
        if(flags[i].size() > 1){
            for(int a = 0; a < flags[i].size() - 1; a++){
                for(int b = a + 1; b < flags[i].size(); b++){
                    if((a * b) % k == 0){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
