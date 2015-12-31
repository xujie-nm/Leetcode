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

// faster
void dfs(int index, char preSign, long preNum, long val, const long target, string &tmp, const string &num, vector<string> &res){
    const int numSize = num.size();
    if(index >= numSize){
        if(target == val+preNum)
            res.push_back(tmp);
        return;
    }
    // 如果等于0，curNum就从此处断开
    long end = num[index]=='0' ? index : (numSize-1);
    long curNum=0, newPreNum = 0, newVal = 0, oldSize = tmp.size();
    for (int i = index; i <= end; i++) {
        curNum = 10*curNum+num[i]-'0';
        tmp += num[i];
        // 这个分支分别计算三种运算符
        if(preSign == '*'){
            newPreNum = preNum*curNum;
            newVal = val;
        }else{
            newPreNum = preSign == '+' ? curNum : -curNum;
            newVal = val+preNum;
        }
        // 进入下一步
        if(i == numSize-1){
            dfs(i+1, ' ', newPreNum, newVal, target, tmp, num, res);
        }else{
            tmp += '*';
            dfs(i+1, '*', newPreNum, newVal, target, tmp, num, res);

            tmp.back() = '+';
            dfs(i+1, '+', newPreNum, newVal, target, tmp, num, res);
            
            tmp.back() = '-';
            dfs(i+1, '-', newPreNum, newVal, target, tmp, num, res);

            tmp.pop_back();
        }
    }
    tmp.resize(oldSize);
}

vector<string> addOperators2(string num, int target){
    vector<string> ret;
    string tmp;
    dfs(0, '+', 0, 0, target, tmp, num, ret);
    return ret;
}

int main(int argc, const char *argv[])
{
    vector<string> res;
    res = addOperators2("1234", 25);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
