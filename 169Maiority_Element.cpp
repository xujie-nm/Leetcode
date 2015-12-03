#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
    int majorityElement(vector<int> &num) {
        map<int, int> result;
        int limit = num.size() / 2;
        for(vector<int>::iterator it = num.begin(); it != num.end(); ++it){
                result[*it]++;
            }   
    
        for(map<int, int>::iterator it = result.begin(); it != result.end(); ++it){
                if(it->second > limit)
                    return it->first;
            }   
        return -1; 
    }
};
// 找到出现次数最多的那个数
class Solution2 {
    public:
    int majorityElement(vector<int> &nums) {
        int cur = nums[0];
        for (int i = 1, count = 1; i < nums.size(); i++) {
            if(nums[i] == cur)
                count++;
            else
                count--;
            if(count == -1){
                cur = nums[i];
                count = 1;
            }
        }
        return cur;
    }
};

// 每次加上出现了出现size/2次的那一位
class Solution3 {
    public:
    int majorityElement(vector<int> &nums) {
        vector<int> bit(32, 0);
        for(auto &num: nums){
            for (int i = 0; i < 32; i++) {
                if((num>>i)&1 == 1)
                    bit[i]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (1<<i)*(bit[i]>nums.size()/2 ? 1: 0);
        }
    }
};

int main(int argc, const char *argv[])
{
    vector<int> nums{1,2,2,2,2,2,3,4,5,6,6,7,7,8,2,2,2,2};
    Solution2 s2;
    cout << s2.majorityElement(nums) << endl;;
    return 0;
}
