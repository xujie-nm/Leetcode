#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

//当前字符是否在当前行中
bool isInRow(vector<vector<char> > &board, int i, char c){
    vector<char> &row = board[i];
    for (int k = 0; k < 9; k++) {
        if(row[k] == c)
            return true;
    }
    return false;
}
//当前字符是否在当前列中
bool isInCol(vector<vector<char> > &board, int j, char c){
    for (int k = 0; k < 9; k++) {
        if(board[k][j] == c)
            return true;
    }
    return false;
}
//当前字符是否在当前小矩形中
bool isInRec(vector<vector<char> > &board, int i, int j, char c){
    int bigrow = i/3, bigcol = j/3;
    for (int m = 3*bigrow; m < 3*(bigrow + 1); m++) {
        for (int n = 3*bigcol; n < 3*(bigcol + 1); n++) {
            if(board[m][n] == c)
                return true;
        }
        return false;
    }
}

bool util(vector<vector<char> > &board, int pos){
    if(pos >= 81)
        return true;
    int i = pos / 9;
    int j = pos % 9;
    //如果当前字符不是空，直接直接到下一个
    if(board[i][j] != '.')
        return util(board, pos + 1);
    //如果当前字符为空
    else{
        //首先遍历判断那个字符是行，列，小矩形中都没有的
        for(char c = '1'; c<= '9'; c++){
            if(!isInRow(board, i, c) &&
               !isInCol(board, j, c) &&
               !isInRec(board, i, j, c)){
                board[i][j] = c;
                //深度遍历下一个
                if(util(board, pos + 1))
                    return true;
                else
                    board[i][j] = '.';
            }
        }
        return false;
    }
}

void solveSudoku(vector<vector<char> > &board){
    util(board, 0);
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > A;
    vector<char> a1;
    a1.push_back('5');
    a1.push_back('3');
    a1.push_back('.');
    a1.push_back('.');
    a1.push_back('7');
    a1.push_back('.');
    a1.push_back('.');
    a1.push_back('.');
    a1.push_back('.');
    vector<char> a2;
    a2.push_back('6');
    a2.push_back('.');
    a2.push_back('.');
    a2.push_back('1');
    a2.push_back('9');
    a2.push_back('5');
    a2.push_back('.');
    a2.push_back('.');
    a2.push_back('.');
    vector<char> a3;
    a3.push_back('.');
    a3.push_back('9');
    a3.push_back('8');
    a3.push_back('.');
    a3.push_back('.');
    a3.push_back('.');
    a3.push_back('.');
    a3.push_back('6');
    a3.push_back('.');
    vector<char> a4;
    a4.push_back('8');
    a4.push_back('.');
    a4.push_back('.');
    a4.push_back('.');
    a4.push_back('6');
    a4.push_back('.');
    a4.push_back('.');
    a4.push_back('.');
    a4.push_back('3');
    vector<char> a5;
    a5.push_back('4');
    a5.push_back('.');
    a5.push_back('.');
    a5.push_back('8');
    a5.push_back('.');
    a5.push_back('3');
    a5.push_back('.');
    a5.push_back('.');
    a5.push_back('1');
    vector<char> a6;
    a6.push_back('7');
    a6.push_back('.');
    a6.push_back('.');
    a6.push_back('.');
    a6.push_back('2');
    a6.push_back('.');
    a6.push_back('.');
    a6.push_back('.');
    a6.push_back('6');
    vector<char> a7;
    a7.push_back('.');
    a7.push_back('6');
    a7.push_back('.');
    a7.push_back('.');
    a7.push_back('.');
    a7.push_back('.');
    a7.push_back('2');
    a7.push_back('8');
    a7.push_back('.');
    vector<char> a8;
    a8.push_back('.');
    a8.push_back('.');
    a8.push_back('.');
    a8.push_back('4');
    a8.push_back('1');
    a8.push_back('9');
    a8.push_back('.');
    a8.push_back('.');
    a8.push_back('5');
    vector<char> a9;
    a9.push_back('.');
    a9.push_back('.');
    a9.push_back('.');
    a9.push_back('.');
    a9.push_back('8');
    a9.push_back('.');
    a9.push_back('.');
    a9.push_back('7');
    a9.push_back('9');

    A.push_back(a1);
    A.push_back(a2);
    A.push_back(a3);
    A.push_back(a4);
    A.push_back(a5);
    A.push_back(a6);
    A.push_back(a7);
    A.push_back(a8);
    A.push_back(a9);


    solveSudoku(A);

    for(vector<vector<char> >::iterator it_A = A.begin(); it_A != A.end(); ++it_A){
        for(vector<char>::iterator it = (*it_A).begin(); it != (*it_A).end(); ++it){
            cout << *it << " ";    
        }
        cout << endl;
    }
    return 0;
}
