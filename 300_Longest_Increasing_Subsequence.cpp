#include <iostream>
#include <string>
#include <vector>
using namespace std;

// no binary search
int lengthOfLIS(vector<int> &nums){
    if(nums.size() < 2)
        return 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
         for (int j = 0; j < i; j++) {
             if(nums[i] > nums[j])
                 dp[i] = max(dp[i], dp[j]+1);
         }
    }
    return *max_element(dp.begin(), dp.end());
}

// binary search
int lengthOfLIS2(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    vector<int> res;
    res.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] <= res[0])   
            // 换成当前最小
            res[0] = nums[i];
        else if(nums[i] > res.back())
            // 如果比最后一个大，进入
            // 只有递增时才会有这一步
            res.push_back(nums[i]);
        else{
            // 如果是中间数，则找到其合适的位置
            int low = 0;
            int high = res.size()-1;
            int tempRes = low;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(res[mid] >= nums[i]){
                    tempRes = mid;
                    high = mid-1;
                }else
                    low = mid+1;
            }
            res[tempRes]= nums[i];
        }
    }
    return res.size();
}

int main(int argc, const char *argv[])
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS2(nums) << endl;
    return 0;
}
