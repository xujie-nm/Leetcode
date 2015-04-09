#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

void init(map<int, vector<char> > &hash_map, int rows[][9], int columns[][9], int boxs[][9]){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            vector<char> temp_i;
            for(int num = 0; num < 9; num++){
                if(!rows[i][num])
                    temp_i.push_back(num + '0' + 1);
            }
            vector<char> temp_j;
            for(int num = 0; num < 9; num++){
                if(!columns[j][num])
                    temp_j.push_back(num + '0' + 1);
            }

            vector<char> temp_k;
            int k = i/3 * 3+ j/3;
            for(int num = 0; num < 9; num++){
                if(!boxs[k][num])
                    temp_k.push_back(num + '0' + 1);
            }

         
            vector<char> temp;
            for (int num = 0; num < 9; num++) {
                if(count(temp_i.begin(), temp_i.end(), num + '0' +1) && 
                   count(temp_j.begin(), temp_j.end(), num + '0' +1) && 
                   count(temp_k.begin(), temp_k.end(), num + '0' +1)){
                
                    temp.push_back(num + '0' + 1);
                }

            }
            if(!temp.empty())
                hash_map.insert(make_pair(i*9+j, temp));

        }
    }
}

void solveSudoku(vector<vector<char> > &board){
    int rows[9][9] = {0};
    int columns[9][9] = {0};
    int boxs[9][9] = {0};
    map<int, vector<char> > hash_map;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1;
                int k = i/3 *3+ j/3;
                rows[i][num] = 1;
                columns[j][num] = 1;
                boxs[k][num] = 1;
            }
        }
    }


    init(hash_map, rows, columns, boxs);


    while(hash_map.size() > 0){
        for(map<int, vector<char> >::iterator it = hash_map.begin(); it != hash_map.end(); ++it){
            if((it->second).size() == 1){
                if(board[it->first/9][it->first%9] == '.')
                board[it->first/9][it->first%9] = (it->second)[0];
            }
        }

        int rows[9][9] = {0};
        int columns[9][9] = {0};
        int boxs[9][9] = {0};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;
                    rows[i][num] = 1;
                    columns[j][num] = 1;
                    boxs[k][num] = 1;
                }
            }
        }
        hash_map.clear();
        init(hash_map, rows, columns, boxs);

    }
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
