#include <iostream>
using namespace std;

int sqrt(int x){
    if(x == 1)
        return x;
    double lr = double(0);
    double rr = double(x);

    while(lr < rr && (rr - lr > 0.00001)){
        // 把这里的 (lr+rr)/2.0 改为 rr + (lr - rr)/2.0
        // 这样不仅仅消除了溢出的可能性，而且加快了计算速度
        double temp =  rr + (lr - rr)/2.0;
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
    cout << sqrt(21473955) << endl;
    return 0;
}
