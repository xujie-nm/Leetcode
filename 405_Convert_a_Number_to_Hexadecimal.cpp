#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toHex(unsigned int num)
{
    if(num == 0)
    {
        return "0";
    }
    string res;
    while(num != 0)
    {
        int curNum = num & 15;
        if(curNum < 10)
        {
            res += char('0' + curNum);
        }
        else
        {
            res += char('a' + curNum - 10);
        }
        num >>= 4;
        //cout << "num: " << num << endl;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char *argv[])
{
    cout << toHex(26) << endl;
    cout << toHex(-1) << endl;
    return 0;
}
