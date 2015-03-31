#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int n){
    vector<vector<int> > res;
    for (int i = 0; i < n; i++) {
        res.push_back(vector<int>(n, 1));
    }
    if(n <= 1)
        return res;

    int num = 1;
    int i = 0, j = 0;
    int count = 0;
    while(num <= n*n){
        while(j < n-count){
            res[i][j] = num++;
            j++;
        }
        j--;i++;

        while(i < n - count){
            res[i][j] = num++;
            i++;
        }
        i--;j--;

        while(j >= count){
            res[i][j] = num++;
            j--;
        }
        j++;i--;

        while(i > count){
            res[i][j] = num++;
            i--;
        }
        i++;j++;
        count++;
    }


    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > res;
    res = generateMatrix(5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
