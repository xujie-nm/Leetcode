#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_i_subset(vector<vector<int> > &res, vector<int> &temp, vector<int> &S, int len, int cur){
    if(temp.size() == len){
        res.push_back(temp);
        return;
    }

    for (int i = cur; i < S.size(); i++) {
        if(i>cur && S[i] == S[i-1])continue;
        temp.push_back(S[i]);
        get_i_subset(res, temp, S, len, i + 1);
        temp.pop_back();
    }
}

vector<vector<int> > subsetWithDup(vector<int> &S){
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    for (int i = 0; i < S.size(); i++) {
        vector<int> temp;
        get_i_subset(res, temp, S, i, 0);
    }
    res.push_back(S);
    
    
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(2);
    vector<vector<int> > res;
    res = subsetWithDup(S);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";   
        }
        cout << endl;
    }
    
    
    return 0;
}
