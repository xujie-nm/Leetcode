#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVaild(const vector<int> &columns, int col){
    // 判断竖着的和斜着的不冲突
    for(int c = 0; c<col; ++c){
        if((columns[c] == columns[col]) // 同一列
          || (col-c == columns[col] - columns[c]) // 左斜线
          || (col-c == columns[c] - columns[col])){ // 右斜线
            return false;
        }
    }
    return true;
}

int totalNQueens(vector<int> &columns, int col){
    if(col == columns.size())
        return 1;
    int total = 0;

    for (int queenPos = 0; queenPos < columns.size(); queenPos++) {
        columns[col] = queenPos;
        if(isVaild(columns, col)){
            total += totalNQueens(columns, col + 1);
        }
    }
    return total;
}

int totalNQueens(int n){
    // columns[i]代表的是第i行皇后所在的位置
    vector<int> columns(n, 0);
    return totalNQueens(columns, 0);
}


int main(int argc, const char *argv[])
{
    cout << "1: " << totalNQueens(1) << endl;
    cout << "2: " << totalNQueens(2) << endl;
    cout << "3: " << totalNQueens(3) << endl;
    cout << "4: " << totalNQueens(4) << endl;
    cout << "5: " << totalNQueens(5) << endl;
    cout << "6: " << totalNQueens(6) << endl;
    cout << "7: " << totalNQueens(7) << endl;
    return 0;
}
