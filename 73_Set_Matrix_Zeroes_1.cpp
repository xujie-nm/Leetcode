#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void setZero(vector<vector<int> > &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    //找到最後一個有0的行
    int last_0_row = -1;
    for (int y = n-1; y >= 0 && last_0_row == -1; y--)
        for (int x = 0; x < m; x++)
            if(matrix[y][x] == 0){
                last_0_row = y;
                break;
            }
    if(last_0_row == -1)
        return;
    //遍歷行
    for (int y = 0; y < last_0_row; y++){
        bool this_is_a_0_row = false;

        for (int x = 0; x < m; x++){
            if(matrix[y][x] == 0){
                this_is_a_0_row = true;
                matrix[last_0_row][x] = 0;
            }
        }

        if(this_is_a_0_row)
            for (int x = 0; x < m; x++)
                matrix[y][x] = 0;
    }

    //設置列爲0
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if(matrix[last_0_row][x] == 0)
                matrix[y][x] = 0;

    //對最後一行設置
    for (int x = 0; x < m; x++)
        matrix[last_0_row][x] = 0;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(0);
    line1.push_back(0);
    line1.push_back(0);
    line1.push_back(5);
    vector<int> line2;
    line2.push_back(4);
    line2.push_back(3);
    line2.push_back(1);
    line2.push_back(4);
    vector<int> line3;
    line3.push_back(0);
    line3.push_back(1);
    line3.push_back(1);
    line3.push_back(4);
    vector<int> line4;
    line4.push_back(1);
    line4.push_back(2);
    line4.push_back(1);
    line4.push_back(3);
    vector<int> line5;
    line5.push_back(0);
    line5.push_back(0);
    line5.push_back(1);
    line5.push_back(1);

    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    matrix.push_back(line5);
    setZero(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
