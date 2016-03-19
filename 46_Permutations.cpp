#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool back(vector<int> &num, vector<int> &temp, vector<bool> &flag, vector<vector<int> > &res){
    if(temp.size() == num.size()){
        res.push_back(temp);
        return true;
    }
    if(temp.size() > num.size())
        return false;

    for (int i = 0; i < num.size(); i++) {
        if(flag[i] == true)
            continue;
        else{
            temp.push_back(num[i]);
            flag[i] = true;
            back(num, temp, flag, res);
            flag[i] = false;
            temp.pop_back();
        }
    }
}

vector<vector<int> > permute(vector<int> &num){
    vector<vector<int> > res;
    if(num.size() ==1){
        res.push_back(num);
        return res;
    }

    vector<bool> flag(num.size(), false);
    vector<int> temp;
    back(num, temp, flag, res);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(3);
    vector<vector<int> > res = permute(num);
    for(vector<vector<int> >::iterator it_i = res.begin(); it_i != res.end(); ++it_i){
         for(vector<int>::iterator it = (*it_i).begin(); it != (*it_i).end(); ++it){
             cout << *it << " ";    
         }
         cout << endl;
    }
    return 0;
}
