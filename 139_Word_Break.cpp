#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &wordDict){
   if(wordDict.empty())
       return false;

   int n = s.size();
   vector<vector<bool> > dp(n+1, vector<bool>(n+1, false));
   for (int i = 0; i <= n; i++) {
       dp[i][0] = true;
   }
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           string temp = s.substr(i-1, j-i+1);
           if(dp[i-1][j] || (wordDict.count(temp) > 0 && dp[i][i-1])){
               //if 0~j can divide or temp in wordDict and 0~i-1 can divide
               //dp[i][i-1] ~~ dp[i][j-(j-i+1)]
                dp[i][j] = true;
           }
       }
   }

   return dp[n][n];
}

// faster
bool wordBreak2(string s, unordered_set<string>& wordDict){
    int len = s.length();
    if(len == 0)
        return false;

    unordered_set<int> lenDict;
    for(string str : wordDict){
        lenDict.insert((int)str.length());
    }

    vector<int> dp(len+1, false);
    dp[0] = true;
    // 每次取现有长度的字符串
    // 而不是一次增长
    for (int i = 0; i <= len; i++) {
        for(int j : lenDict){
            if(j <= i){
                string temp = s.substr(i-j, j);
                if(wordDict.find(temp) != wordDict.end()){
                    dp[i] = dp[i-j];
                    if(dp[i])
                        break;
                }
            }
        }
    }
    return dp[len];
}

int main(int argc, const char *argv[])
{
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");
    cout << wordBreak("leetcode", wordDict) << endl;
    cout << wordBreak2("leetcode", wordDict) << endl;
    return 0;
}
