#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rangeBitwiseAnd(int m, int n){
    if(m == n)
        return m;

    int res = 0;
    for (int i = 0; i <= 30; i++) {
    //遍历，每一位；如果m,n都有这一位
    //并且，两个数相差的最高位开始
        if(m & (1 << i) && n & (1 << i) && (n-m+1) <= (1 << i)){
            res |= (1 << i);
        }
    }

    return res;
}

//好理解的
int rangeBitwiseAnd2(int m, int n){
    int res = 0;
    int i = 1;
    i <<= 30;
    while(i > 0){
        if((i & m) != (i & n)){
            break;
        }else if((i & m) != 0){
            res |= i;
        }
        i >>= 1;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    cout << rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
