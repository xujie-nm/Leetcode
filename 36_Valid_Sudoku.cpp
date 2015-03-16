#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board){
    int rows[9][9] = {0};
    int columns[9][9] = {0};
    int boxs[9][9] = {0};

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1;
                int k = i/3 + j/3 * 3;
                if(rows[i][num] || columns[j][num] || boxs[k][num])
                    return false;
                rows[i][num] = 1;
                columns[j][num] = 1;
                boxs[k][num] = 1;
            }
        }
    }

    return true;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
