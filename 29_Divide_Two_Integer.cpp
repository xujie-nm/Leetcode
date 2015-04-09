#include <iostream>
#include <string>
#define MAX_INT 0x7FFFFFFF
#define MIN_INT 0X80000000
using namespace std;

int divide(int dividend, int divisor){
    long didd = dividend > 0 ? (long)dividend : -((long)dividend);
    long dior = divisor > 0 ? (long)divisor : -((long)divisor);
    long sign = ((dividend < 0) ^ (divisor < 0)) ? -1: 1;

    if(dior == 0 || dividend == MIN_INT && divisor == -1){
        return MAX_INT;
    }
    else if(dior == 1){
        if(sign == -1)
            return -didd;
        else
            return didd;
    }

    long res = 0;
    int i = 0;
    while(didd >= dior){
        i = 0;
        while(didd >= dior << i){
            didd -= dior << i;
            res += 1<<i;
            i++;
        }
    }

    if(sign == -1)
        return -res;
    else
        return res;
}

int main(int argc, const char *argv[])
{
    cout << divide(24, 6) << endl; 
    cout << divide(24, 5) << endl; 
    cout << divide(24, 4) << endl; 
    cout << divide(24, 3) << endl; 
    cout << divide(24, 2) << endl; 
    cout << divide(24, 1) << endl; 
    cout << divide(0, 1) << endl; 
    cout << divide(24, 0) << endl; 
    cout << divide(0, 0) << endl; 
    cout << "test is : "<<divide(-2147483648, 2) << endl; 
    return 0;
}
