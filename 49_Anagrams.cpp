#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<string> > anagrams(vector<string> &strs){
    vector<vector<string> > res;
    if(strs.size() <= 1){
        res.push_back(strs);
        return res;
    }
    
    unordered_map<string, multiset<string> > hash;
    for (int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        //if(hash.count(temp) ==0){
            hash[temp].insert(strs[i]);
        //}else if(hash.count(temp) > 0){
        //    hash[temp].first.insert(strs[i]);
        //}
    }

    for(auto it = hash.begin(); it != hash.end(); ++it){
        vector<string> temp((it->second).begin(), (it->second).end());
        res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string> > res = anagrams(strs);
    cout << "result: " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j <res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

