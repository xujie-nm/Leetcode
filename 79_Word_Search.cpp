#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool helper(vector<vector<char> > &board, string &word, int row, int col, int cur){
    if(row < 0 || col < 0 || row >= board.size()
       || col >= board[0].size()
       || board[row][col] == '\0'
       || word[cur] != board[row][col])
        return false;

    if(word.size()-1 == cur)
        return true;
    char t = board[row][col];
    board[row][col] = '\0';//avoid rollback
    if(helper(board, word, row-1, col, cur+1)
     ||helper(board, word, row+1, col, cur+1)
     ||helper(board, word, row, col-1, cur+1)
     ||helper(board, word, row, col+1, cur+1))
        return true;
    board[row][col] = t;
    return false;

}

bool exist(vector<vector<char> > board, string word){
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if(helper(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > board;
    vector<char> line1;
    line1.push_back('A');
    line1.push_back('B');
    line1.push_back('C');
    line1.push_back('E');
    vector<char> line2;
    line2.push_back('S');
    line2.push_back('F');
    line2.push_back('C');
    line2.push_back('S');
    vector<char> line3;
    line3.push_back('A');
    line3.push_back('D');
    line3.push_back('E');
    line3.push_back('E');
    board.push_back(line1);
    board.push_back(line2);
    board.push_back(line3);

    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCB") << endl;
    return 0;
}
