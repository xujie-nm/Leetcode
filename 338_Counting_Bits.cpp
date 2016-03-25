#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> countBits(int num){
    vector<int> dp(num+1, 0);
    if(num == 0)
        return dp;
    else if(num == 1){
        dp[1] = 1;
        return dp;
    }

    dp[1] = 1;
    int curPower = 1;
    for (int i = 2; i <= num; i++) {
        if(i == curPower*2){
            dp[i] = 1;
            curPower *= 2;
        }else{
            dp[i] = dp[curPower] + dp[i-curPower];
        }
    }
    return dp;
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    int num;
    cin >> num;
    res = countBits(num);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
