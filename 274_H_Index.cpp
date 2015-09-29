#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//sort first
int hIndex(vector<int> &citations){
    if(citations.size() == 0)
        return 0;
    sort(citations.begin(), citations.end());
    int res = 0;
    for (int i = citations.size()-1; i >= 0; i--) {
        if(citations[i] > res)
            res++;
        else
            break;
    }
    return res;
}

//no sorting
int hIndex2(vector<int> &citations){
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n+1, 0);
    //统计出在每一个引文数出现的次数
    for (int i = 0; i < n; i++) {
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }

    //从大到小，如果遇到大于当前引文数的就马上返回。
    int paper = 0;
    for (int i = n; i >= 0; i--) {
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(1);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);
    cout << hIndex2(citations) << endl;;
    return 0;
}
