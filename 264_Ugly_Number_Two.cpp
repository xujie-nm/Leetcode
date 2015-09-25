#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

//需要先弄清楚Ugly Number怎么产生的
//题目中说只可以被素数2.3.5整除的就为Ugly Number
//1为特殊的Ugly Number
//所以Ugly可以这样产生
//1*2 2*2 3*2 4*2 5*2 6*2 8*2 9*2 
//1*3 2*3 3*3 4*3 5*3 6*3 8*3 9*3 
//1*5 2*5 3*5 4*5 5*5 6*5 8*5 9*5 

int nthUglyNumber(int n){
    vector<int> res;
    res.push_back(1);
    if(n == 1)
        return res[res.size()-1];
    //记录三个由2，3，5产生的丑陋数的下标
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; i++) {
        //取得三个中最小的一个
        int temp = min(res[i2]*2, min(res[i3]*3, res[i5]*5));
        res.push_back(temp);
        //判断取得是哪个，把这个后移
        if(temp == res[i2]*2)
            i2++;
        if(temp == res[i3]*3)
            i3++;
        if(temp == res[i5]*5)
            i5++;
    }
    return res[res.size()-1];
}

int main(int argc, const char *argv[])
{
    cout << nthUglyNumber(12) << endl;
    cout << nthUglyNumber2(12) << endl;
    return 0;
}
