#include <iostream>
#include <string>
#include <vector>
using namespace std;

double power1(double x, unsigned long long n){
    double res = 1;
    while(n > 0 ){
        if(n%2 ==1){
            res *= x;
            n--;
            //如果当前n是奇数
            //说明要开始分叉，所以先把小的那部分送给结果
        }else{
            x *= x;
            n /= 2;
            //如果是偶数，则x变为原来的平方
            //n变为原来的1/2
        }
    }
    return res;
}

double power2(double base, unsigned long long exponent){
    if(exponent == 0)
        return 1;
    else if(exponent == 1)
        return base;
    else{
        double temp = power1(base, exponent/2);
        if(exponent % 2 == 1)
            return temp*temp*base;
        else
            return temp*temp;
    }   
}

double pow(double x, int n){
    if(n < 0) 
        return 1.0/power1(x, -n);
    else 
        return power1(x, n);
}

int main(int argc, const char *argv[])
{
    //cout << pow(2, 6) << endl;
    //cout << pow(2, -6) << endl;
    //cout << pow(2, 2) << endl;
    //cout << pow(2, -2) << endl;
    //cout << pow(2, 0) << endl;
    cout << pow(2, -2147483648) << endl;

    return 0;
}
