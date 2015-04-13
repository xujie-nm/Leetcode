#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int main(int argc, const char *argv[])
{
    cout << minDistance("coffee", "cafe") << endl;
    return 0;
}
