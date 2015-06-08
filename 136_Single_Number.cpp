#include <iostream>
#include <string>
#include <vector>
using namespace std;

//the point is A^B^A = B;

int singleNumber(vector<int> &num){
    int res = 0;
    for (int i = 0; i < num.size(); i++) {
        res = res ^ num[i];
    }
    return res;    
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(3);
    cout << singleNumber(num) << endl;
    return 0;
}
