#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
    public:
        string longestPalindrom(string s)
        {
            if(s.size() < 2)
                return s;
            int pos = 0, length = 2;
            int max_length = 0;
            int max_pos;
            bool flag = true;
            while(1)
            {
                int i = pos, j = pos + length - 1;
                while(i < j)
                {
                    if(s[i] != s[j])
                    {
                        flag = false;
                        break;
                    }
                    i++;
                    j--;
                }
                if(flag)
                {
                    max_length = length;
                    max_pos = pos;
                }
                if(pos + length < s.size())
                {
                    length++;
                }
                else
                {
                    pos++;
                    length = max_length;
                    if(pos >= s.size() - 1 || pos + length >= s.size() - 1)
                        break;
                }
                flag = true;
            }
            return s.substr(max_pos, max_length);
        }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
