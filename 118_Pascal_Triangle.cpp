#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows){
    vector<vector<int> > res;
    vector<int> temp;
    if(numRows == 0)
        return res;
    temp.push_back(1);
    res.push_back(temp);
    if(numRows > 1){
        for (int i = 2; i <= numRows; i++) {
            vector<int> temp1(i, 1);
            for (int j = 1; j < i-1; j++) {
                temp1[j] = (res.back())[j] + (res.back()) [j-1];
            }
            res.push_back(temp1);
        }
    }
   return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > res;
    res = generate(6);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
