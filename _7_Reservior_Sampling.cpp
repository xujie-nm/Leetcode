#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

// 从数组nums中随机取出k个数--蓄水池算法
// http://www.cnblogs.com/python27/p/Reservoir_Sampling_Algorithm.html
vector<int> ReservoirSampling(vector<int> nums, int k)
{
    vector<int> res(nums.begin(), nums.begin() + k);

    for (int i = k, j = 0; i < nums.size(); i++) {
        j = rand()%(i+1);
        if(j < k)
        {
            res[j] = nums[i];
        }
    }

    return res;
}

int main(int argc, char const* argv[])
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};

    srand((unsigned int)(time(NULL)));

    vector<int> res;
    res = ReservoirSampling(nums, 1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ", ";
    }
    cout << endl;
    return 0;
}
