#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// 求出非排序数组，在有序时相邻元素最大的差值
int maximumGap(vector<int> &nums){
    int n = nums.size();
    if(nums.size() <= 1)
        return 0;
    int maxE = *(max_element(nums.begin(), nums.end()));
    int minE = *(min_element(nums.begin(), nums.end()));

    int len = maxE - minE;
    if(len <= 1)
        return len;
    //建立两个桶，一个最大桶，一个最小桶
    vector<int> buckMax(n, INT_MIN);
    vector<int> buckMin(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        //产生桶的下标，原理是当前间隙的百分比乘以桶的长度
        int index = (double)(nums[i] - minE) / len * (n-1);
        buckMax[index] = max(buckMax[index], nums[i]);
        buckMin[index] = min(buckMin[index], nums[i]);
    }
    
    int gap = 0, pre = buckMax[0];
    for (int i = 0; i < n; i++) {
        if(buckMax[i] == INT_MIN)
            continue;
        //这需要解释一下，为什么是上一个的min减去这个的max就可以了
        //而不是每一步都需要求出每个桶的最大gap在和这个比较
        //因为，如果nums里的数据不是连续的，
        //那么肯定会有一个桶为空，所以gap肯定会大于桶容量。
        //（因为这样分配的桶的个数其实是len/(n-1),所以不连续
        //就可以识别出来）。
        //如果是连续的，这样也可以求出连续之间的gap。
        gap = max(gap, buckMin[i] - pre);
        pre = buckMax[i];
    }
   
    return gap;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(11);
    nums.push_back(1);
    cout << maximumGap(nums) << endl;
    return 0;
}
