#include <iostream>
#include <string>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++) {
        // 之前也是这种想法，但是是if不是while
        // 使用if可能出现当前交换到这个位置的属于前面
        // 如果只交换一次，那么当前位置的数就不能到正确的位置上
        // 所以，尽可能交换多次
        while(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    int i;
    for (i = 0; i < nums.size(); i++) {
        if(nums[i] != i+1)
            break;
    }
    return i+1;
}

int main(int argc, const char *argv[])
{

    vector<int> nums{-1, 4, 2, 1, 9, 10};
    cout << firstMissingPositive(nums) << endl;;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
