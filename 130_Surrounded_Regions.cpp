#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

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
    solve(board);
    print(board);
    return 0;
}
