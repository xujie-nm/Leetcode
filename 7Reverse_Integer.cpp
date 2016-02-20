#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
    if(x < 10 && x > -10)
        return x;
    int res = 0;
    vector<int> res_nums;
    while(x != 0){
        res_nums.push_back(x%10);
        x /= 10;
    }
    if(res_nums.size() == 10){
        if(res_nums[0] >2 || res_nums[0] < -2)
            return 0;   
        else if(res_nums[0] == 2 || res_nums[0] == -2){
            int temp = 0;
            for(vector<int>::iterator it = res_nums.begin() + 1; it != res_nums.end(); ++it){
                temp *= 10;
                temp += *it;
            }
            if(temp > 147483647 || temp < -147483648)
            return 0;
        }
    }
    for(vector<int>::iterator it = res_nums.begin(); it != res_nums.end(); ++it){
        res *= 10;
        res += *it;
    }
    return res;
}


// easier way
int reverse1(int x){
    int res = 0;
    while(x){
        int temp = res*10 + x%10;
        if(temp/10 != res) // 检查这个数是否越界
            return 0;
        res = temp;
        x /= 10;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    cout << reverse(1234) << endl;
    cout << reverse(-1234) << endl;
    cout << reverse1(1234) << endl;
    cout << reverse1(-1234) << endl;
    return 0;
}
