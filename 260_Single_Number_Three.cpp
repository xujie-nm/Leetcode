#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bit manipulation

vector<int> singleNumber(vector<int>& nums){
    int temp = 0;
    vector<int> res;
    // 异或，取出出现一次的两个数
    for (int i = 0; i < nums.size(); i++) {
        temp ^= nums[i];
    }

    // 取出这两个数的最后一位不相同的
    int lastBit = temp & (~(temp-1));
    int res1 = 0, res2 = 0;
    // 把数组分成两部分
    for (int i = 0; i < nums.size(); i++) {
        if((lastBit & nums[i]) == 0)
            res1 ^= nums[i];
        else
            res2 ^= nums[i];
    }

    res.push_back(res1);
    res.push_back(res2);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{1,2,1,2,3,5};

    vector<int> res;
    res = singleNumber(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
