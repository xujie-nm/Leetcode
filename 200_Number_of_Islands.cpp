#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 从四个方向出发
void fillIslands(vector<vector<char> > &grid, vector<vector<bool> > &visit, int i, int j){
    visit[i][j] = true;
    if(i-1 >= 0 && grid[i-1][j] == '1' && !visit[i-1][j]){
        fillIslands(grid, visit, i-1, j);
    }
    if(i+1 < grid.size() && grid[i+1][j] == '1' && !visit[i+1][j]){
        fillIslands(grid, visit, i+1, j);
    }
    if(j-1 >= 0 && grid[i][j-1] == '1' && !visit[i][j-1]){
        fillIslands(grid, visit, i, j-1);
    }
    if(j+1 < grid[i].size() && grid[i][j+1] == '1' && !visit[i][j+1]){
        fillIslands(grid, visit, i, j+1);
    }
}

int numIslands(vector<vector<char> > &grid){
    if(grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool> > visit(m, vector<bool>(n, false));

    int nums = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == '1' && !visit[i][j])  {
                nums++;
                fillIslands(grid, visit, i, j);
            }
        }
    }
    
    return nums;
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > grid;
    vector<char> l1;
    l1.push_back('1');
    l1.push_back('1');
    l1.push_back('1');
    l1.push_back('0');
    l1.push_back('0');
    vector<char> l2;
    l2.push_back('1');
    l2.push_back('1');
    l2.push_back('0');
    l2.push_back('0');
    l2.push_back('0');
    vector<char> l3;
    l3.push_back('0');
    l3.push_back('0');
    l3.push_back('1');
    l3.push_back('0');
    l3.push_back('0');
    vector<char> l4;
    l4.push_back('0');
    l4.push_back('0');
    l4.push_back('0');
    l4.push_back('1');
    l4.push_back('1');
    grid.push_back(l1);
    grid.push_back(l2);
    grid.push_back(l3);
    grid.push_back(l4);

    cout << numIslands(grid) << endl;
    
    return 0;
}
