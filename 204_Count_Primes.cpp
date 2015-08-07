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
//直接找

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

int main(int argc, const char *argv[])
{
    cout << countPrimes2(499979) << endl;
    return 0;
}
