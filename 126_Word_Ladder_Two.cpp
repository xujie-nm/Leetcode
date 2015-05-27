#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

int same(string a, string b){
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] != b[i])
            count++;
        if(count == 2)
            break;
    }
    return count;
}

void helper(string cur, string end, unordered_set<string> &dict, set<string> &used, vector<string> temp, 
        vector<vector<string> > &res){
    if(same(cur, end) == 1){
        temp.push_back(end);
        if(!res.empty()){
            if(temp.size() < res.back().size()){
                res.pop_back();
                res.push_back(temp);
            }else if(temp.size() == res.back().size())
                res.push_back(temp);
        }else
            res.push_back(temp);

        return;
    }

    for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
        if(used.count(*it) == 0){
            if(same(cur, *it) == 1){
                used.insert(*it);
                temp.push_back(*it);
                helper(*it, end, dict, used, temp, res);
                temp.pop_back();
                used.erase(*it);
            }
        }
    }
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
    set<string> used;
    vector<vector<string> > res;
    vector<string> temp;
    temp.push_back(start);
    helper(start, end, dict, used, temp, res);
    return res;
}

int main(int argc, const char *argv[])
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    vector<vector<string> > res;
    res = findLadders(start, end, dict);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
