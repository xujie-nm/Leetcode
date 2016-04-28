#include <iostream>
#include <string>
#include <vector>
using namespace std;

int integerBreak(int n){
    vector<int> vec(7, 1);
    vec[1] = 1;
    vec[2] = 1;
    vec[3] = 2;
    vec[4] = 4;
    vec[5] = 6;
    vec[6] = 9;
    if(n <= 6)
        return vec[n];

    for (int i = 7; i <= n; i++) {
        vec.push_back(3*vec[i-3]);
    }

    return vec[vec.size()-1];
}

int main(int argc, const char *argv[])
{
    cout << integerBreak(7) << endl;
    cout << integerBreak(8) << endl;
    cout << integerBreak(9) << endl;
    cout << integerBreak(10) << endl;
    cout << integerBreak(11) << endl;
    return 0;
}
