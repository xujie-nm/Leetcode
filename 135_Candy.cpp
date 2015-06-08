#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//二重循环TLE
//换成一层循环，使用数组记录信息

int candy(vector<int> &ratings){
    if(ratings.size() == 1)
        return 1;

    vector<int> left(ratings.size(), 1);
    vector<int> right(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++) {
        if(ratings[i] > ratings[i-1])
            left[i] = left[i-1] + 1;
    }

    for (int i = ratings.size()-2; i >= 0 ; i--) {
        if(ratings[i] > ratings[i+1])
            right[i] = right[i+1] + 1;
    }
    
    

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += max(left[i], right[i]);
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    vector<int> rate;
    rate.push_back(1);
    rate.push_back(2);
    rate.push_back(2);

    cout << candy(rate) << endl;
    return 0;
}
