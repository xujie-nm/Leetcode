#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums){
    if(nums.size() <= 1)
        return -1;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size()-1; i++) {
        if(nums[i] == nums[i+1])
            return nums[i];
    }
}

// Linked List Cycle同思想
int findDuplicate2(vector<int> &nums){
    if(nums.size() <= 1)
        return -1;

    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast){
        //slow一次前进一步
        //fast一次前进两步
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while(fast != slow){
        //然后fast从开头出发
        //找到开始的点
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

//binary search
int findDuplicate3(vector<int> &nums){
    if(nums.size() <= 1)
        return -1;
    int left = 1;
    int right = nums.size()-1;
    int mid;
    int count;
    int i;
    while(left < right){
        mid = left+(right-left)/2;
        for (i = 0, count = 0; i < nums.size(); i++) {
            //统计小于等于mid的
            if(nums[i] <= mid)
                count++;
        }
        //如果大于mid了，说明在左边
        //反之在右边
        if(count > mid) right = mid;
        else
            left = mid+1;
    }
    return left;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{8,7,1,10,17,15,18,11,16,9,19,12,5,14,3,4,2,13,6,18};
    
    cout << findDuplicate3(nums) << endl;
    return 0;
}
