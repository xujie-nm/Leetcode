#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//the point is A^B^A = B;

int singleNumber1(vector<int> &nums){
    int ones = 0, twos = 0, threes = 0;
    //'ones' which represent i-th bit appeared once
    //'twos' which represent i-th bit appeared twice
    //'threes' which represent i-th bit appeared three times
    for (int i = 0; i < nums.size(); i++) {
        twos |= ones & nums[i];

        ones ^= nums[i];

        threes = ones & twos;

        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}

int singleNumber2(vector<int> &nums){
    map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        hash[nums[i]]++;
    }
    
    for(map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it){
        if(it->second == 1)
            return it->first;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(3);
    num.push_back(3);
    cout << singleNumber2(num) << endl;
    return 0;
}
