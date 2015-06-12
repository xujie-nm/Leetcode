#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
//word break one
bool isBreak(string &s, unordered_set<string> &dict){
    if(dict.empty())
        return false;

    int n = s.size();
    vector<vector<bool> > dp(n+1, vector<bool>(n+1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            string temp = s.substr(i-1, j-i+1);
            if(dp[i-1][j] || (dict.count(temp) > 0 && dp[i][i-1])){
                dp[i][j] = true;
            }
        }
    }
    return dp[n][n];
}

void helper(string &s, int begin, unordered_set<string> &dict, string cur, vector<string> &res){
    if(begin >= s.size()){//over
        cur = cur.substr(0, cur.size()-1);
        res.push_back(cur);
        return;
    }

    for (int i = begin; i < s.size(); i++) {
        string temp = s.substr(begin, i-begin+1);
        if(dict.count(temp) > 0)//if this str is vaild, find next str
            helper(s, i+1, dict, cur+temp+" ", res);
    }
}

vector<string> wordBreak(string s, unordered_set<string> &wordDict){
    string cur;
    vector<string> res;
    if(!isBreak(s, wordDict))
        return res;

    helper(s, 0, wordDict, cur, res);
    return res;
}

int main(int argc, const char *argv[])
{
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    
    string s = "catsanddog";
    
    vector<string> res;
    res = wordBreak(s, dict);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
