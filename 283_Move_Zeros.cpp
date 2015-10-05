#include <iostream>
#include <string>
#include <vector>
using namespace std;

//
void moveZeros(vector<int> &nums){
    if(nums.size() == 1)
        return;
    int i = 0;
    int j = 0;
    while(j < nums.size() && i < nums.size()){
        while(nums[i] == 0 && i < nums.size())
            i++;
        while(nums[j] != 0 && j < nums.size())
            j++;
        if(i > j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            //i++;
            //j++;
        }else
            i++;
    }
}

//
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

    moveZeros2(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
