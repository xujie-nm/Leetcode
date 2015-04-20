#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &height){
    int ret = 0;
    height.push_back(0);//加入一个哨兵
    vector<int> index;

    for (int i = 0; i < height.size(); i++) {
        while(index.size() > 0 && height[index.back()] >= height[i]){//每一次的while都是计算两个下降值之间的矩形
            int h = height[index.back()];
            index.pop_back();
            
            int sidx = index.size() > 0 ? index.back() : -1;
            if(h * (i - sidx - 1) > ret){
                ret = h * (i - sidx - 1);
            }
        }
        index.push_back(i);
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);

    cout << largestRectangleArea(height) << endl;
    return 0;
}
