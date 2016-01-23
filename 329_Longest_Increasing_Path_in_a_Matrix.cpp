#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// TLE
int helper(vector<vector<int> >& matrix, vector<vector<bool> >& visited, int curValue, int i, int j){
    visited[i][j] = true;
    int res = 1;

    if(i-1 >= 0 && !visited[i-1][j] && matrix[i-1][j] > curValue) {// 上
        if(res <= 1)
            res += helper(matrix, visited, matrix[i-1][j], i-1, j);
        else
            res = max(res, helper(matrix, visited, matrix[i-1][j], i-1, j)+1);
    }
   
    if(i+1 < matrix.size() && !visited[i+1][j] && matrix[i+1][j] > curValue){ // 下
        if(res <= 1)
            res += helper(matrix, visited, matrix[i+1][j], i+1, j);
        else
            res = max(res, helper(matrix, visited, matrix[i+1][j], i+1, j)+1);
    }
    
    if(j-1 >= 0 && !visited[i][j-1] && matrix[i][j-1] > curValue){ // 左
        if(res <= 1)
            res += helper(matrix, visited, matrix[i][j-1], i, j-1);
        else
            res = max(res, helper(matrix, visited, matrix[i][j-1], i, j-1)+1);
    
    }
    
    if(j+1 < matrix[i].size() && !visited[i][j+1] && matrix[i][j+1] > curValue){ // 右
        if(res <= 1)
            res += helper(matrix, visited, matrix[i][j+1], i, j+1);
        else
            res = max(res, helper(matrix, visited, matrix[i][j+1], i, j+1)+1);
    
    }

    visited[i][j] = false;
    return res;
}

int longestIncreasingPath(vector<vector<int> > &matrix){
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int res = 0;

    multimap<int, pair<int, int> > curPoints;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            curPoints.insert(make_pair(matrix[i][j], make_pair(i, j)));
        }
    }

    while(res < curPoints.size()){
        vector<vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        auto it = curPoints.begin();
        res = max(res,  helper(matrix, visited, it->first, it->second.first, it->second.second));
        curPoints.erase(it);
    }

    return res;
}

// AC more clear

int helper(vector<vector<int> >& matrix, vector<vector<int> >& partRes, int i, int j, int m, int n){
    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    if(i >= 1 && matrix[i-1][j] > matrix[i][j])
        up = partRes[i-1][j] > 1 ? partRes[i-1][j] : helper(matrix, partRes, i-1, j, m, n);
    
    if(i < m-1 && matrix[i+1][j] > matrix[i][j])
        down = partRes[i+1][j] > 1 ? partRes[i+1][j] : helper(matrix, partRes, i+1, j, m, n);
    
    if(j >= 1 && matrix[i][j-1] > matrix[i][j])
        left = partRes[i][j-1] > 1 ? partRes[i][j-1] : helper(matrix, partRes, i, j-1, m, n);
    
    if(j < n-1 && matrix[i][j+1] > matrix[i][j])
        right = partRes[i][j+1] > 1 ? partRes[i][j+1] : helper(matrix, partRes, i, j+1, m, n);
    
    partRes[i][j] = 1 + max(max(up, down), max(left, right));

    return partRes[i][j];
}

int longestIncreasingPath2(vector<vector<int> >& matrix){
    int m = matrix.size();
    if(m == 0)
        return 0;
    int n = matrix[0].size();
    vector<vector<int> > partRes(m, vector<int>(n, 1));
    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, helper(matrix, partRes, i, j, m, n));
        }
    }

    return res;
}



int main(int argc, const char *argv[])
{
    vector<int> line1{7,7,5};
    vector<int> line2{2,4,6};
    vector<int> line3{8,2,0};
    vector<vector<int> > nums{line1, line2, line3};

    cout << longestIncreasingPath(nums) << endl;
    cout << longestIncreasingPath2(nums) << endl;
    return 0;
}
