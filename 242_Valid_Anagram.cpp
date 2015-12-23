#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t){
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i++)
        hash[s[i]]++;
    
    for (int i = 0; i < t.size(); i++) 
        hash[t[i]]--;
    
    for(unordered_map<char, int>::iterator it = hash.begin(); 
        it != hash.end(); 
        ++it){
        if(it->second != 0)
            return false;
    }
    return true;
}

bool isAnagram2(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main(int argc, const char *argv[])
{
    cout << isAnagram2("rat", "car") << endl;
    return 0;
}
