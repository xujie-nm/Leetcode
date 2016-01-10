#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 没想到有log10这个函数啊
bool isPowerOfThree(int n){
   if(n <= 0) 
       return false;
   double x = log10(n) / log10(3);
   return x == floor(x);
}

// 递归
bool isPowerOfThree2(int n){
    if(n == 3 || n == 1)
        return true;
    if(n == 0 || n%3 != 0)
        return false;
    return isPowerOfThree(n/3);
}

int main(int argc, const char *argv[])
{
    cout << isPowerOfThree(1) << endl; 
    cout << isPowerOfThree2(1) << endl; 
    cout << isPowerOfThree(3) << endl; 
    cout << isPowerOfThree2(3) << endl; 
    cout << isPowerOfThree(27) << endl; 
    cout << isPowerOfThree2(27) << endl; 
    cout << isPowerOfThree(6) << endl; 
    cout << isPowerOfThree2(6) << endl; 
    return 0;
}
