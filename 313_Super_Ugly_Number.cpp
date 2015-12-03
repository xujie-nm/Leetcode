#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// TLE
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> res;
    res.push_back(1);
    if(n == 1)
        return res[res.size()-1];
    unordered_map<int, int> primesIndex;
    for(int i = 0; i < primes.size(); i++){
        primesIndex[primes[i]] = 0;
    }

    for(int i = 1; i < n; i++){
        int minTemp = INT_MAX;
        for(int j = 0; j < primes.size(); j++){
            minTemp = min(minTemp, (res[primesIndex[primes[j]]] * primes[j]));
        }
        res.push_back(minTemp);
        for(int j = 0; j < primes.size(); j++){
            if(minTemp == res[primesIndex[primes[j]]] * primes[j])
                primesIndex[primes[j]]++;
        }
    }
    return res[res.size() - 1];
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
        cout << nthSuperUglyNumber2(50, primes) << " ";
    //}
    cout << endl;
    return 0;
}
