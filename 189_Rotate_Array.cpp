#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotate1(vector<int> &nums, int k){
    int size = nums.size();
    if(size <= 1 || k == 0 || k == size)
        return;

    reverse(nums.begin(), nums.end());
    if(k > size)
        k %= size;
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());

}

void rotate2(vector<int> &nums, int k){
   int size = nums.size();
   if(size <= 1 || k == 0 || k == size)
       return;

   vector<int> temp;
   k %= size;
   for (int i = size - k; i < size; i++) {
       temp.push_back(nums[i]);
   }
   
   for (int i = 0; i < size - k; i++) {
       temp.push_back(nums[i]);
   }
    
   for (int i = 0; i < size; i++) {
       nums[i] = temp[i];
   }
}

void rotate3(vector<int> &nums, int k){
    int size = nums.size();
    if(size <= 1 || k == 0 || k == size)
        return;

    k %= size;
    while(k > 0){
        int temp = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), temp);
        k--;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    /*
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    */
    
    rotate3(nums, 4);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
