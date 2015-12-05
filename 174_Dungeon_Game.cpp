#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon){
    int m = dungeon.size();
    int n = m == 0 ? 0 : dungeon[0].size();
    if(m == 0 || n == 0)
        return 0;
    vector<vector<int> > dp(m, vector<int>(n));
    //重点是边界条件

    for (int i = m-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if(i == m-1 && j == n-1)
                //如果是最后一个的话
                dp[i][j] = max(1, 1-dungeon[i][j]);
            else if(i == m-1)
                //如果是最后一行的话
                dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
            else if(j == n-1)
                //如果是最后一列的话
                dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
            else
                //用两个方向中的最小血量对当前血量做操作
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j])-dungeon[i][j]);
        }
        
    }
    return dp[0][0];
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > dungeon;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(-3);
    line1.push_back(3);
    vector<int> line2;
    line2.push_back(0);
    line2.push_back(-2);
    line2.push_back(0);
    vector<int> line3;
    line3.push_back(-3);
    line3.push_back(-3);
    line3.push_back(-3);
    dungeon.push_back(line1);
    dungeon.push_back(line2);
    dungeon.push_back(line3);

    cout << "min: " << calculateMinimumHP(dungeon)  << endl;
    return 0;
}
