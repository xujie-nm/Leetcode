#include <iostream>
#include <string>
#include <vector>
using namespace std;

//with loop
int addDigits(int num){
    int sum = 0;
    while(num != 0){
        sum += num%10;
        num /= 10;
        if(num == 0){
            if(sum < 10)
                return sum;
            else{
                num = sum;
                sum = 0;
            }
        }
    }
    return sum;
}

//no loop

int addDigits2(int num){
    return num - 9*((num-1)/9);
}

int main(int argc, const char *argv[])
{
    cout << addDigits(38) << endl;
    cout << addDigits2(38) << endl;
    return 0;
}
