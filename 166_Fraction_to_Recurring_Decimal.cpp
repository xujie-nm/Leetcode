#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string itoa(long long num){
    string str;
    while(num){
        str += (num % 10 + '0');
        num /= 10;
    }
    if(str.empty())
        return "0";
    reverse(str.begin(), str.end());
    return str;
}

string fractionToDecimal(int numerator, int denominator){
    if(numerator == 0)
        return "0";
    string res;
    if(numerator < 0 ^ denominator < 0)
        res += '-';
    long long numer = numerator < 0 ? (long long)numerator * (-1) : (long long)numerator;
    long long denom = denominator < 0 ? (long long)denominator * (-1) : (long long)denominator;
    long long integer = numer / denom;
    res += itoa(integer);
    long long remain = numer - integer * denom;
    if(remain == 0)
        return res;
    res += '.';
    remain *= 10;
    unordered_map<long long, long long> mp;
    while(remain){
        long long quotient = remain / denom;
        if(mp.find(remain) != mp.end()){
            //这里是判断这个数字师傅出现过
            //如果出现过，那么说明就是循环了
            //则在res这个数字开始的位置插入‘(’
            //在末尾插入')',跳出循环
            res.insert(mp[remain], 1, '(');
            res += ')';
            break;
        }
        mp[remain] = res.size();
        //记录当前位置
        res += itoa(quotient);
        remain -= denom * quotient;
        remain *= 10;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    cout << fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
