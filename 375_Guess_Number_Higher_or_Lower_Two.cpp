#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getMoneyAmount(int iN)
{
    vector<vector<int> > dp(iN + 2, vector<int>(iN+2, 0));
    for (int i = 0; i <= iN; i++) 
    {
        for (int j = i-1; j >= 1; j--) 
        {
            int iMinValue = INT_MAX;
            for (int k = j; k <= i; k++) 
            {
                int iTmp = k + max(dp[j][k-1], dp[k+1][i]);
                iMinValue = min(iMinValue, iTmp);
            }
            dp[j][i] = iMinValue;
        }    
    }

    return dp[1][iN];
}

int main(int argc, const char *argv[])
{
    int i = 0;
    while(cin >> i)
    {
        cout << getMoneyAmount(i) << endl;
    }
    return 0;
}
