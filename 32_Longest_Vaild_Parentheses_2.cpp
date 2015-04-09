#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestVaildParentheses(string s){
    int Max = 0;
    int left_cnt = 0;
    vector<int> dp(s.size() + 1, 0);

    for (int i = 1; i <= s.size(); i++) {
        if(s[i-1] == '(')
            left_cnt++;
        else{
            if(left_cnt > 0){//说明前面有未和（匹配的）
                left_cnt--;
                dp[i] = 2;
                if(s[i - 2] == ')')//说明前面有匹配好的部分
                    dp[i] += dp[i - 1];
                dp[i] += dp[i-dp[i]];//把前面可能匹配好的部分加上 
            }
        }
        Max = max(Max, dp[i]);
    }
    return Max;
}


int main(int argc, const char *argv[])
{
    cout << longestVaildParentheses("(()") << endl;;
    cout << "ok" << endl;
    cout << longestVaildParentheses("()") << endl;;
    cout << "ok" << endl;
    cout << longestVaildParentheses(")()()(") << endl;;
    cout << "ok" << endl;

    return 0;
}
