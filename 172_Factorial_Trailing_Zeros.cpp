#include <iostream>
#include <string>
#include <vector>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

int trailingZeroes(int n){
    if(n <= 4)
        return 0;

    int count5 = 0;
    int count2 = 0;

    for (int i = 2; i <= n; i++) {
        int temp = i;
        while((temp % 2) == 0 || (temp % 5) == 0){
            if((temp % 2) == 0){
                count2++;
                temp /= 2;
            }
            if((temp % 5) == 0){
                count5++;
                temp /= 5;
            }
        }
    }
    
    return min(count2, count5);
}

int trailingZeroes2(int n){
    //其实这端代码还是基于上面的思想
    //首先想一个问题，怎么会产生０．就是得到10
    //那么得到10只有2*5，所以只需要对２或５的个数计数，取较小者
    //但是产生一个5的因子至少会产生3个２的因子，所以５比２少
    //所以只需要对５的个数计数
    //但是看一下可能有５的因子的数：
    //5    10    15    20    25    30    35    40    45    50
    //1个  2个   3个   4个   5个   6个   7个   8个   9个  10个
    //所以从上面可以看出可以产生５因子的数和他们的规律，
    //那么下面的代码就不难理解了
    int count = 0;
    
    while(n /= 5)
        count += n;

    return count;
}

int main(int argc, const char *argv[])
{
    //time
    struct timeval tv1, tv2, tv3;
    gettimeofday(&tv1, 0);
    //

    cout << trailingZeroes(1000000) << endl;
    //time
    gettimeofday(&tv2, 0);
    //
    cout << trailingZeroes2(1000000) << endl;
    //time
    gettimeofday(&tv3, 0);
    //
    double res1, res2;
    res1 = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + tv2.tv_sec - tv1.tv_sec;
    res2 = (double)(tv3.tv_usec - tv2.tv_usec)/1000000 + tv3.tv_sec - tv2.tv_sec;

    cout << "first solution: " << res1 << endl;
    cout << "second solution: " << res2 << endl;
    return 0;
}
