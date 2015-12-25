#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// 这个函数的功能是nums1从i开始，nums2从j开始
// 取出从这两个位置开始的较大者
bool compareVector(vector<int>& nums1, int i, 
                   vector<int>& nums2, int j){
    while(i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]){
        ++i;
        ++j;
    }
    if(j == nums2.size())
        return true;
    if(i < nums1.size() && nums1[i] > nums2[j])
        return true;
    return false;
}

// 从数组nums中取最大的k个组成最大数组
vector<int> maxVector(vector<int> nums, int k){
    while(nums.size() > k){
        int i = 0;
        int n = nums.size();
        for (; i < n-1; i++) {
            if(nums[i] < nums[i+1]){
                nums.erase(nums.begin() + i);
                break;
            }
        }
        if(i == n-1)
            nums.erase(nums.begin() + i);
    }
    return nums;
}

// 把两个数组在不改变相对位置的情况下合并成一个
vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k){
    vector<int> res(k, 0);
    for (int i = 0, j = 0, r = 0; 
         r < k; r++) {
        res[r] = compareVector(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    }
    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
    int m = nums1.size();
    int n = nums2.size();
    vector<int> res(k, 0);

    for (int i = max(0, k-n); i <= min(k, m); i++) {
        // 从nums1中取i个数，组成最大数组
        auto v1 = maxVector(nums1, i);
        // 从nums2中取k-i个数，组成最大数组
        auto v2 = maxVector(nums2, k-i);
        // 合并两个数组
        auto tmp = merge(v1, v2, k);
        // 比较和当前结果的大小
        if(compareVector(tmp, 0, res, 0))
            res = tmp;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{3, 4, 6, 5};
    vector<int> nums2{9, 1, 2, 5, 8, 3};

    vector<int> res;
    res = maxNumber(nums1, nums2, 5);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
