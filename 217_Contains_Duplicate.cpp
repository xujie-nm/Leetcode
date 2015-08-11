#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums){
    bool flag = false;
    unordered_set<int> hash;
    
    for (int i = 0; i < nums.size(); i++) {
        if(hash.count(nums[i]) == 0)
            hash.insert(nums[i]);
        else{
            flag = true;
            break;
        }
    }
    return flag;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << containsDuplicate(nums) << endl;
    nums[4] = 1;
    cout << containsDuplicate(nums) << endl;
    return 0;
}
