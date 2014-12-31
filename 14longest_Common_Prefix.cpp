#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.size() == 0)
                return "";
            else if(strs.size() == 1)
                return strs[0];
            string res;
            string temp;
            bool equal = true;
            int min_size = strs[0].size();
            for(vector<string>::iterator it = strs.begin(); it != strs.end(); ++it){
                if((*it).size() <= min_size ){
                    min_size = (*it).size();
                        temp = *it;
                }
            }
            for (int i = 0; i < min_size; i++) {
                equal = true;
                for (int j = 0; j < strs.size(); j++) {
                    if(strs[j][i] != temp[i]){
                        equal = false;
                        break;
                    }
                }
                if(equal)
                    res += temp[i];
                else
                    break;
            }
            return res;
        }
};

int main(int argc, const char *argv[])
{
    return 0;
}
