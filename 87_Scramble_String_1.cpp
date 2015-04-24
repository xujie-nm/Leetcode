#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2){
    if(s1.size() != s2.size() || s1.size() == 0 || s2.size() == 0)
        return false;
   
    if(s1 == s2)
        return true;

    int len = s1.size();

    //声明一个三维数组
    vector<vector<vector<bool> > > dp(len+1, vector<vector<bool> >(len, vector<bool>(len)));

    //当k=1时初始化
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            dp[1][i][j] = (s1[i]==s2[j]);
        }
    }
    //从k=2开始，0(n^4)的循环
    for (int k = 2; k <= len; k++) {
        for (int i = 0; i < len-k+1; i++) {
            for (int j = 0; j < len-k+1; j++) {
                dp[k][i][j] = false;
                for (int divk = 1; divk < k && dp[k][i][j]==false; divk++) {
                    dp[k][i][j] = (dp[divk][i][j] && dp[k-divk][i+divk][j+divk]) || 
                                   (dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j]);
                    //这就是递归里哪两个if的含义
                }
            }   
        }
    }
    return dp[len][0][0];    
}

int main(int argc, const char *argv[])
{
    cout << isScramble("rgtae", "great") << endl;
    return 0;
}
