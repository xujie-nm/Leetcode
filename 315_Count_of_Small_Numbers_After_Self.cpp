#include <iostream>
#include <string>
#include <vector>
using namespace std;

// left和right存储的是nums中的下标
// sortRes里是最后的排序结果（以原始数组的下标表示）
vector<int> merge(vector<int> left, vector<int> right, vector<int>& nums, vector<int>& res){
    int leftSize = left.size();
    int rightSize = right.size();

    vector<int> sortRes;

    int i = 0, j = 0;
    int count = 0;

    // 记录res，正常序，则用当前count赋值
    // 反序count++
    while(i < leftSize && j < rightSize){
        if(nums[left[i]] <= nums[right[j]]){
            sortRes.push_back(left[i]);
            res[left[i++]] += count;
        }else{
            sortRes.push_back(right[j++]);
            count++;
        }
    }

    while(i < leftSize){
        sortRes.push_back(left[i]);
        res[left[i++]] += count;
    }

    while(j < rightSize){
        sortRes.push_back(right[j++]);
    }

    return sortRes;
}

void mergeSort(vector<int>& sortRes, vector<int>& nums, vector<int>& res){
    int size = sortRes.size();
    if(size < 2)
        return ;
    vector<int> left, right;
    left.assign(sortRes.begin(), sortRes.begin() + size/2);
    right.assign(sortRes.begin() + size/2, sortRes.end());
    mergeSort(left, nums, res);
    mergeSort(right, nums, res);
    sortRes = merge(left, right, nums, res);
    return;
}

vector<int> countSmaller(vector<int>& nums){
    int size = nums.size();
    vector<int> res(size, 0);
    vector<int> sortRes;
    for (int i = 0; i < size; i++) {
        sortRes.push_back(i);
    }

    mergeSort(sortRes, nums, res);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{5,2,6,1};

    vector<int> res;
    res = countSmaller(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
