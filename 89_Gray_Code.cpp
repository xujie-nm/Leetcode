#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(int n, vector<int> &res){
    if(n == 1){
        res.push_back(0);
        res.push_back(1);
        return ;
    }

    helper(n-1, res);
    int size = res.size() -1;

    for (int i = size; i >= 0; i--) {
        int num = res[i] + (1<<(n-1));
        //新填了一位後把前面的都加上
        res.push_back(num);
    }
}

vector<int> grayCode(int n){
    vector<int> res;
    if(n > 0)
        helper(n, res);
    else
        res.push_back(0);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    res = grayCode(2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
