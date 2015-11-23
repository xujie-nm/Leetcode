#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 从边缘出发，宽度优先搜索
// 如果从边缘为O的出发，
// 最后所有搜索后到不了的那些为O的区域为surrounded
void helper(vector<vector<char> > &board, vector<vector<int> > &temp, int i, int j, int m, int n){
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int temp_i = p.first, temp_j = p.second;
        if(temp_i >= 0 && temp_i < m && temp_j >= 0 && temp_j < n
           && board[temp_i][temp_j] == 'O' && temp[temp_i][temp_j] == 1){
            temp[temp_i][temp_j] = 0;
            if(temp_i-1 >= 0)
                q.push(make_pair(temp_i-1, temp_j));
            if(temp_i+1 < m)
                q.push(make_pair(temp_i+1, temp_j));
            if(temp_j-1 >= 0)
                q.push(make_pair(temp_i, temp_j-1));
            if(temp_j+1 < n)
                q.push(make_pair(temp_i, temp_j+1));
        }
    }
}

void solve(vector<vector<char> > &board){
    int m = board.size();
    if(m == 0)
        return;
    int n = board[0].size();
    vector<vector<int> > temp(m, vector<int>(n, 1));
   
    for (int i = 0; i < m; i++) {
        if(board[i][0] == 'O')
            helper(board, temp, i, 0, m, n);
        if(board[i][n-1] == 'O')
            helper(board, temp, i, n-1, m, n);
    }

    for (int j = 0; j < n; j++) {
        if(board[0][j] == 'O')
            helper(board, temp, 0, j, m, n);
        if(board[m-1][j] == 'O')
            helper(board, temp, m-1, j, m, n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'O' && temp[i][j] == 1)
                board[i][j] = 'X';
        }
    }
    return;
}

// faster BFS
void helper(vector<vector<char> > &vec, int i, int j, int row, int col){
    if(vec[i][j] == 'O'){
        vec[i][j] = '1';
        if(i > 1)
            helper(vec, i-1, j, row, col);
        if(i+1 < row)
            helper(vec, i+1, j, row, col);
        if(j > 1)
            helper(vec, i, j-1, row, col);
        if(j+1 < col)
            helper(vec, i, j+1, row, col);
    }
}

void solve2(vector<vector<char> > &board){
    // int i,j;
    // 如果这里提前定义了i，j
    // 那么在下面的for中就少定义两个局部变量
    // 最后的运行时间少4ms
    int row = board.size();
    if(row == 0)
        return;
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
        helper(board, i, 0, row, col);
        if(col > 1)
            helper(board, i, col-1, row, col);
    }
    for (int j = 1; j < col; j++) {
        helper(board, 0, j, row, col);
        if(row > 1)
            helper(board, row-1, j, row, col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == '1')
                board[i][j] = 'O';
        }
    }
}

void print(const vector<vector<char> > &board){
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > board;
    vector<char> b1;
    b1.push_back('O');
    b1.push_back('O');
    b1.push_back('O');
    //b1.push_back('o');
    vector<char> b2;
    b2.push_back('O');
    b2.push_back('O');
    b2.push_back('O');
    //b2.push_back('o');
    vector<char> b3;
    b3.push_back('O');
    b3.push_back('O');
    b3.push_back('O');
    //b3.push_back('o');
    //vector<char> b4;
    //b4.push_back('o');
    //b4.push_back('o');
    //b4.push_back('o');
    //b4.push_back('o');
    board.push_back(b1);
    board.push_back(b2);
    board.push_back(b3);
    //board.push_back(b4);

    print(board);
    solve2(board);
    print(board);
    return 0;
}
