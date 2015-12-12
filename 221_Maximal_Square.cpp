#include <iostream>
#include <string>
#include <vector>
using namespace std;

//base on 85 maximal rectangle

int maximalSquare(vector<vector<char> > &matrix){
    if(matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> height(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, n);

    int maxA = 0;
    for (int i = 0; i < m; i++) {
        int curLeft = 0, curRight = n;
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == '1')
                height[j]++;
            else
                //对高度重置
                height[j] = 0;
        }

        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == '1')
                left[j] = max(left[j], curLeft);
            else{
                //对左边重置
                left[j] = 0;
                curLeft = j+1;
            }
        }

        for (int j = n-1; j >= 0; j--) {
            if(matrix[i][j] == '1')
                right[j] = min(right[j], curRight);
            else{
                //对右边重置
                right[j] = n;
                curRight = j;
            }
        }

        for (int j = 0; j < n; j++) {
            int len = min((right[j]-left[j]), height[j]);
            maxA = max(maxA, len*len); 
        }
    }
    

    return maxA;
}

int maximalSquare2(vector<vector<char> > &matrix){
   if(matrix.size() == 0) 
       return 0;
   int m = matrix.size();
   int n = matrix[0].size();
   int res = INT_MIN;
   vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

   for (int i = 1; i <= m; i++) {
       for (int j = 1; j <= n; j++) {
           if(matrix[i-1][j-1] == '1'){
               dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
               res = max(res, dp[i][j]);
           }
       }
   }
   return res*res;
}

int main(int argc, const char *argv[])
{
    vector<vector<char> > matrix;
    vector<char> line1;
    line1.push_back('0');
    line1.push_back('1');
    line1.push_back('1');
    line1.push_back('0');
    line1.push_back('1');
    vector<char> line2;
    line2.push_back('1');
    line2.push_back('1');
    line2.push_back('0');
    line2.push_back('1');
    line2.push_back('0');
    vector<char> line3;
    line3.push_back('0');
    line3.push_back('1');
    line3.push_back('1');
    line3.push_back('1');
    line3.push_back('0');
    vector<char> line4;
    line4.push_back('1');
    line4.push_back('1');
    line4.push_back('1');
    line4.push_back('1');
    line4.push_back('0');
    vector<char> line5;
    line5.push_back('1');
    line5.push_back('1');
    line5.push_back('1');
    line5.push_back('1');
    line5.push_back('1');
    vector<char> line6;
    line6.push_back('0');
    line6.push_back('0');
    line6.push_back('0');
    line6.push_back('0');
    line6.push_back('0');

    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    matrix.push_back(line5);
    matrix.push_back(line6);

    cout << "matrix.size: " << matrix.size() << endl;
    cout << "matrix.size: " << matrix[0].size() << endl;
    cout << maximalSquare(matrix) << endl;
    cout << maximalSquare2(matrix) << endl;
    return 0;
}
