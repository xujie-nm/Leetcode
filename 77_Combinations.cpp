#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool helper(vector<vector<int> > &res, vector<int> &temp, vector<bool> &flag, int n, int k){
    if(temp.size() == k){
        res.push_back(temp);
        return true;
    }else if(temp.size() > k)
        return false;
    
    for (int i = 0; i < n; i++) {
        if(!flag[i] && (temp.empty() || i > (temp.back()-1))){
            flag[i] = true;
            temp.push_back(i+1);
            helper(res, temp, flag, n, k);
            temp.pop_back();
            flag[i] = false;
        }
    }
}

vector<vector<int> > combine(int n, int k){
    vector<vector<int> > res;
    vector<int> temp;
    vector<bool> flag(n, false);
    helper(res, temp, flag, n, k);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > res;
    res = combine(4, 2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
