#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// DFS

bool dfs(vector<int>& nums, int end, int target)
{
    for (int i = end; i >= 0; i--) {//从大到小遍历
        if(nums[i] == target)
            return true;
        if(nums[i] > target)//太大跳过
            continue;
        if (dfs(nums, i-1, target-nums[i]))
            return true;
    }
    return false;
}

bool canPartition(vector<int>& nums)
{
    int canPartition = false;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    
    if(sum % 2)
        return false;

    sort(nums.begin(), nums.end());
    return dfs(nums, n-1, sum/2);
}

// DP
bool canPartition2(vector<int>& nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];      
    }
   
    if(sum % 2)
        return false;
    
    vector<int> dp(sum/2+1, 0);
    int target = sum/2;
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }       
    }
    return dp[target];
}

int main(int argc, const char *argv[])
{
    vector<int> nums{2,2,3,5}; 
    cout << canPartition(nums) << endl;
    cout << canPartition2(nums) << endl;
    
    return 0;
}
