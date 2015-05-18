#include <iostream>
#include <string>
#include <vector>
using namespace std;


int numDistinct(string s, string t){
    int m = t.size();
    int n = s.size();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
       for (int j = i; j <= n; j++) {
           if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                //如果相等了，當前的結果等於去掉這個字符的結果
                //加上之前的結果
           }else
               dp[i][j] = dp[i][j-1];
               //表示當前t在s中有多少個
       }
       
    }
    
    return dp[m][n];
}

int main(int argc, const char *argv[])
{
    cout << numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
