#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPowerOfTwo(int n){//把前面的零都消除，留第一个出现的一
    if(n <= 0)
        return false;

    while((n & 1) != 1 && n > 0){
        n = n >> 1;
    }
    return n == 1;
}

bool isPowerOfTwo(int n){
    if(n <= 0)
        return false;
    return (n & (n-1)) == 0;
}

int main(int argc, const char *argv[])
{
    cout << isPowerOfTwo(4) << endl;
    cout << isPowerOfTwo(6) << endl;
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(5) << endl;
    return 0;
}
