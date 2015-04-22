#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char> > &matrix){
    if(matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    int maxA = 0;

    for (int i = 0; i < m; i++) {
        int cur_left = 0, cur_right = n;
        for (int j = 0; j < n; j++) {//计算每一列的高
            if(matrix[i][j] == '1')
                height[j]++;
            else 
                height[j] = 0;
        }

        for (int j = 0; j < n; j++) {//计算最左边的不为0的
            if(matrix[i][j] == '1')
                left[j] = max(left[j], cur_left);
            else{
                left[j] = 0;
                cur_left = j+1;
            }
        }

        for (int j = n-1; j >= 0; j--) {//计算最右边不为0的
            if(matrix[i][j] == '1')
                right[j] = min(right[j], cur_right);
            else{
                right[j] = n;
                cur_right = j;
            }
        }
        
        for (int j = 0; j < n; j++) 
            maxA = max(maxA, (right[j]-left[j]) * height[j]);

    }
    return maxA;
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > matrix;
    vector<char> line1;
    line1.push_back('1');
    line1.push_back('1');
    line1.push_back('1');
    line1.push_back('1');
    line1.push_back('1');
    vector<char> line2;
    line2.push_back('1');
    line2.push_back('1');
    line2.push_back('1');
    line2.push_back('0');
    line2.push_back('1');
    vector<char> line3;
    line3.push_back('1');
    line3.push_back('1');
    line3.push_back('1');
    line3.push_back('0');
    line3.push_back('0');
    vector<char> line4;
    line4.push_back('1');
    line4.push_back('0');
    line4.push_back('0');
    line4.push_back('0');
    line4.push_back('0');
    vector<char> line5;
    line5.push_back('1');
    line5.push_back('0');
    line5.push_back('0');
    line5.push_back('0');
    line5.push_back('0');
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    matrix.push_back(line5);

    cout << maximalRectangle(matrix) << endl;
    return 0;
}
