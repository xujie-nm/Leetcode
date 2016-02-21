#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int>& nums){
    if(nums.size() < 3)
        return false;

    int first = INT_MAX;
    int second = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] <= first)
            first = nums[i];
        else if(nums[i] <= second)
            second = nums[i];
        else
            return true;
    }
    return false;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1 {1,2,3,4,5};
    vector<int> nums2 {5,4,3,2,1};
    
    cout << increasingTriplet(nums1) << endl;
    cout << increasingTriplet(nums2) << endl;
    return 0;
}
