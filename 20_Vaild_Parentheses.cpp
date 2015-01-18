#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s){
    vector<char> temp;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            temp.push_back(s[i]);
        }
        if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(temp.empty())
                return false;
            else{
                if(temp.back()=='(' && s[i]==')' || 
                   temp.back()=='{' && s[i]=='}' ||
                   temp.back()=='[' && s[i]==']')
                    temp.pop_back();
                else
                    return false;
            }
        }
    }
    if(temp.empty())
        return true;
    else
        return false;
}

int main(int argc, const char *argv[])
{
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([)]") << endl;
    return 0;
}
