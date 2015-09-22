#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <deque>
using namespace std;

//using map and queue
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    vector<int> res;
    if(nums.size() == 0)
        return res;

    queue<int> tmpQueue;
    map<int, int> tmpMap;
    int curMax;
    for (int i = 0; i < k; i++) {
        tmpQueue.push(nums[i]);
        tmpMap[nums[i]]++;
    }
    for (int i = k; i < nums.size(); i++) {
        //取得当前最大
        curMax = (tmpMap.rbegin())->first;
        res.push_back(curMax);
        //删除下一个
        int top = tmpQueue.front();
        tmpQueue.pop();
        if(tmpMap[top] == 1)
            tmpMap.erase(top);
        else
            tmpMap[top]--;
        //插入新的元素
        tmpQueue.push(nums[i]);
        tmpMap[nums[i]]++;
    }
    curMax = (tmpMap.rbegin())->first;
    res.push_back(curMax);
    return res; 
}

//using deque
vector<int> maxSlidingWindow2(vector<int>& nums, int k){
    deque<int> que;
    vector<int> maxs;
    if(nums.empty() || k <= 0)
        return maxs;

    for (int i = 0; i < nums.size(); i++) {
        while(!que.empty() && nums[que.back()] <= nums[i]){
            //如果队尾的元素小于当前，则弹出
            que.pop_back();
        }
        //依次入队
        que.push_back(i);
        //如果当前队列中元素过多（大于等于k个）
        //弹出
        if(que.front() <= i-k){
            que.pop_front();
        }

        //已经检阅过k和元素，肯定已经产生最大的
        if(i >= k-1){
            maxs.push_back(nums[que.front()]);
        }
    }
    return maxs;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(-7);
    nums.push_back(-8);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(0);

    vector<int> res;
    res = maxSlidingWindow2(nums, 4);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
