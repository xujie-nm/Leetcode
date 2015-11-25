#include <iostream>
#include <string>
#include <vector>
using namespace std;

// recursive
// TLE
int helper(vector<int> &prices, int cur, int res){
    if(cur >= prices.size())
        return res;
    int i = cur;
    while(i < prices.size()){
        if(prices[i] > prices[i+1])
            break;
        i++;
    }
    if(i >= prices.size())
        i = prices.size()-1;
    
    return max(helper(prices, i+1, res + prices[i-1] - prices[cur]),
               helper(prices, i+2, res + prices[i] - prices[cur]));
}

int maxProfit(vector<int> &prices){
    int res = 0;
    return helper(prices, 0, res);
}

// dp
int maxProfit2(vector<int> &prices){
    int n = prices.size();
    if(n <= 1)
        return 0;
    
    vector<int> dp(n, 0);
    dp[1] = max(prices[1] - prices[0], 0);
    // 初始化第一次和第零次卖
    for (int i = 2; i < n; i++) {
        int maxProfit = 0;
        for (int j = i; j >= 2; j--) {
            maxProfit = max(maxProfit, dp[j-2] + prices[i] - prices[j]);
            // 中间第j-1天休息
        }
        maxProfit = max(maxProfit, dp[i-1]);
        // 当天休息
        maxProfit = max(maxProfit, prices[i] - prices[1]);
        // 第零天休息
        dp[i] = max(maxProfit, prices[i] - prices[0]);
        // 不休息，只买卖一次
    }
    return dp[n-1];
}

int main(int argc, const char *argv[])
{
    vector<int> prices{1,2,3,0,2};
    cout << maxProfit(prices) << endl;
    cout << maxProfit2(prices) << endl;
    return 0;
}
