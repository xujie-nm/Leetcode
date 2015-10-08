#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


void dfs(vector<string> &res, const string &num, const int target, string cur, int pos, const long curNum, const long preNum, const char preOp){
    if(pos == num.size()){
        if(curNum == target)
            res.push_back(cur);
        return;
    }
    for (int i = pos+1; i <= num.size(); i++) {
        string temp = num.substr(pos, i-pos);
        long int nowNum= stol(temp.c_str());
        if(to_string(nowNum).size() != temp.size())
            continue;// "05"->5
        dfs(res, num, target, cur + "+" + temp, i, curNum + nowNum, nowNum, '+');
        dfs(res, num, target, cur + "-" + temp, i, curNum - nowNum, nowNum, '-');
        int nextCurNum;
        if(preOp == '-'){
            nextCurNum = curNum + preNum - preNum*nowNum;
        }else if(preOp == '+'){
            nextCurNum = curNum - preNum + preNum * nowNum;
        }else{
            //如果前一个是*，那么下一个数就等于上一个数乘以当前的数
            //所以重点是，如果遇到了*号，就把他计算出来作为一个新的数
            nextCurNum = preNum * nowNum;
        }
        dfs(res, num, target, cur + "*" + temp, i, nextCurNum, preNum * nowNum, preOp);
    }
}

vector<string> addOperators(string num, int target){
    vector<string> res;
    if(num.size() == 0)
        return res;
    for (int i = 1; i <= num.size(); i++) {
        string ss = num.substr(0, i);
        long int cur = stol(ss);
        if(to_string(cur).size() != ss.size())
            continue;
        dfs(res, num, target, ss, i, cur, cur, '#');
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> res;
    res = addOperators("1234", 25);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
