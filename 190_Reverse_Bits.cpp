#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    if(n == 0)
        return n;
    string binaryStr;
    while(n != 0){ 
        binaryStr += n%2 + '0';
        n /= 2;
    }   
    
    reverse(binaryStr.begin(), binaryStr.end());
    while(binaryStr.size() < 32){
        binaryStr = '0' + binaryStr;
    }   

    uint32_t res = 0;
    uint32_t temp = 1;
    for (int i = 0; i < binaryStr.size(); i++) {
        if(binaryStr[i] == '1')
            res += temp;
        temp *= 2;
    }   
    
    return res;
}

uint32_t reverseBits2(uint32_t n){
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res <<= 1;
        res += n & 1;
        n >>= 1;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    uint32_t a = 43261596;
    cout << reverseBits(a) << endl;
    return 0;
}
