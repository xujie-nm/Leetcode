#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ac
vector<string> findRepeatedDnaSequences(string s){
    unordered_set<string> res;
    if(s.size() < 11)
        return vector<string> (res.begin(), res.end());

    unordered_set<string> strings;

    for (int i = 0; i < s.size()-9; i++) {
        string temp = s.substr(i, 10);
        if(strings.find(temp) != strings.end()){
            res.insert(temp);
        }else{
            strings.insert(temp);
        }
    }
    
    return vector<string> (res.begin(), res.end());
}

// 用一个新的哈希函数
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
            // 根据这个子串生成一个哈希值
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

// bit manipulation
vector<string> findRepeatedDnaSequences3(string s){
    vector<string> res;
    if(s.size() < 11)
        return res;

    int mask = 0x3ffff; // 用于取一个int数的低18位
    vector<int> map(1024*1024, 0);

    unsigned int cur = 0, i = 0;

    while(i < 9) {// 取18位
        switch(s[i]){
            case 'A':
                cur = (cur << 2) | 0;
                break;
            case 'C':
                cur = (cur << 2) | 1;
                break;
            case 'G':
                cur = (cur << 2) | 2;
                break;
            case 'T':
                cur = (cur << 2) | 3;
                break;
        }
        i++;
    }

    while(i < s.size()){
        switch(s[i]){
            case 'A':
                cur = ((cur & mask) << 2 | 0); // 取原来字符的18位后再接上新字符的新两位
                break;
            case 'C':
                cur = ((cur & mask) << 2 | 1);
                break;
            case 'G':
                cur = ((cur & mask) << 2 | 2);
                break;
            case 'T':
                cur = ((cur & mask) << 2 | 3);
        }
        i++;
        map[cur]++;

        // 防止结果重复
        if(map[cur] == 2)
            res.push_back(s.substr(i-10, 10));
    }

    return res;
}

int main(int argc, const char *argv[])
{
    string s = "AAAAAAAAAAAA";

    vector<string> res;
    res = findRepeatedDnaSequences3(s);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    
    return 0;
}
