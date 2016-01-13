#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 112ms
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> res;
    res.push_back(1);
    int numPrimes = primes.size();
    vector<int> indexs(numPrimes, 0);

    while(res.size() < n){
        int nextSuperUglyNumber = res[indexs[0]]*primes[0];

        // 寻找当前最小的一个uglynumber
        for (int i = 0; i < numPrimes; i++) {
           nextSuperUglyNumber = min(nextSuperUglyNumber, res[indexs[i]] * primes[i]);
        }

        // 找到最小的，为下标累加，为下一步做准备
        for (int i = 0; i < numPrimes; i++) {
            if(nextSuperUglyNumber == res[indexs[i]] * primes[i])
                indexs[i]++;
        }

        res.push_back(nextSuperUglyNumber);
    }
    return res[n-1];
}

int nthSuperUglyNumber2(int n, vector<int>& primes) {
    vector<long> res(n, 0);
    res[0] = 1;
    if(n == 1)
        return res[n-1];
    // 存储每个值对对应的index数组中的值
    map<long, int> hash;
    int k = primes.size();
    // 每个primes的下标
    vector<int> index(k, 0);
    for (int i = 0; i < primes.size(); i++) {
        hash[primes[i]] = i;
    }
    int i = 1;
    while(i < n){
        //拿到当前最小
        auto cur = *(hash.begin());
        hash.erase(hash.begin());
        //if(cur.first != res[i-1]) 非必要，下面的while已经处理过重复
            res[i++] = cur.first;
        // 这个数加入结果，其prime所对应的下标加1
        index[cur.second]++;
        // 在插入的时候保持没有重复
        while(hash.count(primes[cur.second] * res[index[cur.second]])){
            // 保证不会重复，和上面的第二个for一个意思
            // 如果这个数出现了，那么这个prime所对应的下标加1
            index[cur.second]++;
        }
        // 产生下一个数
        hash[primes[cur.second] * res[index[cur.second]]] = cur.second;
    }

    return res[n - 1];
}

int main(int argc, const char *argv[])
{
    vector<int> primes{2, 7, 13, 19};
    //for (int i = 1; i < 50; i++) {
        cout << nthSuperUglyNumber(50, primes) << " ";
    //}
    cout << endl;
    return 0;
}
