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
        if(curProfit <= 0)//如果小于0，表示赔钱，当前不买
            curBuy = i;
        if(curProfit > 0){//调整结果，如果大于零卖出，准备购买下一次
            curBuy = i;
            max += curProfit;
        }
    }
    return max;
}

int main(int argc, const char *argv[])
{
    vector<int> pri;
    pri.push_back(1);
    pri.push_back(2);
    pri.push_back(4);
    cout << maxProfit(pri) << endl;
    return 0;
}
