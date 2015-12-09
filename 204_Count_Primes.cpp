#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(vector<int> &primes, int num){
    for (int i = 0; i < primes.size(); i++) {
        if(num%primes[i] == 0)    
            return false;
    }
    primes.push_back(num);
    return true;
}

// 直接找
int countPrimes(int n){
    if(n <= 2)
        return 0;;

    vector<int> primes;
    int res = 0;

    for (int i = 2; i <= n; i++) {
        if(isPrime(primes, i))
            res++;
    }
    return res;
}

// 328ms
int countPrimes2(int n){
    vector<bool> primes(n, true);
    primes[0] = false; primes[1] = false;
    for (int i = 0; i < sqrt(n); i++) {
        if(primes[i]){
            for (int j = i*i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) 
        if(primes[i])
            res++;
    return res;
}

// 128ms
// 尽量跳过重复计算的偶数
int countPrimes(int n){
    if(--n < 2)
        return 0;
    int m = (n+1)/2, count = m;
    int iUpper = (sqrt(n) - 1)/2;
    vector<bool> notPrime(m, false);

    for (int i = 1; i <= iUpper; i++) {
        if(!notPrime[i]){
            for (int k = (i + 1)*2*i; k < m; k += i*2 + 1) {
                if(!notPrime[k]){
                    notPrime[k] = true;
                    count--;
                }
            }
        }
    }
    return count;
}

int main(int argc, const char *argv[])
{
    cout << countPrimes2(499979) << endl;
    return 0;
}
