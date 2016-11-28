#include <string>
#include <iostream>
#include <vector>

using namespace std;

// MLE
class Solution {
    public:
        Solution(vector<int> nums)
        {
            for (int i = 0; i < nums.size(); i++) {
                indexes[nums[i]].push_back(i);
            }
        }

        int pick(int target)
        {
            int indexed = rand()%indexes[target].size();
            return indexes[target][indexed];
        }

    private:

        unordered_map<int, vector<int> > indexes;
};

class Solution {
    vector<int> nums;
    public:
        Solution(vector<int> vNums)
        {
            nums = vNums;
        }

        int pick(int target)
        {
            int count = 0;
            int res = -1;

            for (int i = 0; i < nums.size(); i++) {
                if(nums[i] != target)
                    continue;
                if(count == 0)
                {
                    res = i;
                    count++;
                }
                else
                {
                    count++;
                    if(rand()%count == 0)
                    {
                        res = i;
                    }
                }
            }
            return res;
        }

};

int main(int argc, char const* argv[])
{

    return 0;
}
