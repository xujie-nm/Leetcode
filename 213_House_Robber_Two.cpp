#include <iostream>
#include <string>
#include <vector>
using namespace std;

int simpleRob(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    return dp[nums.size()];
}

int rob(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];

    vector<int> case1(nums.begin(), nums.end()-1);
    vector<int> case2(nums.begin()+1, nums.end());

    return max(simpleRob(case1), simpleRob(case2));

}


int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << rob(nums) << endl;;
    return 0;
}
