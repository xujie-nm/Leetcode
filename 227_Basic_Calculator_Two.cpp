#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
using namespace std;

// not very elegent
int calculate(string s){
     string last;
     stack<char> temp;

     for (int i = 0; i < s.size(); i++) {
         if(s[i] >= '0' && s[i] <= '9'){
            last += s[i];
            continue;
         }
         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            last += ' ';
            if(temp.empty()){
                temp.push(s[i]);
            }else{
                while(!temp.empty())
                {
                    if(temp.top() == '*' || temp.top() == '/'){
                        last += temp.top();
                        temp.pop();
                    }else if(temp.top() == '+' || temp.top() == '-'){
                        if(s[i] == '+' || s[i] == '-'){
                            last += temp.top();
                            temp.pop();
                        }else{
                            break;
                        }
                    
                    }
                    else{
                        break;
                    }
                }
                temp.push(s[i]);
                //
            }
            continue;
         }
         if(s[i] == '('){
            temp.push(s[i]);
            continue;
         }
         if(s[i] == ')'){
            while(temp.top() != '('){
                last += ' ';
                last += temp.top();
                temp.pop();
            }
            temp.pop();
            continue;
         }
         if(s[i] == ' ')
             continue;
     }
     
     while(!temp.empty()){
        last += ' ';
        last += temp.top();
        temp.pop();
     }
     last += ' ';

     stack<int> temp1;
     string num;
     cout << "last: " << last << endl;
     for (int i = 0; i < last.size(); i++) {
         if(last[i] >= '0' && last[i] <= '9'){
            num += last[i];
            continue;
         }else if(last[i] == '+' || last[i] == '-' || last[i] == '*' || last[i] == '/'){
            int second = temp1.top();
            temp1.pop();
            int first = temp1.top();
            temp1.pop();
            int res = 0;
            if(last[i] == '+')
                res = first + second;
            else if(last[i] == '-')
                res = first - second;
            else if(last[i] == '*')
                res = first * second;
            else if(last[i] == '/')
                res = first / second;
            temp1.push(res);
         }else if(last[i] == ' '){
            if(num.size() != 0){
                temp1.push(atoi(num.c_str()));
                num = "";
            }
         }
     }
    return temp1.top();
}

int calculate2(string s){
    int res = 0, curRes = 0;
    char op = '+';
    for (int pos = s.find_first_not_of(' '); pos < s.size();
         pos = s.find_first_not_of(' ', pos)) {
        if(isdigit(s[pos])){
            int tmp = s[pos] - '0';
            while(++pos < s.size() && isdigit(s[pos]))
                tmp = tmp*10 + s[pos] - '0';
            switch(op){
                case '+':
                    curRes += tmp;
                    break;
                case '-':
                    curRes -= tmp;
                    break;
                case '*':
                    curRes *= tmp;
                    break;
                case '/':
                    curRes /= tmp;
                    break;
            }
        }else{
            if(s[pos] == '+' || s[pos] == '-'){
                res += curRes;
                curRes = 0;
            }
            op = s[pos++];
        }
    }
    return res + curRes;
}

int main(int argc, const char *argv[])
{
    string s1 = "3+2*2";   
    string s2 = "2-0+30-56";
    string s3 = "1*2-3/4+5*6-7*8+9/10";
    cout << calculate(s1) << endl;
    cout << calculate(s2) << endl;
    cout << calculate(s3) << endl;
    return 0;
}
