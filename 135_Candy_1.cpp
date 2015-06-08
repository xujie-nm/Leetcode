#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//TLE
int candy(vector<int> &ratings){
    if(ratings.size() == 1)
        return 1;

    vector<int> count(ratings.size(), 1);
    int sum = 0;
    for (int i = 0; i < ratings.size(); i++) {
        int left = 1, right = 1;
        if(i > 0){
            for (int a = 1; a <= i; a++) {
                if(ratings[i] > ratings[i-1])
                    left++;
                else
                    left = 1;
            }
        }
        
        if(i < ratings.size()-1){
            for (int b = ratings.size() - 2; b >= i; b--) {
                if(ratings[i] > ratings[i+1])
                    right++;
                else
                    right = 1;
            }
        }
        sum += max(right, left);
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
