#include <iostream>
#include <string>
#include <vector>

using namespace std;

int thirdMax(vector<int>&nums)
{
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] <= third || nums[i] == second || nums[i] == first)
            continue;
        if(nums[i] > third)
        {
            third = nums[i];
        }
        if(third > second)
        {
            swap(second, third);
        }
        if(second > first)
        {
            swap(first, second);
        }
    }
    return third == LONG_MIN ? first : third;
}

int main(int argc, char const* argv[])
{
    std::vector<int> nums{2,2,3,1};
    cout << thirdMax(nums) << endl;
    return 0;
}
