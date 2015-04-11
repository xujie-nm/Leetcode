#include <iostream>
using namespace std;

int sqrt(int x){
    if(x == 1)
        return x;
    double lr = double(0);
    double rr = double(x);

    while(lr < rr && (rr - lr > 0.00001)){
        double temp = (lr + rr)/2.0;
        if(temp * temp == x)
            return int(temp);
        else if(temp * temp > x){
            rr = temp;
        }else
            lr = temp;
    }
    return int(rr);
}

int main(int argc, const char *argv[])
{
    cout << sqrt(2147395599) << endl;
    return 0;
}
