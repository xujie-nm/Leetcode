#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void setZero(vector<vector<int> > &matrix){
   int n  = matrix.size();
   if(n==0)
       return;
   int m = matrix[0].size();
   set<pair<int, int> > loc_set;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           if(matrix[i][j] == 0)
               loc_set.insert(make_pair(i ,j));
       }
   }

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           pair<int, int> ij(i, j);
           if(loc_set.count(ij)){
                for (int i_1 = 0; i_1 < n; i_1++) {
                    if(matrix[i_1][j] != 0)
                        matrix[i_1][j] = 0;
                }
                for (int j_1 = 0; j_1 < m; j_1++) {
                    if(matrix[i][j_1] != 0)
                        matrix[i][j_1] = 0;
                }
           }
       }
   }
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
