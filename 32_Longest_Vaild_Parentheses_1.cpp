#include <iostream>
#include <string>
#include <queue>
#include <map>
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

map<string, int> pa_len;

int longestVaildParentheses(string s){
    if(s.size() == 1){
        pa_len.insert(make_pair(s, 0));
        return pa_len[s];
    }
    if(isVaild(s)){
        pa_len.insert(make_pair(s, s.size()));
        return pa_len[s];
    }
    else
        if(pa_len.count(s.substr(1, s.size() - 1)) > 0 && pa_len.count(s.substr(0, s.size() - 1)) > 0)
            return pa_len[s.substr(1, s.size() - 1)] > pa_len[s.substr(0, s.size() - 1)] ?
                pa_len[s.substr(1, s.size() - 1)] : pa_len[s.substr(0, s.size() - 1)];
        else if(pa_len.count(s.substr(1, s.size() - 1)) > 0)
            return pa_len[s.substr(1, s.size() - 1)] > longestVaildParentheses(s.substr(0, s.size() - 1))?
                pa_len[s.substr(1, s.size() - 1)] : longestVaildParentheses(s.substr(0, s.size() - 1));
        else if(pa_len.count(s.substr(0, s.size() - 1)) > 0)
            return longestVaildParentheses(s.substr(1, s.size() - 1)) > pa_len[s.substr(0, s.size() - 1)] ?
                longestVaildParentheses(s.substr(1, s.size() - 1)) : pa_len[s.substr(0, s.size() - 1)];
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
