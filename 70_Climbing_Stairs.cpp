#include <iostream>
#include <string>
#include <vector>
using namespace std;

int climbStairs(int n){
    if(n <= 2)
        return n;
    vector<vector<int> > temp(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j <= i; j++) {
            if(i-j <= 2)
                temp[i][j] = i-j;
            else
                temp[i][j] = temp[i-1][j] + temp[i-1][j+1];
        }
    }
    
    return temp[n][0];
}

int main(int argc, const char *argv[])
{
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
    cout << climbStairs(6) << endl;
    cout << climbStairs(7) << endl;
    return 0;
}
