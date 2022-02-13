/*** 
 * Author       : Linloir
 * Date         : 2022-02-13 10:32:52
 * LastEditTime : 2022-02-13 11:15:22
 * Description  : [Weekly 280] | B
 */

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef struct tag{
    int num;
    int freq;
    Tag(int n, int f) : num(n), freq(f){}
    bool operator < (const Tag& t) const{
        return freq < t.freq;
    }
} Tag;

int minimumOperations(vector<int>& nums){
    if(nums.size() < 2){
        return 0;
    }
    map<int, int> evenMap;
    map<int, int> oddMap;
    for(int i = 0; i < nums.size(); i++){
        map<int, int>::iterator it = evenMap.find(nums[i]);
        if(it != evenMap.end()){
            it->second++;
        }
        else{
            evenMap.insert(pair<int, int>(nums[i], 1));
        }
        i++;
        if(i < nums.size()){
            it = oddMap.find(nums[i]);
            if(it != oddMap.end()){
                it->second++;
            }
            else{
                oddMap.insert(pair<int, int>(nums[i], 1));
            }
        }
    }
    priority_queue<Tag> evenQueue;
    priority_queue<Tag> oddQueue;
    map<int, int>::iterator it = evenMap.begin();
    while(it != evenMap.end()){
        evenQueue.push(Tag(it->first, it->second));
        it++;
    }
    it = oddMap.begin();
    while(it != oddMap.end()){
        oddQueue.push(Tag(it->first, it->second));
        it++;
    }
    if(evenQueue.top().num == oddQueue.top().num){
        if(evenQueue.top().freq > oddQueue.top().freq){
            oddQueue.pop();
        }
        else{
            evenQueue.pop();
        }
    }
    if(evenQueue.size() == 0){
        evenQueue.push(Tag(0, 0));
    }
    if(oddQueue.size() == 0){
        oddQueue.push(Tag(0, 0));
    }
    return nums.size() - evenQueue.top().freq - oddQueue.top().freq;
}
