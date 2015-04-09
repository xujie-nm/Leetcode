#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
    vector<int> res;
    int n = matrix.size();
    if(n == 0)
        return res;
    if(n == 1)
        return matrix[0];
    int m = matrix[0].size();
    int num = 0;
    int i = 0, j = 0;
    int count = 0;
    while(num < n * m){
        while(j < m - count){
            res.push_back(matrix[i][j]);
            num++;
            j++;
        }
        j--;
        i++;
        while(i < n - count) {
            res.push_back(matrix[i][j]);
            num++;
            i++;
        }
        i--;
        j--;
        
       while(j >= count){
            res.push_back(matrix[i][j]);
            num++;
            j--;
        }
        j++;
        i--;
        while(i > count){
            res.push_back(matrix[i][j]);
            num++;
            i--;
        }
        i++;
        j++;


        count++;
    }

    if(res.size() > n*m){
        res.erase(res.end()- (res.size() - n*m), res.end());
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(1);
    //line1.push_back(2);
    //line1.push_back(3);
    vector<int> line2;
    line2.push_back(4);
    //line2.push_back(5);
    //line2.push_back(6);
    vector<int> line3;
    line3.push_back(7);
    //line3.push_back(8);
    //line3.push_back(9);
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);

    vector<int> res;
    cout << matrix.size() << endl;
    res = spiralOrder(matrix);
    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << " ";    
    }
    cout << endl;
    return 0;
}
