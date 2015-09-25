#include <iostream>
#include <string>
#include <vector>
using namespace std;

//O(n)space
int missingNumber(vector<int> &nums){
    vector<bool> bit(nums.size()+1, false);
    for (int i = 0; i < nums.size(); i++) {
        bit[nums[i]] = true;
    }

    for (int i = 0; i < bit.size(); i++) {
        if(bit[i] == false)
            return i;
    }
}

//sum
int missingNumber2(vector<int> &nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return nums.size() * (nums.size()+1) / 2 - sum;
}

//move to right position
int missingNumber3(vector<int> &nums){
    int i = 0;
    while(i < nums.size()){
        int v = nums[i];
        if(v < nums.size() && v != nums[v]){
            int temp = nums[v];
            nums[v] = nums[i];
            nums[i] = temp;
        }else
            i++;
    }

    int k = 0;
    while(k < nums.size()){
        if(k != nums[k])
            break;
        k++;
    }
    return k;
}

//Bit Manipulation
//存在的数会出现两次，所^操作会消去
//不存在的数只会出现一次，会被留下来
int missingNumber4(vector<int> &nums){
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        result ^= i;
        result ^= nums[i];
    }
    return result;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    cout << missingNumber4(nums) << endl;
    return 0;
}
