#include <iostream>
#include <string>
#include <vector>
using namespace std;

void adjust(vector<int> &nums, int begin, int end){
    int left = begin*2;
    int right = begin*2+1;
    
    if(left < end)
        adjust(nums, left, end);
    if(right < end)
        adjust(nums, right, end);
    int biggest = begin;
    if(left <= end && nums[left-1] > nums[biggest-1])
        biggest = left;
    if(right <= end && nums[right-1] > nums[biggest-1])
        biggest = right;

    if(biggest != begin){
        int temp = nums[begin-1];
        nums[begin-1] = nums[biggest-1];
        nums[biggest-1] = temp;
    }
}

int findKthLargest(vector<int>&nums, int k){
    
    int i;
    for (i = 0; i < k-1; i++) {
        adjust(nums, 1, nums.size()-i);
        int temp = nums[0];
        nums[0] = nums[nums.size()-i-1];
        nums[nums.size()-i-1] = temp;
    }
    adjust(nums, 1, nums.size()-i);
    return nums[0];
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);

    cout << findKthLargest(nums, 1) << endl; 
    cout << findKthLargest(nums, 2) << endl; 
    cout << findKthLargest(nums, 3) << endl; 
    cout << findKthLargest(nums, 4) << endl; 
    cout << findKthLargest(nums, 5) << endl; 
    cout << findKthLargest(nums, 6) << endl; 
    return 0;
}
