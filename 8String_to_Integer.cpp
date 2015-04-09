#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int atoi(const char *str) {
            int res = 0;
            int positive = 1;
            int positive_num = 0;
            bool start = false;
            vector<int> res_nums;
            while(*str != '\0'){
                if(*str == ' ' && !start){
                    str++;
                    continue;
                }
                if(*str == '-'){
                    positive = -1;
                    positive_num++;
                    start = true;
                }
                else if(*str == '+'){
                    positive = 1;
                    positive_num++;
                    start = true;
                }
                else if(positive_num > 1)
                    break;
                else if(*str >= '0' && *str <= '9'){
                    res_nums.push_back(*str - 48);
                    start = true;   
                }
                else
                    break;
                str++;
            }
    
            if(res_nums.size() == 10){
                if(res_nums[0] >2)
                    return 0;
                else if(res_nums[0] == 2){
                    int temp = 0;
                    for(vector<int>::iterator it = res_nums.begin() + 1; it != res_nums.end(); ++it){
                        temp *= 10;
                        temp += (*it) * positive;
                    }
                    if(temp > 147483647)
                        return 2147483647;
                    else if(temp < -147483648)
                        return -2147483648;
                    }
            }
            else if(res_nums.size() > 10){
                if(positive == 1)
                    return 2147483647;
                else
                    return -2147483648;
            }
            for(vector<int>::iterator it = res_nums.begin(); it != res_nums.end(); ++it){
                res *= 10;
                res += (*it) * positive;
            }
            return res;
        }
};


int main(int argc, const char *argv[])
{
    
    return 0;
}
