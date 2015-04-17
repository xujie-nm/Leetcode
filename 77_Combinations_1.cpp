#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(int n, int k, vector<vector<int> > &res, vector<int> &tmp, int ind){
    if(k==0)
        res.push_back(tmp);
    else{
        for (int i = ind; i <= n; i++) {
            tmp.push_back(i);
            helper(n, k-1, res, tmp, i+1);
            tmp.pop_back();
        }
    }
}

vector<vector<int> > combine(int n, int k){
    vector<vector<int> > res;
    vector<int> temp;
    helper(n, k, res, temp, 1);
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
