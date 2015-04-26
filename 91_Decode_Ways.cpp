#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int numDecodings(string s){
    if(s.size() == 0 || (s.size() == 1 && s[0] == '0'))
        return 0;
    vector<int> dp(s.size()+1, 0);
    dp[s.size()] = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        if(i==s.size()-1){
            dp[i] = s[i]=='0' ? 0 : 1;
        }else{
            if(s[i] != '0'){
                dp[i] += dp[i+1];
                if(s[i]<='1' || (s[i]=='2' && s[i+1] <= '6'))
                    dp[i] += dp[i+2];
            }
        }
    }

   return dp[0]; 
}

int main(int argc, const char *argv[])
{
    cout << numDecodings("10") << endl;
    return 0;
}
