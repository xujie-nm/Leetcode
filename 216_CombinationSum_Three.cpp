#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool backtracking(vector<vector<int> > &res, vector<int> &temp, set<int> &visited, int num, int tar, int curSum){
    if(curSum > tar || temp.size() > num)
        return false;
    if(curSum == tar){
        if(temp.size() == num){
            res.push_back(temp);
            return true;
        }
        return false;
    }

    for (int i = 1; i < 10; i++) {
        if(visited.count(i) == 0 && curSum + i <= tar){
            if(!temp.empty() && i > temp.back()){
                temp.push_back(i);
                visited.insert(i);
                backtracking(res, temp, visited, num, tar, curSum+i);
                visited.erase(i);
                temp.pop_back();
            }else if(temp.empty()){
                temp.push_back(i);
                visited.insert(i);
                backtracking(res, temp, visited, num, tar, curSum+i);
                visited.erase(i);
                temp.pop_back();
            }
        }
    }
}

vector<vector<int> > combinationSum3(int k, int n){
    vector<vector<int> > res;
    vector<int> temp;
    set<int> visited;

    backtracking(res, temp, visited, k, n, 0);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > res;
    res = combinationSum3(3, 9);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
