#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVaild(const vector<int> &columns, int col){
    for(int c = 0; c<col; ++c){
        if((columns[c] == columns[col])
          || (col-c == columns[col] - columns[c])
          || (col-c == columns[c] - columns[col])){
            return false;
        }
    }
    return true;
}

int totalNQueens(vector<int> &columns, int col){
    if(col == columns.size())
        return 1;
    int total = 0;

    for (int row = 0; row < columns.size(); row++) {
        columns[col] = row;
        if(isVaild(columns, col)){
            total += totalNQueens(columns, col + 1);
        }
    }
    return total;
}

int totalNQueens(int n){
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
