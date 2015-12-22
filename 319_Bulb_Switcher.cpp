#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int bulbSwitch(int n){
    return (int)sqrt(n);
}

int main(int argc, const char *argv[])
{
    cout << bulbSwitch(9) << endl;
    return 0;
}
