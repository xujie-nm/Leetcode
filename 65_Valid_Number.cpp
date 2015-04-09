#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isNumber(string s){
    int n = s.size();
    int i = 0;
    bool left = true;
    //去除首尾的空格
    while(i < n && s[i] == ' ')
        i++;
    while(n > 0 && s[n-1] == ' ')
        n--;
    //在第一个数字之前可能是正负号
    if(s[i] == '+' || s[i] == '-')
        i++;
    //开始的第一个元素可能是。，也有可能是数字，
    //但不能是e
    if(s[i] == '.')
        left = false;
    else if(s[i] < '0' || s[i] > '9')
        return false;
    else
        while(s[i] >= '0' && s[i] <= '9')
            i++;

    //这里已经跳过了前面所有的数字
    //下一步可能是。，可能是e
    //如果是e则后面肯定是数字
    //处理数字
    if(s[i] == 'e'){
        i++;
        if(s[i] == '+' || s[i] == '-')
            i++;
        if(i >= n || s[i] == ' ')
            return false;
        while(s[i] >= '0' && s[i] <= '9')
            i++;
    }else if(s[i] == '.'){
    //后面出现小数
    //在。的左右可能一边是空的，left的作用就是这个
    //在。的右边如果左为空，那么右边肯定是数字
    //如果左不空，那么右边可能空，可能不空
        i++;
        if((s[i] < '0' || s[i] > '9') && !left)
            return false;
        while(s[i] >= '0' && s[i] <= '9')
            i++;
        if(s[i] == 'e'){
        //后面又出现e，处理后面的数字
            i++;
            if(s[i] == '+' || s[i] == '-')
                i++;
            if(i >= n || s[i] == ' ')
                return false;
            while(s[i] >= '0' && s[i] <= '9')
                i++;
        }
    }
    //如果没有到尾说明中间出错，返回false
    if(i<n)
        return false;
    return true;
}

int main(int argc, const char *argv[])
{
    cout << isNumber("0") << endl;
    cout << isNumber(" 0.1") << endl;
    cout << isNumber("abc") << endl;
    cout << isNumber("1 a") << endl;
    cout << isNumber("2e10") << endl;
    return 0;
}
