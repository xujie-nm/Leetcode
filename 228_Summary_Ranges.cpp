#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> &nums){
    vector<string> res;
    string newRange;
   
    if(nums.size() == 0)
        return res;
    if(nums.size() == 1){
        newRange += to_string(nums[0]);
        res.push_back(newRange);
        return res;
    }

    for (int i = 0; i < nums.size(); i++) {
        if(i == 0){
            newRange += to_string(nums[i]);
        }else{
            if(nums[i] == nums[i-1]+1) 
                continue;
            else{
                if(newRange == to_string(nums[i-1]))
                    res.push_back(newRange);
                else{
                    newRange += "->";
                    newRange += to_string(nums[i-1]);
                    res.push_back(newRange);
                }
                newRange = "";
                newRange += to_string(nums[i]);
            }
        }
    }
    if(nums[nums.size()-1] != nums[nums.size()-2] + 1)
        res.push_back(to_string(nums[nums.size()-1]));
    else{
        newRange += "->";
        newRange += to_string(nums[nums.size()-1]);
        res.push_back(newRange);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(5);

    vector<string> res;
    res = summaryRanges(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

