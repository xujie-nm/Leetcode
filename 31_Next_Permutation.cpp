#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//从排列的右端开始，找出第一个比右边数字小的序号j
//在pj右边的数字中，找出所有比pj大的数中的最小数pk
//（因为右边的数从右到左是递增的，因此k就是所有大于pj
//的序号的最大者）
//对换pj和pk
//再将pj后的数反转

void nextPermutation(vector<int> &num){
    int size = num.size();
    int i , j;
    for (i = size - 2; i >= 0; i--) {
        if(num[i] < num[i + 1]) break;
    }
    for (j = size - 1; j > i; j--) {
        if(num[j] > num[i]) break;
    }

    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
    
    reverse(num.begin() + i + 1, num.end());
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    res.push_back(2);
    res.push_back(4);
    res.push_back(3);
    res.push_back(8);
    res.push_back(7);
    res.push_back(6);
    res.push_back(5);
    res.push_back(1);
    nextPermutation(res);

    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
