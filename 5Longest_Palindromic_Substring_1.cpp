#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.size()==0)
                return "";
            int maxLength= 1 ;
            string result=s.substr(0,1); 
            for (int i =0; i<s.size()-1; i++) {
                int count = 0;
                while (i-count>=0 && i+count<=s.size()-1) {
                    if (s[i-count]==s[i+count])
                        count++;
                    else
                        break;
                }
                count--;
                if (count*2+1>=maxLength) {
                    maxLength = count*2+1;
                    result = s.substr(i-count,count*2+1);
                }
                int count2 = 0;
                while (i-count2>=0 && i+count2+1<=s.size()-1) {
                if(s[i-count2]==s[i+1+count2])
                    count2++;
                else
                    break;
                }
                if(count2*2>=maxLength) {
                    maxLength = count2*2;
                    result = s.substr(i+1-count2, count2*2);
                }
            }
            return result;
    
        }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
