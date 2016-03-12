#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(vector<vector<int> > &res, vector<int> &can, vector<int> &sol, int pos, int tar){
    if(tar < 0 )
        return false;
    else if(tar == 0){
        res.push_back(sol);
        return true;
    }
    else{
        for (int i = pos; i < can.size(); i++) {
            if(can[i] > tar)
                return false;
            if(i > pos && can[i] == can[i - 1])
                continue;

            sol.push_back(can[i]);
            // 这里与39不一样
            solve(res, can, sol, i+1, tar - can[i]);
            sol.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target){
    vector<vector<int> > res;
    vector<int> temp;
    if(candidates.size() == 0)
        return res;

    sort(candidates.begin(), candidates.end());
    solve(res, candidates, temp, 0, target);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > res;
    vector<int> can;
    can.push_back(10);
    can.push_back(1);
    can.push_back(2);
    can.push_back(7);
    can.push_back(6);
    can.push_back(1);
    can.push_back(5);
    res = combinationSum(can, 9);
    
    for(vector<vector<int> >::iterator it_temp = res.begin(); it_temp != res.end();
            ++it_temp){
        for(vector<int>::iterator it = (*it_temp).begin(); it != (*it_temp).end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
