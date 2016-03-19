#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int i_tar = -1;

    for (int i = 0; i < n; i++) {
        if(matrix[i][0] == target || matrix[i][m-1] == target){
            return true;
        }
        if(matrix[i][0] < target && matrix[i][m-1] > target){
            i_tar = i;
            break;
        }
    }

    if(i_tar == -1)
        return false;

    int low = 0;
    int high = m-1;
    while(low < high){
        int mid = low + (high - low)/2;
        if(matrix[i_tar][mid] == target){
            return true;
        }
        else if(matrix[i_tar][mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(matrix[i_tar][low] == target || matrix[i_tar][high] == target){
        return true;
    }
    return false;
}

// Faster
bool searchMatrix2(vector<vector<int> >& matrix, int target){
    int rows = matrix.size();
    if(rows == 0)
        return false;
    int columns = matrix[0].size();
    if(columns == 0)
        return false;
    int row = 0;
    int column = columns-1;
    while(row < rows && column >= 0){
        // 未查找的区域总是当前数字作为右上角的矩形
        // 如果当前数字大于查找数字，则剔除所在列（到前一列）
        // 如果当前数字小于查找数字，则剔除所在行（到下一行）
        if(matrix[row][column] == target)
            return true;
        else if(matrix[row][column] > target)
            column--;
        else
            row++;
    }
    return false;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(3);
    line1.push_back(5);
    line1.push_back(7);
    vector<int> line2;
    line2.push_back(10);
    line2.push_back(11);
    line2.push_back(16);
    line2.push_back(10);
    vector<int> line3;
    line3.push_back(23);
    line3.push_back(30);
    line3.push_back(34);
    line3.push_back(50);
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);

    cout << searchMatrix2(matrix, 23) << endl;
    return 0;
}
