#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices){
    if(prices.size() < 2)
        return 0;
   
    int curBuy = 0;//记录当前购买彩票的位置
    int max = 0;//结果
    for (int i = 1; i < prices.size(); i++) {
        int curProfit = prices[i] - prices[curBuy];//产生当前卖出的利润
        if(curProfit <= 0)//如果小于0，调整购买彩票的位置
            curBuy = i;
        if(curProfit > max)//调整结果
            max = curProfit;
    }
    return max;
}
