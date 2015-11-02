#include <iostream>
#include <string>
#include <vector>
using namespace std;

// O(m*n)space
int minDis(int a, int b, int c){
    if(a < b){
        if(a < c)
            return a;
        else
            return c;
    }else{
        if(b < c)
            return b;
        else
            return c;
    }
}

int minDistance(string word1, string word2){
    int n = word1.size();
    int m = word2.size();
    vector<vector<int> > temp(n+1, vector<int>(m+1, 0));
    
    for (int i = 0; i <= n; i++) {
        temp[i][0] = i;
    }

    for (int i = 0; i <= m; i++) {
        temp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int dis;
            if(word1[i-1] == word2[j-1])
                dis = 0;
            else
                dis = 1;
            temp[i][j] = minDis(temp[i-1][j] + 1, temp[i][j-1] + 1, temp[i-1][j-1] + dis);
            //temp[i-1][j]+1体现的是删除一个字符需要的步长
            //temp[i][j-1]+1体现的是插入一个字符所需要的步长
            //temp[i-1][j-1]+1体现的是替换一个字符需要的步长
        }
    }

    return temp[n][m];
}

// O(n)space
int minDistance2(string word1, string word2){
    int n1 = word1.size(), n2 = word2.size();
    vector<int> dp(n2+1, 0);
    for (int j = 1; j <= n2; j++) 
        dp[j] = j;
    int last_tmp, cur_tmp;
    for (int i = 1; i <= n1; i++) {
        last_tmp = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n2; j++) {
            cur_tmp = dp[j];
            dp[j] = min(min(dp[j]+1, dp[j-1]+1),
                        last_tmp + (int)(word1[i-1] != word2[j-1]));
            last_tmp = cur_tmp;
        }
    }
    return dp[n2];
}

int main(int argc, const char *argv[])
{
    cout << minDistance("coffee", "cafe") << endl;
    cout << minDistance2("coffee", "cafe") << endl;
    return 0;
}
