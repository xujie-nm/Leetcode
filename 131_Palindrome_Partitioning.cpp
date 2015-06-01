#include <iostream>
#include <string>
#include <vector>
using namespace std;
//这个方法虽然也可以输出s的所有的子串是回文的
//但是输出的格式有问题
bool isPalindrome(string &s){
    int low = 0;
    int high = s.size()-1;
    while(low <= high){
        if(s[low] == s[high]){
            low++;
            high--;
        }else
            return false;
    }
    return true;
}

void helper(vector<vector<string> > &res, string &s, int i){
    vector<string> temp;
    int start = i, end = i;
    while(start >= 0 && end < s.size()){
        string sub = s.substr(start, end - start + 1);
        if(isPalindrome(sub)){
            temp.push_back(sub);
            start--;
            end++;
        }else
            break;
    }
    start = i; end = i+1;
    while(start >= 0 && end < s.size()){
        string sub = s.substr(start, end - start + 1);
        if(isPalindrome(sub)){
            temp.push_back(sub);
            start--;
            end++;
        }else
            break;
    }
    res.push_back(temp);
}

vector<vector<string> > partition(string s){
    vector<vector<string> > res;
    for (int i = 0; i < s.size(); i++) {
        helper(res, s, i);
    }
    return res;
}

int main(int argc, const char *argv[]){
    vector<vector<string> > res;
    res = partition("aad");
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";       
        }
        cout << endl;
        
    }
    return 0;
}
