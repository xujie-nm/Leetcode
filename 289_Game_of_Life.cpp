#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 这个题目的重点在于在一个位置上同时存储邻居和原来有没有Cell的信息
// 因为最多只有八个方向，个位足以存储邻居的信息，十位存储原来有没有Cell的信息
void countNeighbors(vector<vector<int> > &board){
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //把Cell转移到十位
            board[i][j] *= 10;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int neighbor = 0;
            if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] >= 10)
                neighbor++;
            if(i-1 >= 0 && board[i-1][j] >= 10)
                neighbor++;
            if(i-1 >= 0 && j+1 < n && board[i-1][j+1] >= 10)
                neighbor++;
            if(j+1 < n && board[i][j+1] >= 10)
                neighbor++;
            if(i+1 < m && j+1 < n && board[i+1][j+1] >= 10)
                neighbor++;
            if(i+1 < m && board[i+1][j] >= 10)
                neighbor++;
            if(i+1 < m && j-1 >= 0 && board[i+1][j-1] >= 10)
                neighbor++;
            if(j-1 >= 0 && board[i][j-1] >= 10)
                neighbor++;
            //个位记录邻居
            board[i][j] += neighbor;
        }
    }
}

void gameOfLife(vector<vector<int> > &board){
    int m = board.size();
    if(m == 0)
        return;
    int n = board[0].size();
    if(n == 0)
        return;
    countNeighbors(board);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int hasCell = board[i][j]/10;
            board[i][j] %= 10;
            if(hasCell){
                if(board[i][j] > 1 && board[i][j] <= 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }else
                if(board[i][j] == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
        }
    }
}

int main(int argc, const char *argv[])
{
    vector<int> line1{1,0,1,1};
    vector<int> line2{0,0,0,0};
    vector<int> line3{0,0,1,1};
    vector<int> line4{0,1,1,0};
    vector<vector<int> > board{line1, line2, line3, line4};

    gameOfLife(board);
    cout << "next: " << endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
