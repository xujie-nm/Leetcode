#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

//Catalan Number

long int numTrees(int n){
    if(n==1 || n==0)
        return 1;
    vector<long int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    
    for (int i = 2; i < n+1; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[i-j-1];   
        }
    }
    return dp[n];
}

long int numTrees2(int n){
    if(n == 0 || n == 1)
        return 1;
    double res= 1.0;
    for (int i = 2; i <= n; i++) {
        res *= (double)(n+i)/i;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    
    int i = 1;
    int up = atoi(argv[1]);
    while(i <= up){
        if(numTrees(i) == numTrees2(i))
            cout << "true" << endl;
        else{
            cout << "false" << endl;
        }
            
        i++;
    }

    return 0;
}
