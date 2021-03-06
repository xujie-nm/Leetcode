#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_i_subset(vector<vector<int> >&res, vector<int> &temp, vector<int> &S, int sub_len, int ind){
    if(temp.size() == sub_len){
        res.push_back(temp);
        return;
    }
    for (int i = ind; i < S.size(); i++) {
        temp.push_back(S[i]);
        get_i_subset(res, temp, S, sub_len, i + 1);
        temp.pop_back();
    }
}


vector<vector<int> > subsets(vector<int> &S){
    vector<vector<int> >res;
    sort(S.begin(), S.end());
    for (int i = 0; i < S.size(); i++) {
        vector<int> temp;
        get_i_subset(res, temp, S, i, 0);
    }
    res.push_back(S);
    return res;
}

// Faster
void get_i_subset2(vector<vector<int> > &res, vector<int> &temp, vector<int> &S, int sub_len, int ind){
    if(sub_len == 0){
        res.push_back(temp);
        return;
    }
    for (int i = ind; i < S.size() - sub_len + 1; i++) {
        temp[temp.size() - sub_len] = S[i];
        get_i_subset2(res, temp, S, sub_len-1, i+1);
    }
}

vector<vector<int> > subsets2(vector<int> &S){
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    for (int i = 0; i <= S.size(); i++) {
        vector<int> temp(i);
        get_i_subset2(res, temp, S, i, 0);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> S;
    S.push_back(4);
    S.push_back(1);
    S.push_back(0);

    vector<vector<int> > res;
    res = subsets2(S);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
