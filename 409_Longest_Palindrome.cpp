#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> charHash;
    bool hasSingle = false;
    int iLongestLength = 0;
    for (int i = 0; i < s.size(); i++) 
    {
        charHash[s[i]]++;
    }
    
    for(const auto& item : charHash)
    {
        if(item.second >= 2)
        {
            iLongestLength += (item.second/2)*2;
        }

        if((item.second%2==1) && !hasSingle)
        {
            hasSingle = true;
            iLongestLength += 1;
        }
    }
    
    return iLongestLength;
}

int main(int argc, const char *argv[])
{
    cout << longestPalindrome("abccccdd") << endl;
    return 0;
}
