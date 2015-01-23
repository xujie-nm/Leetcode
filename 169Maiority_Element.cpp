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


int main(int argc, const char *argv[])
{
    
    return 0;
}
