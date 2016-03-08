#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
class Solution{
    public:
        bool isMatch(const char *s, const char *p) {
        int i, j;
        int m = strlen(s);
        int n = strlen(p);
        bool b[m + 1][n + 1];
        //申请足够大的二位数组
        b[0][0] = true;
        //都为空是为真
        for (i = 0; i < m; i++) {
            b[i + 1][0] = false;
            //第一列都是false
        }
        for (j = 0; j < n; j++) {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
            //第一行隔一个的为*，且这个为*，且不是第一个为真
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (p[j] != '*') {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                    //如果这个字符不是*的话
                    //则他两相等或为.，且他们前面的相等为真
                    //若不是为假
                } 
                else {
                    b[i + 1][j + 1] = j > 0 && b[i + 1][j - 1] || b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
                    //若这个字符是*的话
                    //那么就有两种情况
                    //第一种，当前*号（不包括）和s前面的已经匹配
                    //第二种，当前*号（包括*）和s后面的已经匹配
                }
            }
        }

    return b[m][n];
    }
};

int main(int argc, const char *argv[])
{
    return 0;
}
