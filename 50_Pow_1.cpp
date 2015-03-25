#include <iostream>
#include <string>
#include <vector>
using namespace std;

double po(double x, int n){
    double res = 1;
    while(n > 0 ){
        res *= x;
        n--;
    }
    return res;
}

double pow(double x, int n){
    if(n < 0) 
        return 1.0/po(x, -n);
    else 
        return po(x, n);
}

int main(int argc, const char *argv[])
{
    cout << pow(2, 6) << endl;
    cout << pow(2, -6) << endl;
    cout << pow(2, 2) << endl;
    cout << pow(2, -2) << endl;
    cout << pow(2, 0) << endl;

    return 0;
}
