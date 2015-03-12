#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L){
    vector<int> res;
    if(L.size() == 0) return res;
    if(S.size() == 0) return res;
    int word_size = L[0].size();
    int sum_size = L.size() * word_size;
    if(S.size() < word_size * L.size()) return res;
    //建立hashtables
    map<string, vector<int> > word_indexs;
    for(vector<string>::iterator it = L.begin(); it != L.end(); ++it){
        int temp_index = -1;
        while(1){
            temp_index = S.find(*it, temp_index + 1);
            if(S.size() - temp_index >= sum_size && temp_index != string::npos)
                word_indexs[*it].push_back(temp_index);
            else
                break;
        }
    }
    //把可能的字符串切出來
    map<int, string> substrings;
    for(map<string, vector<int> >::iterator it = word_indexs.begin(); it != word_indexs.end(); ++it){
        for(vector<int>::iterator temp_it = it->second.begin(); temp_it != it->second.end(); ++temp_it){
            string temp_S = S;
            substrings.insert(make_pair(*temp_it,temp_S.substr(*temp_it, sum_size)));
        }
    }
    //判斷字符串是否匹配
    for(map<int, string>::iterator it = substrings.begin(); it != substrings.end(); ++it){
        vector<string> temp_L(L);
        for (int i = 0; i < it->second.size(); i+= word_size) {
            string sub = it->second.substr(i, word_size);
            vector<string>::iterator iter = find(temp_L.begin(), temp_L.end(), sub);
            if(iter != temp_L.end())
                temp_L.erase(iter);
        }
        if(temp_L.empty())
            res.push_back(it->first);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    res = findSubstring(S, L);
    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
