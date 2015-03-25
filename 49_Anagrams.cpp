#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map> 
using namespace std;

vector<string> anagrams(vector<string> &strs){
    vector<string> res;
    if(strs.size() <= 1)
        return res;
    map<string, pair<string, int> > hash;
    for (int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if(hash.count(temp) ==0){
            hash[temp].first = strs[i];
            hash[temp].second += 1;
        }else if(hash.count(temp) > 0){
            res.push_back(strs[i]);
            hash[temp].second +=1;
        }
    }

    for(map<string, pair<string, int> >::iterator it = hash.begin(); it != hash.end(); ++it){
        if(it->second.second > 1)
            res.push_back(it->second.first);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> strs;
    strs.push_back("tea");
    strs.push_back("tae");
    strs.push_back("eat");
    strs.push_back("eta");
    strs.push_back("pen");
    strs.push_back("pne");
    strs.push_back("end");
    vector<string> res = anagrams(strs);
    cout << "result: " << endl;
    for(vector<string>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}

