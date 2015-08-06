#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums){
    int start = 0, sum = 0, minlen = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        while(sum >= s && start < nums.size()){
            minlen = min(i - start + 1, minlen);
            sum -= nums[start];
            start++;
        }
    }
    minlen = (minlen == INT_MAX ? 0 : minlen);
    return minlen;
}

int minSubArrayLen2(int s, vector<int>& nums){
    int right = 0, left = 0, sum = 0, minlen = INT_MAX;

    while(right < nums.size() || sum >= s){
        //可能在最后的时候还没有找出结果
        if(sum < s && right < nums.size()){
            sum += nums[right++];
        }
        if(sum >= s){
            //总是可能的最小长度
            minlen = min(right-left, minlen);
            sum -= nums[left++];
        }
    }

    minlen = (minlen == INT_MAX ? 0 : minlen);
    return minlen;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(4);
    cout << minSubArrayLen2(7, nums) << endl;
    return 0;
}
