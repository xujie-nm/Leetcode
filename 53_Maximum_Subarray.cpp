#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxSubArray(int A[], int n){
    int max = A[0];
    int subsum = 0;
    for (int i = 0; i < n; i++) {
        subsum += A[i];
        if(subsum > max)
            max = subsum;
        if(subsum < 0)
            subsum = 0;
    }
    
    return max;
}

// dp
int maxSubArray(vector<int> &nums){
    vector<int> dp(nums.size(), 0);
    int Max = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        Max = max(Max, dp[i]);
    }
    return Max;
}

int main(int argc, const char *argv[])
{
    int A[] = {1};
    cout << maxSubArray(A, 1) << endl;

    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
