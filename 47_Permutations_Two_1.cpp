#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool back(vector<int> num, int cur, int len, vector<vector<int> > &res){
    //這裏的num不是應用說明每次傳進來的是num的副本，對副本進行操作
    if(cur == len - 1){
        //說明此時到數組的頭了
        res.push_back(num);
        return true;
    }

    for (int i = cur; i < len; i++) {
        if(cur != i && num[cur] == num[i])
            continue;
        else{
            int temp;
            temp = num[i];
            num[i] = num[cur];
            num[cur] = temp;
            //交換，找下一個排列
            //開始對下一個數操作
            back(num, cur+1, len, res);
        }
    }
}

vector<vector<int> > permuteUnique(vector<int> &num){
    vector<vector<int> > res;
    if(num.size() ==1){
        res.push_back(num);
        return res;
    }
    sort(num.begin(), num.end());
    back(num, 0, num.size(), res);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    cout << "ok" << endl;
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    vector<vector<int> > res = permuteUnique(num);
    for(vector<vector<int> >::iterator it_i = res.begin(); it_i != res.end(); ++it_i){
         for(vector<int>::iterator it = (*it_i).begin(); it != (*it_i).end(); ++it){
             cout << *it << " ";    
         }
         cout << endl;
    }
    return 0;
}
