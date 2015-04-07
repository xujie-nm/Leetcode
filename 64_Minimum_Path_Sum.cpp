#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid){
    int m = grid.size();
    if(m == 0)
        return 0;
    int n = grid[0].size();
    vector<vector<int> > A(m, vector<int>(n, 0));
    A[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) 
        A[i][0] = A[i-1][0] + grid[i][0];
    for (int i = 1; i < n; i++)
        A[0][i] = A[0][i-1] + grid[0][i];

    for (int i = 1; i < m; i++) 
        for (int j = 1; j < n; j++) 
            A[i][j] = min(A[i-1][j],A[i][j-1]) + grid[i][j];
    
    return A[m-1][n-1];
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > grid;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(5);
    vector<int> line2;
    line2.push_back(1);
    line2.push_back(1);
    grid.push_back(line1);
    grid.push_back(line1);

    cout << minPathSum(grid) << endl;
    return 0;
}
