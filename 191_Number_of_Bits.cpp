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

int main(int argc, const char *argv[])
{
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    return 0;
}
