#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 从尾部开始
void moveZeros(vector<int> &nums){
    if(nums.size() == 1)
        return;
    map<int, int> indexs;
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0){
            indexs[index] = nums[i];
            index++;
        }
    }
    //cout << "index: " << index << endl;
    for (auto it = indexs.begin(); it != indexs.end() ; it++) {
        nums[it->first] = it->second;
    }

    for (int i = index; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

// 删除，增加
void moveZeros2(vector<int> &nums){
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(*(nums.begin()+i) == 0){
            nums.erase(nums.begin()+i);
            i--;
            num++;
        }
    }

    while(num > 0){
        nums.push_back(0);
        num--;
    }
}

// swap
void moveZeros3(vector<int> &nums){
    // 当前数列中最后一个不为0的数
    int nonZeros = 0;

    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0){
            swap(nums[nonZeros++], nums[i]);
        }
    }
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(0);

    moveZeros3(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
