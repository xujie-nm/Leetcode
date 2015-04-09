#include <iostream>
#include <map>
#include <vector>

using namespace std;

static map<char, int> unit;
class Solution {
    public:
        int romanToInt(string s) {
            unit['I'] = 1;
            unit['V'] = 5;
            unit['X'] = 10; 
            unit['L'] = 50; 
            unit['C'] = 100;
            unit['D'] = 500;
            unit['M'] = 1000;
            char prior = 'I';
            int res = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if(unit[s[i]] >= unit[prior])
                    res += unit[s[i]];
                else
                    res -= unit[s[i]];                                                                                  
                prior = s[i];
            }   
            return res;
        }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
