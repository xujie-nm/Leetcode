#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums){
    int len = nums.size();
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(mid < len-1 && nums[mid+1] > nums[mid])
            left = mid+1;
        else
            if(mid > 0 && nums[mid-1] > nums[mid])
                right = mid-1;
            else
                return mid;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    cout << findPeakElement(nums) << endl;
    return 0;
}
