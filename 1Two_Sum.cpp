#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
     
        map<int, int> second;
        vector<int> res;
        for(vector<int>::size_type first = 0; first != numbers.size(); ++first){
           int second_num = target - numbers[first];
                if(second.find(second_num) != second.end())
                {   
                     res.push_back(second[second_num] + 1); 
                     res.push_back(first + 1); 
                     break;
                }   
                second[numbers[first]] = first;
            }   
        return res;
    
    
       }
};

int main(int argc, const char *argv[])
{
    return 0;
}
