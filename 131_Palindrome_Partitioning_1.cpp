#include <iostream>
#include <string>
#include <vector>
using namespace std;
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

void helper(vector<vector<string> > &res, vector<string> &temp, string &s, int i){
    if(i >= s.size()){
        res.push_back(temp);
        return;
    }

    for (int j = s.size()-1; j >= i; j--) {
        string sub = s.substr(i, j - i + 1);
        if(isPalindrome(sub)){
            temp.push_back(sub);
            helper(res, temp, s, j+1);
            temp.pop_back();
        }    
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > res;
    vector<string> temp;
    helper(res, temp, s, 0);
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
