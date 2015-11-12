#include <iostream>
#include <string>
#include <vector>
using namespace std;

// res(row1,col1, row2, col2) =
// sumMatrix(row2, col2) - sumMatrix(row2, col1-1)
// - sumMatrix(row1-1, col2) + sumMatrix(row1-1, col1-1);

class NumMatrix{
    public:
        NumMatrix(vector<vector<int> > &matrix){
            int curSum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                curSum = 0;
                vector<int> temp;
                for (int j = 0; j <matrix[i].size(); j++) {
                    if(i == 0){
                        curSum += matrix[i][j];
                        temp.push_back(curSum);
                    }else{
                        curSum += matrix[i][j];
                        temp.push_back(curSum + sumMatrix_[i-1][j]);
                    }
                }
                sumMatrix_.push_back(temp);
            }

            //test
            for (int i = 0; i < sumMatrix_.size(); i++) {
                for (int j = 0; j < sumMatrix_[i].size(); j++) {
                    cout << sumMatrix_[i][j] << " ";
                }
                cout << endl;
            }
            //test
        }

        int sumRegion(int row1, int col1, int row2, int col2){
            if(row1 == 0 && col1 == 0)
                return sumMatrix_[row2][col2];
            else if(row1 == 0)
                return sumMatrix_[row2][col2] - sumMatrix_[row2][col1-1];
            else if(col1 == 0)
                return sumMatrix_[row2][col2] - sumMatrix_[row1-1][col2];
            else
                return sumMatrix_[row2][col2] - sumMatrix_[row2][col1-1]
                     - sumMatrix_[row1-1][col2] + sumMatrix_[row1-1][col1-1];
        }

    private:
        vector<vector<int> > sumMatrix_;
};

int main(int argc, const char *argv[])
{
    vector<int> line1{3,0,1,4,2};
    vector<int> line2{5,6,3,2,1};
    vector<int> line3{1,2,0,1,5};
    vector<int> line4{4,1,0,1,7};
    vector<int> line5{1,0,3,0,5};
    vector<vector<int> > matrix{line1, line2, line3, line4, line5};

    NumMatrix numMatrix(matrix);
    cout << "res: " << endl;
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
    cout << numMatrix.sumRegion(0, 0, 2, 2) << endl;
    cout << numMatrix.sumRegion(0, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 0, 2, 2) << endl;
    return 0;
}
