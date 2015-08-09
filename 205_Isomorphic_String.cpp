#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool isIsomorphic(string s, string t){
    if(s.size() != t.size())
        return false;

    unordered_map<char, set<int> > hashs;

    for (int i = 0; i < s.size(); i++)
        hashs[s[i]].insert(i);

    for(unordered_map<char, set<int> >::iterator it = hashs.begin(); it != hashs.end(); ++it){
        if((it->second).size() == 1)
            continue;
        else{
            int temp = *((it->second).begin());
            for(set<int>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); ++it1){
                if(t[temp] != t[*it1]) 
                    return false;
            }
        }
    }
    
    unordered_map<char, set<int> > hasht;

    for (int i = 0; i < t.size(); i++)
        hasht[t[i]].insert(i);

    for(unordered_map<char, set<int> >::iterator it = hasht.begin(); it != hasht.end(); ++it){
        if((it->second).size() == 1)
            continue;
        else{
            int temp = *((it->second).begin());
            for(set<int>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); ++it1){
                if(s[temp] != s[*it1]) 
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << isIsomorphic("egg", "add") << endl;    
    cout << isIsomorphic("foo", "bar") << endl;    
    cout << isIsomorphic("paper", "title") << endl;    
    cout << isIsomorphic("ab", "aa") << endl;    
    return 0;
}
