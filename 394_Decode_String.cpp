#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stack>

using namespace std;

//recursive
string decodeString(string s, int& i)
{
    string res;

    while(i < s.length() && s[i] != ']')
    {
        if(!isdigit(s[i]))
            res += s[i++];
        else
        {
            int n = 0;
            while(i < s.length() && isdigit(s[i]))
                n = n*10 + s[i++]-'0';

            i++; // '['
            string t = decodeString(s, i);
            i++; // ']'

            while(n-- > 0)
                res += t;
        }
    }

    return res;
}

string decodeString(string s)
{
    int i = 0;
    return decodeString(s, i);
}

// stack
string decodeString2(string s)
{
    stack<string> strs;
    stack<int> nums;
    string res;
    int num = 0;

    for (int i = 0; i < s.size(); i++) {
        if(isdigit(s[i]))
        {
            num = num*10 + (s[i]-'0');
        }
        else if(isalpha(s[i]))
        {
            res.push_back(s[i]);
        }
        else if(s[i] == '[')
        {
            strs.push(res);
            nums.push(num);
            res = "";
            num = 0;
        }
        else if(s[i] == ']')
        {
            string temp = res;
            for (int i = 0; i < nums.top()-1; i++) {
                res += temp;
            }
            res = strs.top() + res;
            strs.pop();
            nums.pop();
        }
    }
    return res;
}

int main(int argc, char const* argv[])
{
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString2("3[a]2[bc]") << endl;
    return 0;
}
