#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> &nums){
    int size = nums.size();
    if(size <= 1)
        return nums;
    sort(nums.begin(), nums.end());
    int pre = nums[0];
    int count = 1;
    vector<int> res;
    for (int i = 1; i < nums.size(); i++) {
        if(pre == nums[i])
            count++;
        else{
            pre = nums[i];
            if(count > size/3)
                res.push_back(nums[i-1]);
            count = 1;
        }
    }
    if(count > size/3)
        res.push_back(nums[size-1]);
    return res;
}

//因为超过1/3才是结果，所以最多只有两个数
vector<int> majorityElement2(vector<int> &nums){
    int size = nums.size();
    if(size <= 1)
        return nums;
    int res1, res2;
    int count1 = 0, count2 = 0;

    //找出出现次数最多的两个数
    //这里的原理是如果已经是这两个数，那么最后的count是不为0的，
    //加起来大于2/3，就算减去1/3，还有1/3
    //反之如果不是这2/3的数，肯定会减到0
    for (int i = 0; i < size; i++) {
        if(nums[i] == res1)
            count1++;
        else if(nums[i] == res2)
            count2++;
        else if(count1==0){
            res1 = nums[i];
            count1 = 1;
        }else if(count2 == 0){
            res2 = nums[i];
            count2 = 1;
        }else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < size; i++) {
        if(nums[i] == res1)
            count1++;
        else if(nums[i] == res2)
            count2++;
    }
    vector<int> res;
    if(count1 > size/3)
        res.push_back(res1);
    if(count2 > size/3)
        res.push_back(res2);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    vector<int> res;
    res = majorityElement2(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
