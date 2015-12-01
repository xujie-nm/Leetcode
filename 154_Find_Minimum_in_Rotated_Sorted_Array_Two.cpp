#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMin(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    int low = 0;
    int high = nums.size()-1;

    while(low < high){
        int mid = low + (high-low)/2;

        while(nums[mid] == nums[low] && low < mid)
            low++;
        while(nums[mid] == nums[high] && high > mid)
            high--;

        if(nums[mid] > nums[high])
            low = mid+1;
        else
            high = mid;
    }
    return nums[low];
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    cout << findMin(nums) << endl;
    return 0;
}
