#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getPermutation(int n, int k){
    if(--k < 0) return "";

    string str(n, '0');

    vector<bool> vis(n+1, false);

    int fact[n];
    for (int i = 0; i < n; i++) fact[i] = (i==0 ? 1:i*fact[i-1]);

    //计算最后结果的每一位
    for (int i = 0; i < n; i++) {
        int cur = k/fact[n-1-i];
        //找出当前的匹配位
        k %= fact[n-1-i];
        //为找到下一位做准备
        for (int j = 1, cnt = 0; j <= n; j++) {
            if(!vis[j]){
                if(cnt == cur){
                    str[i] += j; 
                    vis[j] = true;
                    break;
                }
                ++cnt;
            }
        }
    }
        
    return str;
}

int main(int argc, const char *argv[])
{
    cout << getPermutation(3, 1) << endl;
    cout << getPermutation(3, 2) << endl;
    cout << getPermutation(3, 3) << endl;
    cout << getPermutation(3, 4) << endl;
    cout << getPermutation(3, 5) << endl;
    cout << getPermutation(3, 6) << endl;
    cout << getPermutation(8, 8590) << endl;
    return 0;
}
