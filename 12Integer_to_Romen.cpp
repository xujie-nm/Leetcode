#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            vector<string> res_nums;
            string res;
            int i = 0;
            string unit[][9] = {{"I", "II", "III", "IV","V", "VI", "VII", "VIII", "IX"},
                               {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"M", "MM", "MMM"}};
            while(num != 0){   
                int temp = num % 10; 
                if(temp != 0)
                    res_nums.push_back(unit[i][temp - 1]);
                num /= 10; 
                i++;
            }   
                                                                                       
            for(vector<string>::reverse_iterator it = res_nums.rbegin(); it != res_nums.rend(); ++it){
                res += *it;
            }   
            return res;
    
        }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
