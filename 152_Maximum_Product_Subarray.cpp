#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// easy understand
int maxProduct(vector<int> &nums){
    int Max = nums[0];
    if(nums.size() == 1)
        return Max;

    int firstNeg = 1;
    int product = 1;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0){
            product *= nums[i];
            if(product < 0){
                if(firstNeg > 0)
                    firstNeg = product;
                else
                    Max = max(Max, product/firstNeg);
            }else{
                Max = max(Max, product);
            }
        }else{
            Max = max(Max, 0);
            firstNeg = 1;
            product = 1;
        }
    }
    return Max;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);

    cout << maxProduct(nums) << endl;
    return 0;
}
