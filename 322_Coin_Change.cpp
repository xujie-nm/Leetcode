#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int helper(vector<int>& coins, int amount, int cur){
    //cout << "amount: " << amount << " cur: " << cur << endl;
    if(amount == 0)
        return cur;
    else if(amount < 0)
        return -1;
    int res = INT_MAX;
    for (int i = coins.size()-1; i >= 0; i--) {
        int temp_res = -1;
        temp_res = helper(coins, amount-coins[i], cur+1);
        if(temp_res != -1 && temp_res < res){
            res = temp_res;
        }
    }
    return res;
}

int coinChange(vector<int>& coins, int amount){
   int res = 0;
   sort(coins.begin(), coins.end());
   res = helper(coins, amount, 0);
   return res;
}

int coinChange2(vector<int>& coins, int amount){
    int Max = amount + 1;
    // 为每一个硬币可能到得地方计算最少的硬币数
    vector<int> dp(amount+1, Max);
    dp[0] = 0;
    // 遍历每一个数
    for (int i = 0; i <= amount; i++) {
        // 遍历每一个硬币
        for (int j = 0; j < coins.size(); j++) {
            // 如果硬币可能到这里的话
            // 那么他只可能有两个取值，
            // 第一个：当前就是最小的
            // 第二个：减去当前的硬币，查看上一个到得位置的
            //         硬币数加一
            // 取两者中的最小值
            if(coins[j] <= i){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main(int argc, const char *argv[])
{
    vector<int> coins{2,5,10,1};
    cout << coinChange(coins, 27) << endl;
    cout << coinChange2(coins, 27) << endl;
    return 0;
}
