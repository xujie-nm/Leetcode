#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
using namespace std;

int evalRPN(vector<string> &tokens){
    stack<int> numbers;
    //this program is not very rigorous
    //when pop, has to judge stack is not empty,
    //and at last if stack size if bigger than 1,
    //this result is not correct
    for (int i = 0; i < tokens.size(); i++) {
        if(tokens[i] == "+"){
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a+b);
        }else if(tokens[i] == "-"){
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a-b);
        }else if(tokens[i] == "*"){
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a*b);
        }else if(tokens[i] == "/"){
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a/b);
        }else{
            numbers.push(atoi(tokens[i].c_str()));
        }
    }
    return numbers.top();
}

int main(int argc, const char *argv[])
{
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    cout << evalRPN(tokens) << endl;
    return 0;
}
