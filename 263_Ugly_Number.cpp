#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isUgly(int num){
    if(num == 1)
        return true;
    if(num <= 0)
        return false;
    while(num != 1){
        if(num % 2 == 0)
            num /= 2;
        else if(num % 3 == 0)
            num /= 3;
        else if(num % 5 == 0)
            num /= 5;
        else{
            if(num == 1)
                continue;
            else
                return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << isUgly(14) << endl;
    cout << isUgly(28) << endl;
    cout << isUgly(15) << endl;

    return 0;
}
