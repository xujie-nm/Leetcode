#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVaild(vector<string> &temp, int n,int x, int y){
    for (int i = 0; i < x; i++) {
        if(temp[i][y] == 'Q')
            return false;
    }
    for (int i = x-1, j = y-1; i >=0&&j>=0; i--,j--) {
        if(temp[i][j] == 'Q')
            return false;
    }
    for (int i = x-1,j = y+1; i >=0&&j<n; i--, j++) {
        if(temp[i][j] == 'Q')
            return false;
    }
    
    return true;
}


bool back(vector<vector<string> > &res, vector<string> &temp, int size, int loc){
    if(loc == size){
        res.push_back(temp);
        return true;
    }
    else if(loc > size){
        return false;
    }

    for (int j = 0; j < size; j++) {
        if(isVaild(temp, size, loc, j) == true){
            string t1(j, '.');
            string t2(size-j-1, '.');
            temp.push_back(t1+'Q'+t2);
            back(res, temp, size, loc+1);
            temp.pop_back();
        }
    }
}

vector<vector<string> > solveNQueen(int n){
    vector<vector<string> > res;
    vector<string> temp;

    back(res, temp, n, 0);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<vector<string> > res;
    res = solveNQueen(8);

    for(vector<vector<string> >::iterator it_i = res.begin(); it_i != res.end(); ++it_i){
        for(vector<string>::iterator it = (*it_i).begin(); it != (*it_i).end(); ++it){
            cout << *it << endl;    
        }
        cout << endl;
    }
    cout << res[0].size() << endl;
    cout << res[0][0].size() << endl;
    cout << res.size() << endl;
    return 0;
}
