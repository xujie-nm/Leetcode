#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void helper(string s, int index, int leftRemoved, int rightRemoved, int pair, string temp, unordered_set<string> &res){
    // 通过变量pair来控制表达式是有效地
    // 当index==s.size或者pair<0退出程序
    if(index == s.size() || pair < 0){
        if(leftRemoved == 0 && rightRemoved == 0 && pair == 0){
            res.insert(temp);
        }
            return;
    }
    if(s[index] != '(' && s[index] != ')'){
        // 如果既不是(，又不是)，则加入表达式中
        helper(s, index+1, leftRemoved, rightRemoved, pair, temp+s[index], res);
    }else if(s[index] == '('){
        // 遇到(时，两步操作，一步删除这个(，另一步是不删除
        if(leftRemoved > 0){
            helper(s, index+1, leftRemoved-1, rightRemoved, pair, temp, res);
        }
        helper(s, index+1, leftRemoved, rightRemoved, pair+1, temp+s[index], res);
    }else{
        // 遇到)时，同上
        if(rightRemoved > 0){
            helper(s, index+1, leftRemoved, rightRemoved-1, pair, temp, res);
        }
        helper(s, index+1, leftRemoved, rightRemoved, pair-1, temp+s[index], res);
    }
}

vector<string> removeInvalidParentheses(string s){
    unordered_set<string> res;
    auto leftRemoved = 0;
    auto rightRemoved = 0;
    // 统计出多余的左括号和右括号
    for(auto item: s){
        if( item == '(')
            leftRemoved++;
        else if(item == ')'){
            if(leftRemoved > 0)
                leftRemoved--;
            else
                rightRemoved++;
        }else
            continue;
    }
    helper(s, 0, leftRemoved, rightRemoved, 0, "", res);
    return vector<string>(res.begin(), res.end());
}

int main(int argc, const char *argv[])
{
    vector<string> strs;
    strs = removeInvalidParentheses("()())()");
    for(auto item: strs){
        cout << item << endl;
    }
    return 0;
}
