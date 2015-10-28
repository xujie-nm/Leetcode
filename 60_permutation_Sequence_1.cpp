#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// faster
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

// backtracking
// faster
void helper(string& res, string str, int k, int fac, int i){
    if(i == 0){
        res += str;
        return;
    }
    int pos = (k-1)/fac;
    // 计算位置
    k = (k-1)%fac+1;

    res += str[pos];
    // 取出当前位置的数字
    str = str.substr(0, pos) + str.substr(pos+1, str.size()-pos-1);
    // 重新处理字符串

    fac /= i;
    helper(res, str, k, fac, i-1);
}

string getPermutation2(int n, int k){
    string str;
    for (int i = 1; i <= n; i++) {
        str += char(i + '0');
    }
    string res;
    int fac = 1;
    int i = 1;
    while(i < n-1){
        i++;
        fac *= i;
    }
    helper(res, str, k, fac, i);
    return res;
}

// practice permutation 
// TLE

void helper(vector<string> &res, vector<bool> &flag, int n, int k,  string str){
    if(res.size() >= k)
        return;
    if(str.size() == n){
        res.push_back(str);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if(!flag[i-1]){
            str+= char(i + '0');
            flag[i-1] = true;
            helper(res, flag, n, k, str);
            flag[i-1] = false;
            str = str.substr(0, str.size()-1);
        }
    }
}

string generatePermutation(int n, int k){
    vector<string> res;
    vector<bool> flag(n, false);
    string str;
    helper(res, flag, n, k, str);
    return res[k-1];
}

int main(int argc, const char *argv[])
{
    cout << "first: " << getPermutation(3, 1) << endl;
    cout << "second: " << getPermutation2(3, 1) << endl;
    cout << "first: " << getPermutation(3, 2) << endl;
    cout << "second: " << getPermutation2(3, 2) << endl;
    cout << "first: " << getPermutation(3, 3) << endl;
    cout << "second: " << getPermutation2(3, 3) << endl;
    cout << "first: " << getPermutation(3, 4) << endl;
    cout << "second: " << getPermutation2(3, 4) << endl;
    cout << "first: " << getPermutation(3, 5) << endl;
    cout << "second: " << getPermutation2(3, 5) << endl;
    cout << "first: " << getPermutation(3, 6) << endl;
    cout << "second: " << getPermutation2(3, 6) << endl;
    cout << "first: " << getPermutation(8, 8590) << endl;
    cout << "second: " << getPermutation2(8, 8590) << endl;
    
    cout << generatePermutation(3, 1) << endl;
    cout << generatePermutation(3, 2) << endl;
    cout << generatePermutation(3, 3) << endl;
    cout << generatePermutation(3, 4) << endl;
    cout << generatePermutation(3, 5) << endl;
    cout << generatePermutation(3, 6) << endl;
    cout << generatePermutation(9, 273815) << endl;
    return 0;
}
