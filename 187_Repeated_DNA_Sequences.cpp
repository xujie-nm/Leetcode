#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<string> findRepeatedDnaSequences(string s){
    vector<string> res;
    if(s.size() < 11)
        return res;

    set<string> strings;

    for (int i = 0; i < s.size()-9; i++) {
        string temp = s.substr(i, 10);
        if(strings.count(temp) > 0){
            res.push_back(temp);
        }else{
            strings.insert(temp);
        }
    }
    
    return res;
}
//Memory limit exceeded

vector<string> findRepeatedDnaSequences2(string s){
    vector<string> res;
    if(s.size() < 11)
        return res;
    unordered_map<char, int> map;
    map['A'] = 1;
    map['C'] = 2;
    map['G'] = 3;
    map['T'] = 4;
    unordered_map<int, int> hash;

    for (int i = 0; i < s.size()-9; i++) {
        string temp = s.substr(i, 10);
        int index = 0;
        for (int j = 0; j <temp.size(); j++) {
            index *= 10;
            index += map[temp[j]];
        }
        if(hash.find(index) != hash.end()){
            if(hash[index] == 1){
                res.push_back(temp);
                hash[index]++;
            }
        }
        else
            hash[index] = 1;
    }
    
    return res;
}

//ac

int main(int argc, const char *argv[])
{
    string s = "AAAAAAAAAAAA";

    vector<string> res;
    res = findRepeatedDnaSequences2(s);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    
    return 0;
}
