#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int abs(int num){
    if(num >= 0)
        return num;
    else
        return -num;
}

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t){
    if(nums.size() <= 2)
        return false;
    if(k == 0)
        return false;
    
    multiset<int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if(hash.size() > k)
            hash.erase(nums[i-k-1]);
        multiset<int>::iterator lower = hash.lower_bound(nums[i]-t);
        if(lower != hash.end() && abs(nums[i] - *lower) <= t)
            return true;
        hash.insert(nums[i]);
    }
    return false;
}

bool cmp(int *a, int *b){
    return *a < *b;
}

bool containsNearbyAlmostDuplicate2(vector<int> &nums, int k, int t){
    if(nums.size() < 2 || k == 0)
        return false;
    vector<int*> numptrs(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        numptrs[i] = &nums[i];
    }

    sort(numptrs.begin(), numptrs.end(), cmp);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if(*numptrs[j] > *numptrs[i] + t)
                break;
            if(abs(numptrs[j] - numptrs[i]) <= k)
                return true;
        }
    }
    return false;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << containsNearbyAlmostDuplicate2(nums, 1, 1) << endl;
    cout << containsNearbyAlmostDuplicate(nums, 1, 1) << endl;
    return 0;
}
