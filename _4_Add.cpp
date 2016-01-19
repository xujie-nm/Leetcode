#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// 计算两个数的和
/// 不使用+，-，*，/，来实现

int add(int num1, int num2){
    int sum, carry;
    do{
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    }while(num2 != 0);

    return num1;
}

int main(int argc, const char *argv[])
{
    cout << add(10, 6) << endl;
    cout << add(3, 6) << endl;
    cout << add(3, 4) << endl;
    cout << add(123, 346) << endl;
    return 0;
}
