#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addStrings(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    bool carry = false;
    int i = 0, j = 0;
    string res;
    while(i < num1.size() && j < num2.size())
    {
        int temp = (num1[i]-'0') + (num2[j]-'0') + carry;
        carry = temp/10;
        res += (char)(temp%10 + '0');
        i++;
        j++;
    }

    while(i < num1.size())
    {
        int temp = (num1[i]-'0') + carry;
        carry = temp/10;
        res += (char)(temp%10 + '0');
        i++;
    }

    while(j < num2.size())
    {
        int temp = (num2[j]-'0') + carry;
        carry = temp/10;
        res += (char)(temp%10 + '0');
        j++;
    }

    if(carry)
    {
        res += char(carry + '0');
    }

    reverse(res.begin(), res.end());
    
    return res;
}

int main(int argc, const char *argv[])
{
    cout << addStrings("1", "99999")  << endl;
    return 0;
}
