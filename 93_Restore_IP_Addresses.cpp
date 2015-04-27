#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool check(string &ss){//检查数值大小和是否有前缀零
    bool flag = false;
    if(ss.size() > 1){
        for (int i = 0; i < ss.size(); i++) {
            if(ss[i] != '0')
                flag = true;
            if(!flag && ss[i] == '0')
                return false;
        }
    }
    
    int a = atoi(ss.c_str());
    if(a >= 0 && a <= 255)
        return true;
    return false;
}

void helper(vector<string> &res, string &temp, string &s, int cur, int dot){
    if(dot == 3){
        string sub = s.substr(cur);
        if(!sub.empty() && sub.size() <= 3 && check(sub)){
            temp += sub;
            res.push_back(temp);
            return;
        }else
            return;
    }

    for (int i = 1; i <= 3; i++) {
        if(cur + i > s.size())
            return ;
        string sub = s.substr(cur, i);
        if(!sub.empty() && check(sub)){
            int oldSize = temp.size();
            temp += sub + ".";
            helper(res, temp, s, cur+i, dot+1);
            temp = temp.substr(0, oldSize);
        }else
            return ;
    }
}

vector<string> restoreIPAddresses(string &s){
    vector<string> res;
    string temp;
    helper(res, temp, s, 0, 0);
    return res;
}

int main(int argc, const char *argv[])
{
    string s = "010010";
    vector<string> res;
    res = restoreIPAddresses(s);
    cout << res.size() << endl;

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
