#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k){
    int temp = INT_MAX;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if(hash.count(nums[i]) == 0)
            hash[nums[i]] = i;
        else{
            temp = i - hash[nums[i]];
            if(temp <= k)
                return true;
            else
                hash[nums[i]] = i;
        }
    }
    if(temp <= k)
        return true;
    else
        return false;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);

    cout << containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}
