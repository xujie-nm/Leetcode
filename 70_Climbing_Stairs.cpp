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

// simpier and faster
int climbStairs2(int n){
    if(n <= 2)
        return n;
    vector<int> temp(n, 0);
    temp[0] = 1;
    temp[1] = 2;

    for (int i = 2; i < n; i++) {
        temp[i] = temp[i-1] + temp[i-2];
    }
    return temp[n-1];
}

int main(int argc, const char *argv[])
{
    cout << climbStairs(1) << endl;
    cout << climbStairs2(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs2(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs2(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs2(4) << endl;
    cout << climbStairs(5) << endl;
    cout << climbStairs2(5) << endl;
    cout << climbStairs(6) << endl;
    cout << climbStairs2(6) << endl;
    cout << climbStairs(7) << endl;
    cout << climbStairs2(7) << endl;
    return 0;
}
