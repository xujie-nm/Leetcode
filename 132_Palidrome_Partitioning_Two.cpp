#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minCut(string s){
    if(s.empty())
        return 0;
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    vector<int> d(s.size());
    for (int i = s.size()-1; i >= 0; i--) {
        d[i] = s.size()-i-1;
        // 初始化为如果是最坏情况，没有超过两个字符的回文
        // 所以需要切的次数为当前长度减１
        for (int j = i; j < s.size(); j++) {
            if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                // 如果当前前后两个字符相等
                // 那么当当前字符长度小于２或者去掉前后两个字符也是回文的情况
                // 那么当前s[i~j]也是回文
                dp[i][j] = true;
                // 设置s[i~j]字符串为回文
                if(j == s.size()-1)
                    d[i] = 0;
                // 如果s[i~s.size()-1]为回文，那么当前s[i~s.size()-1]最小切的次数为０
                else if(d[j+1]+1 < d[i])
                // 已经确定s[i~j]是回文，回文切0次
                // 所以s[i~s.size()-1]所需要切的最少的次数是
                // １＋s[j+1~s.size()-1]所需要切的最少次数
                // 那么如果这个次数小于初始化的最大次数，则进行重新赋值
                    d[i] = d[j+1]+1;
            }
        }
    }
    return d[0];
}

// another clear solution
int minCut2(string s){
    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0xffff));
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length()-i; j++) {
            if(s[j] == s[j+i])
                // 这一步先得到string中的回文
                dp[j][j+i] = j+1 <= j+i-1 ? dp[j+1][j+i-1] : 0;
        }
    }

    for (int j = 1; j < s.length(); j++) {
        for (int i = 0; i < j; i++) {
            // 计算出最小的分法
            dp[0][j] = min(dp[0][j], dp[0][i] + dp[i+1][j] + 1);
        }
    }

    return dp[0][s.length()-1];
}
int main(int argc, const char *argv[])
{
    cout << minCut2("abbab") << endl;
    return 0;
}
