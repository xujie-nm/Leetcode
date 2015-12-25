#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

int hammingWeight(uint32_t n){
    int res = 0;
    while(n != 0){
        if(n %2 == 1)
            res++;
        n /= 2;
    }
    return res;
}

// 如果n是负数就麻烦了
int hammingWeight2(uint32_t n){
    int res = 0;
    while(n != 0){
        if((n & 1) == 1)
            res++;
        n >>= 1;
    }
    return res;
}

// 不会有负数的问题
int hammingWeight3(uint32_t n){
    int res = 0;
    uint32_t flag = 1;
    while(flag != 0){
        if((n & flag) != 0)
            res++;
        flag <<= 1;
    }
    return res;
}

// 把一个整数减一，再和原整数做与运算，会把该整数最右边一个1变成0
// 那么一个整数二进制中有多少个一，就做这样多少次运算
int hammingWeight4(uint32_t n){
    int res = 0;
    while(n != 0){
        ++res;
        n &= (n-1);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    cout << hammingWeight2(n) << endl;
    cout << hammingWeight3(n) << endl;
    cout << hammingWeight4(n) << endl;
    return 0;
}
