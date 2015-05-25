#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices){
    if(prices.size() <= 1)
        return 0;
    int n = prices.size();

    vector<int> forward(n);//这个数组里面存的是０～ｉ所能购买到的最大利润
    forward[0] = 0;
    int lowBuy = prices[0];
    for (int i = 1; i < n; i++) {
        forward[i] = max(forward[i-1], prices[i] - lowBuy);
        lowBuy = min(lowBuy, prices[i]);
    }

    vector<int> backward(n);//这个数组里存的是ｉ～ｎ所能购买到的最大利润
    backward[n-1] = 0;
    int highSell = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        backward[i] = max(backward[i+1], highSell - prices[i]);
        highSell = max(highSell, prices[i]);
    }
    
    int Max = 0;
    for (int i = 0; i < n; i++) {
        Max = max(Max, forward[i] + backward[i]);
    }
    return Max;
}


int main(int argc, const char *argv[])
{
    vector<int> pri;
    pri.push_back(2);
    pri.push_back(1);
    pri.push_back(2);
    pri.push_back(0);
    pri.push_back(1);

    cout << maxProfit(pri) << endl;
    return 0;
}
