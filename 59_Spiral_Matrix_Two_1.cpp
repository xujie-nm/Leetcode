#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int n){
    vector<vector<int> > res;
    
    for (int i = 0; i < n; i++) {
        vector<int> row;
        res.push_back(row);
        for (int j = 0; j < n; j++) {
            res[i].push_back(0);
        }
    }

    int begin = 1;
    int loop = n/2;
    if(n%2 == 0) loop--;

    for (int i = 0; i <= loop; i++) {
        int up = i, down = n-i-1, right = n-i-1, left = i;
        int x = left, y = up;
        //right
        for (; x <= right; x++) {
            res[y][x] = begin++;
        }

        //down
        for (x--, y=y+1; y <= down; y++) {
            res[y][x] = begin++;
        }

        //left
        for(y--, x=x-1; x>=left; x--){
            res[y][x] = begin++;
        }

        //up
        for(x++, y=y-1; y>up; y--){
            res[y][x] = begin++;
        }
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
