#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rob(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++) {
        //状态转换方程
        //当前的值等于上一个（就是说这间屋子不抢）
        //或者是上上个和这个的和（抢这间屋子）
        //局部最优
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    
    return dp[nums.size()];
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    cout << rob(nums) << endl;
    return 0;
}
