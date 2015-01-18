#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits){
    if(digits.size() == 0)
    {
        vector<string> tem;
        tem.push_back("");
        return tem;
    }
    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"};
    
    int nums = 1;
    for (int i = 0; i < digits.size(); i++) {
        nums *= map[digits[i]-'0'].size();
    }
    vector<string> result(nums, "");

    for (int i = 0; i < nums; i++) {
        int temp = i;
        for (int j = digits.size() - 1; j >= 0; j--) {
            result[i].insert(result[i].begin(),map[digits[j]-'0'][temp%(map[digits[j]-'0'].size())]);
            temp /= (map[digits[j]-'0'].size());
        }
    }
    return result;
}

int main(int argc, const char *argv[])
{
    vector<string> res = letterCombinations("245");
    cout << "ok ok ok ok ok ok ok ok " << endl;
    for(vector<string>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
