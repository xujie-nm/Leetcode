#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &nums){
    set<int> temp;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        temp.insert(*it);

    int max = 1;
    int length = 1;
    int cur = *(temp.begin());
    set<int>::iterator it = temp.begin();
    ++it;
    for(; it != temp.end(); ++it){
        if(*it == cur + 1){
            ++cur;
            ++length;
        }
        else{
            if(length > max)
                max = length;
            length = 1;
            cur = *it;
        }
    }
    if(length > max)
        max = length;
    return max;
}

int longestConsecutive2(vector<int> &num){
    unordered_set<int> temp(num.begin(), num.end());
    int res = 1;

    for (int i = 0; i < num.size(); i++) {
        if(temp.find(num[i]) == temp.end())
            continue;
        temp.erase(num[i]);
        int prev = num[i]-1, next = num[i]+1;
        while(temp.find(prev) != temp.end())
            temp.erase(prev--);
        while(temp.find(next) != temp.end())
            temp.erase(next++);
        res = max(res, next-prev-1);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(-1);
    cout << longestConsecutive(nums) << endl;
    cout << longestConsecutive2(nums) << endl;
    return 0;
}
