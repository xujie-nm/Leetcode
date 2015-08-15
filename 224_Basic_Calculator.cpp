#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
using namespace std;

int calculate(string s){
    string last;
    stack<char> temp;
    //由中缀表达式计算后缀表达式
    for (int i = 0; i < s.size(); i++) {
        //如果是数字直接输出到后缀表达式
        if(s[i] >= '0' && s[i] <= '9'){
            last += s[i];
            continue;
        }
        //如果是+或者-
        //  如果栈空直接入
        //  如果非空
        //      如果栈顶是运算符，则先出栈输出到表达式
        //      ，再把当前运算符直接入栈
        //      如果不是，则直接入栈
        if(s[i] == '+' || s[i] == '-'){
            last += ' ';
            if(temp.empty()){
                temp.push(s[i]);
            }else{
                if(temp.top() == '+' || temp.top() == '-'){
                    last +=  temp.top();
                    temp.pop();
                    temp.push(s[i]);
                }else{
                    temp.push(s[i]);
                }
            }
            continue;
        }
        //如果是（直接入栈
        if(s[i] == '('){
            temp.push(s[i]);
            continue;
        }
        //如果是）则运算符一直出栈
        if(s[i] == ')'){
            while(temp.top() != '('){
                last +=' ';
                last += temp.top();
                temp.pop();
            }
            temp.pop();
            continue;
        }
        //如果是空，跳过
        if(s[i] == ' ')
            continue;
    }

    //最后处理栈非空的情况
    //！！这里注意每个数字的末尾加空格，以区分每个数字
    while(!temp.empty()){
        last += ' ';
        last += temp.top();
        temp.pop();
    }
    last += ' ';
    
    //计算后缀表达式
    stack<int> temp1;
    string num;
    for (int i = 0; i < last.size(); i++) {
        if(last[i] >= '0' && last[i] <= '9'){
            num += last[i];
            continue;
        }else if(last[i] == '+' || last[i] == '-'){
            int second = temp1.top();
            temp1.pop();
            int first = temp1.top();
            temp1.pop();
            int res = 0;
            if(last[i] == '+')
                res = first + second;
            if(last[i] == '-')
                res = first - second;
            temp1.push(res);
        }else if(last[i] == ' '){
            if(num.size() != 0)
            {
                temp1.push(atoi(num.c_str()));
      //          cout << atoi(num.c_str()) << endl;
                num = "";
            }
        }
    }
    return temp1.top();
}

int main(int argc, const char *argv[])
{
    string s = "(12+(43+125+2234)-332)+(632+832)";
    //string s = "3123213";
    cout << "s: " << s << endl;
    cout << "calculate: " << calculate(s) << endl;
    return 0;
}
