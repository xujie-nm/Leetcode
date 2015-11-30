#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// backtracing TLE
void helper(list<int> nums, vector<int>& res, int coins){
    if(nums.empty()){
        res.push_back(coins);
        return;
    }

    for(auto it = nums.begin();
        it != nums.end();){
        int curCoins = 0;
        auto right = it;
        right++;
        auto left = it;
        if(it == nums.begin() && right == nums.end())
            curCoins += *(it);
        else if(it == nums.begin() && right != nums.end()){
            curCoins += (*it) * (*right);
        }else if(right == nums.end()){
            --left;
            curCoins += (*it) * (*left);
        }else{
            --left;
            curCoins += (*left) * (*it) * (*right);
        }
        int temp = *it;
        it = nums.erase(it);
        helper(nums, res, coins + curCoins);
        nums.insert(it, temp);
    }
}

int maxCoins(vector<int> &nums){
    list<int> tempNums(nums.begin(), nums.end());
    vector<int> res;
    helper(tempNums, res, 0);
    return *(max_element(res.begin(), res.end()));
}

// DC TLE
int burst(vector<vector<int> >&memo, vector<int>& nums, int left, int right){
    if(left + 1 == right)
        return 0;
    if(memo[left][right] > 0)
        return memo[left][right];
    int res = 0;
    
    for (int i = left+1; i < right; i++) {
        res = max(res, nums[left]*nums[i]*nums[right]
                + burst(memo, nums, left, i) + burst(memo, nums, i, right));
    }
    memo[left][right] = res;
    return res;
}

int maxCoins2(vector<int>& nums){
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int> > memo(nums.size(), vector<int>(nums.size()));
    return burst(memo, nums, 0, nums.size()-1);
}

// DP
int maxCoins3(vector<int>& nums){
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    // rangeValues[i][j]代表的是range[i,j]可以获得的最大coins
    vector<vector<int> > rangeValues(n+2, vector<int>(n+2, 0));

    for(int len = 1; len <= n; len++){
        for(int start = 1; start <= n-len+1; start++){
            int end = start+len-1;
            int bestCoins = 0;
            // 依次计算[start, end]之间可以获得的最大coins
            for(int final = start; final <= end; ++final){
                // 当前的coins等于
                // 前面的coins加上后面的coins加上当前计算出来的coins
                int coins = rangeValues[start][final-1] + rangeValues[final+1][end];
                coins += nums[start-1]*nums[final]*nums[end+1];
                if(coins > bestCoins){
                    bestCoins = coins;
                }
            }
            rangeValues[start][end] = bestCoins;
        }
    }

    return rangeValues[1][n];
}

// 例[3，1，5，8]如果到了[5,8],那么可能由[3,5,8]或者[1,5,8]中来
int main(int argc, const char *argv[])
{
    vector<int> nums{3, 1, 5, 8};
    cout << maxCoins3(nums) << endl;
    return 0;
}
