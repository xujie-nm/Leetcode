#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countDigitOne(int n){
    if(n < 1)
        return 0;
    if(n >= 1 && n < 10)
        return 1;
    int tens = 1, temp = n;
    while(temp >= 10){
        temp /= 10;
        tens *= 10;
    }
    if(temp == 1)
        //如果最高位是1
        //结果就是小于1^tens数的1加上余数的1
        //再加上每个余数对应的1
        return n-tens+1+countDigitOne(tens-1) + countDigitOne(n % tens);
    else
        //如果最高位不是1
        //不同的temp的1加上余数的1
        //这里的tens还是余数对应的那些1
        return tens + temp*countDigitOne(tens-1) + countDigitOne(n % tens);
}

int main(int argc, const char *argv[])
{
    int n = 13;
    cout << countDigitOne(n) << endl;
    return 0;
}
