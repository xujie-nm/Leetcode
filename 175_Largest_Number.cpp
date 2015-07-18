#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toString(int x){
    string str;
    while(x != 0){
        str += (char)(x%10+'0');
        x /= 10;
    }
    reverse(str.begin(), str.end());
    if(str.size() == 0)
        return "0";
    return str;
}

bool comp(const string &aStr, const string &bStr){
   if(aStr.size() == bStr.size()) 
       return aStr > bStr;

   int i = 0;
   while(i < aStr.size() && i < bStr.size()){
        if(aStr[i] != bStr[i])
            return aStr[i] > bStr[i];
        i++;
   }

   if(i == aStr.size()){
        return comp(aStr, bStr.substr(i));
   }else{
        return comp(aStr.substr(i), bStr);
   }
}

bool comp1(const string &aStr, const string &bStr){
    string s1 = aStr + bStr;
    string s2 = bStr + aStr;
    return s1 > s2;
}

string largestNumber(vector<int> &nums){
    string res = "";
    vector<string> numStr;
    for (int i = 0; i < nums.size(); i++) {
        numStr.push_back(toString(nums[i]));
    }
    
    sort(numStr.begin(), numStr.end(), comp1);

    for (int i = 0; i < nums.size(); i++) {
        res += numStr[i];
    }

    string res1(res.size(), '0');
    if(res.size() == 0 || res == res1)
        return "0";
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(128);
    nums.push_back(12);

    cout << largestNumber(nums) << endl;
    return 0;
}
