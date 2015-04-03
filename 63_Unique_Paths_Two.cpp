#include <iostream>
#include <string>
#include <vector>
using namespace std;

int uniquePathWithObstacles(vector<vector<int> > &obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int> > A(m + 1, vector<int>(n+1, 0));
    //初始化A[0][1]或A[1][0]爲1
    //因爲要判斷A[0][0]的值
    A[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(!obstacleGrid[i-1][j-1])
                //如果當前不是障礙的話則可以通過
                //如果是障礙的話爲0
                A[i][j] = A[i-1][j] + A[i][j-1];
        }
    }

    return A[m][n];
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > obs;
    vector<int> line1(3, 0);
    vector<int> line2;
    line2.push_back(0);
    line2.push_back(1);
    line2.push_back(0);
    vector<int> line3(3, 0);
    obs.push_back(line1);
    obs.push_back(line2);
    obs.push_back(line3);

    cout << uniquePathWithObstacles(obs) << endl;
    return 0;
}
