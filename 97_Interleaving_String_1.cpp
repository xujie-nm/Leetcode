#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isInterleave(string s1, string s2, string s3){
    if(s1.size() + s2.size() != s3.size())
        return false;

    int m = s1.size();
    int n = s2.size();
    vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;

    for (int i = 1; i <= m; i++) {//记录s1和s3的前几个相同
        if(s1[i-1] == s3[i-1])
            dp[i][0] = true;
        else
            break;
    }   

    for (int j = 1; j <= n; j++) {//记录s2和s3的前几个相同
        if(s2[j-1] == s3[j-1])
            dp[0][j] = true;
        else
            break;
    }   
    
    // 这里存在两个字符串多个字符相同的情况
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(s1[i-1] == s3[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j];//如果s1和当前的s3相同，查看去除这个字符之前的是否相同
            if(s2[j-1] == s3[j+i-1])
                dp[i][j] = dp[i][j-1] || dp[i][j];//同上
        }   
    }   
    return dp[m][n];
}

int main(int argc, const char *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}

/**
*　　　　　　　 ┏┓　 ┏┓+ +
*　　　　　　　┏┛┻━━━┛┻━━┓ + +
*　　　　　　　┃　　     ┃ 　
*　　　　　　　┃　━　    ┃ ++ + + +
*　　　　　　 ████━████ ┃+
*　　　　　　　┃　　　　 ┃ +
*　　　　　　　┃　┻　　　┃
*　　　　　　　┃　　　　 ┃ + +
*　　　　　　　┗━┓　　 ┏━┛
*　　　　　　　　┃　　 ┃　　　　　　　　　　　
*　　　　　　　　┃　　 ┃ + + + +
*　　　　　　　　┃　　 ┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　┃　　 ┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　┃　　 ┃
*　　　　　　　　┃　　 ┃　　+　　　　　　　　　
*　　　　　　　　┃　 　┗━━━┓ + +
*　　　　　　　　┃ 　　　　┣┓
*　　　　　　　　┃ 　　　　┏┛
*　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　 　　　　　┃┫┫ ┃┫┫
*　　 　　　　　　┗┻┛ ┗┻┛+ + + +
*/
