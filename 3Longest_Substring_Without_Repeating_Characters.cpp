#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int i = 0, j = 0;
    int maxLen = 0;
    bool exist[256] = { false };
    while (j < n) {
        if (exist[s[j]]) {
            maxLen = max(maxLen, j-i);
            while (s[i] != s[j]) {
                exist[s[i]] = false;
                i++;
            }
            i++;
            j++;
            } else {
                exist[s[j]] = true;
                j++;
            }
    }
    maxLen = max(maxLen, n-i);
    return maxLen;
}

int lengthOfLongestSubstring(string s){
    int n = s.size();
    if(n == 0)
        return 0;
    int start = 0;
    int maxLen = 0;
    map<char, int> hash;
    for (int i = 0; i < n; i++) {
        if(hash.find(s[i]) != hash.end)
            start = max(start, hash[s[i]]+1);
        
        if(i-start+1 > maxLen)
            maxLen = i-start+1;
        hash[s[i]] = i;
    }
    return maxLen;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
