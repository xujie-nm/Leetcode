#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
    vector<int> res(nums.size(), 1);
    if(nums.size() == 1)
        return res;
    vector<int> forward(nums.size(), 1);
    vector<int> backward(nums.size(), 1);
    int temp = 1;
    for (int i = 1; i < nums.size(); i++) {
        temp *= nums[i-1];
        forward[i] = temp;
    }
    temp = 1;

    for (int i =nums.size()-2; i >= 0; i--) {
        temp *= nums[i+1];
        backward[i] = temp;
    }

    for (int i = 0; i < nums.size(); i++) {
        res[i] = forward[i] * backward[i];
    }
    return res;
}

// 基于上面的方法，省略了一些步骤
vector<int> productExceptSelf2(vector<int> &nums){
    vector<int> res(nums.size(), 1);
    if(nums.size() == 1)
        return res;
    int temp = 1;
    for (int i = 1; i < nums.size(); i++) {
        temp *= nums[i-1];
        res[i] = temp;
    }

    temp = 1;
    for (int i = nums.size()-2; i >= 0; i--) {
        temp *= nums[i+1];
        res[i] *= temp;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    vector<int> res;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    res = productExceptSelf2(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
