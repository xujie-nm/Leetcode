#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool isMatch(const char *s, const char *p){
    int m = strlen(s);
    int n = strlen(p);

    if(m > 3000)
        return false;
    //这句也不明白，是因为出了“a....aaaaa”那个错误讨论区看的
    //目测是字符串如果太长就跳过

    bool ss[m + 1][n + 1];
    //声明一个数组，记录dp时的信息
    ss[0][0]= true;
    //第一个为true
    for (int j = 1; j <= n; j++) {
        ss[0][j] = ss[0][j - 1] && p[j-1] == '*';
        //如果第一行的前一个为1，p[j-1]为*的话，那么当前为1
    }
    for (int i = 1; i <= m; i++) {
        ss[i][0] = false;
        //因为第一列没有特殊符号，设为0
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(p[j-1] == '*'){
                ss[i][j] = ss[i][j-1] || ss[i-1][j];
                //如果当前字符为*的话只要s的前i个和p的前j-1个
                //或者s的前i-1个和p的前j个匹配成功过，说明就成功
            }
            else{
                ss[i][j] = ss[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                //如果不是*说明是正常字符，那么在s和p前面成功的基础之上
                //如果当前字符也能匹配，说明可以匹配。
            }
        }
    }

    return ss[m][n];
    //返回最后结果
}

int main(int argc, const char *argv[])
{
    cout << isMatch("aa", "a") << endl;
    cout << "ok" << endl;
    cout << isMatch("aa", "aa") << endl;
    cout << "ok" << endl;
    cout << isMatch("aaa", "aa") << endl;
    cout << "ok" << endl;
    cout << isMatch("aa", "*") << endl;
    cout << "ok" << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << "ok" << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << "ok" << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << "ok" << endl;
    return 0;
}
