#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix){
    int n = matrix.size();
    for (int i = 0; i < n/2; i++) {
        int up = n%2==0 ? n/2 : (n/2+1);
        for (int j = 0; j < n/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1] = temp;
        }
    }
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    matrix.push_back(row1);
    matrix.push_back(row2);
    rotate(matrix);
    for(auto &item: matrix){
            for(auto &item1: item){
                    cout << item1 << " ";
            }
            cout << endl;
    }
    return 0;
}
