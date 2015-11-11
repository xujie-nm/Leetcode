#include <iostream>
#include <string>
#include <vector>
using namespace std;

// sum(i, j) = sum(0. j) - sum(0, i-1)
class NumArray{
    public:
        NumArray(vector<int> &nums){
            int curSum = 0;
            for (int i = 0; i < nums.size(); i++) {
                curSum += nums[i];
                sum_.push_back(curSum);
            }
        }

        int sumRange(int i, int j){
            if(j >= sum_.size())
                return -1;
            else if(i == 0)
                return sum_[j];
            else
                return sum_[j] - sum_[i-1];
        }

    private:
        vector<int> sum_;
};

int main(int argc, const char *argv[])
{
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            cout << "i: " << i << " j: " << j 
            << " sumRange: " << numArray.sumRange(i, j) << endl;
        }
    }
    return 0;
}
