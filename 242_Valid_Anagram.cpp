#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isAnagram(string s, string t){
    map<char, int> hash;
    for (int i = 0; i < s.size(); i++)
        hash[s[i]]++;
    
    for (int i = 0; i < t.size(); i++) 
        hash[t[i]]--;
    
    for(map<char, int>::iterator it = hash.begin(); it != hash.end(); ++it){
        if(it->second != 0)
            return false;
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << isAnagram("rat", "car") << endl;
    return 0;
}
