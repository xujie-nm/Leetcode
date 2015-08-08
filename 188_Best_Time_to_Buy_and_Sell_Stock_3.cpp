#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int maxProfit(int k, vector<int> &prices){
    int len  = prices.size();
    if(len < 2) return 0;
    if(k > len/2){
        int res = 0;
        for (int i = 1; i < prices.size(); i++) 
            res += max(prices[i] - prices[i-1], 0);
        //如果k这么大的话，那么无论如何最大的买卖次数不会超过这个
        return res;
    }
   vector<int> temp(k+1, INT_MIN);
   //记录当前第k-i次能卖出多少
   //记录当前前k-i次能卖出多少
   vector<int> res(k+1, 0);
   int cur;

   for (int i = 0; i < prices.size(); i++) {
       cur = prices[i];
       for (int j = k; j > 0; j--) {
           res[j] = max(res[j], temp[j] + cur);
           temp[j] = max(temp[j], res[j-1] - cur);
       }
   }
   return res[k];
}

int main(int argc, const char *argv[])
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(1);
    cout << maxProfit(2, prices) << endl;
    return 0;
}
