#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool isVaild(string s){
    if(s[0] == ')')
        return false;
    queue<char> temp;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            temp.push(s[i]);
        else if(!temp.empty())
            temp.pop();
        else if(temp.empty())
            return false;
    }

    if(temp.empty())
        return true;
    else 
        return false;
}

int longestVaildParentheses(string s){
    if(s.size() == 1)
        return 0;
    if(isVaild(s))
        return s.size();
    else
        return longestVaildParentheses(s.substr(1, s.size() - 1)) > 
            longestVaildParentheses(s.substr(0, s.size() - 1)) ? 
            longestVaildParentheses(s.substr(1, s.size() - 1)):
            longestVaildParentheses(s.substr(0, s.size() - 1));
}


int main(int argc, const char *argv[])
{
    cout << longestVaildParentheses("(()") << endl;;
    cout << "ok" << endl;
    cout << longestVaildParentheses("()") << endl;;
    cout << "ok" << endl;
    cout << longestVaildParentheses(")()()(") << endl;;
    cout << "ok" << endl;

    return 0;
}
