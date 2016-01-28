#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

//MLE
void helper(vector<int>& nums, vector<bool>& flags, int& n, int curIndex, int curSum){
    if(curSum-1 >= 0)
        flags[curSum-1] = true;
    if(curSum > n || curIndex >= nums.size())
        return;


    helper(nums, flags, n, curIndex+1, curSum + nums[curIndex]);
    helper(nums, flags, n, curIndex+1, curSum);
}

int minPatches(vector<int>& nums, int n){
    vector<bool> flags(n, false);
    set<int> restNums;
    int res = 0;

    helper(nums, flags, n, 0, 0);
    
    for (int i = 0; i < flags.size(); i++) {
        if(!flags[i]){
            restNums.insert(i+1);
            //cout << "not appear: " << i << endl;
        }
    }

    while(!restNums.empty()){
        set<int> temp;
        int cur = *(restNums.begin());
        res++;
        auto it = restNums.begin();
        while(it != restNums.end()){
            if(restNums.count(*it - cur) == 0 
            && temp.count(*it-cur) == 0){
                temp.insert(*it);
                it = restNums.erase(it);
            }else
                ++it;
        }
    }

    return res;
}


// AC1
int minPatches2(vector<int>& nums, int n){
    vector<long> completeNums;
    long sum = 0;
    int curIndex = 0;
    while(sum < n){
        // 产生新的下一个数
        long newNum = sum+1;
        // 如果这个数小于当前数组中的候选值，置换
        if(curIndex < nums.size() && nums[curIndex] <= newNum){
            newNum = nums[curIndex];
            curIndex++;
        }
        // 把这个数加到结果集
        completeNums.push_back(newNum);
        sum += newNum;
    }

    return completeNums.size()-nums.size();
}

// 改进,想法同上
int minPatches3(vector<int>& nums, int n){
    long curSum = 0;
    int curIndex = 0;
    int res = 0;

    while(curSum < n){
        long newNum = curSum+1;
        res++;
        if(curIndex < nums.size() && nums[curIndex] <= newNum){
            newNum = nums[curIndex];
            curIndex++;
            res--;
        }
        curSum += newNum;
    }

    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{1,2,31,33};

    cout << minPatches2(nums, 2147483647) << endl;
    cout << minPatches3(nums, 2147483647) << endl;
    return 0;
}
