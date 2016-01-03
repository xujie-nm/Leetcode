#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map_index(int index, int n){
    return (2 * index + 1) % (n | 1);
}

void wiggleSort(vector<int>& nums){
    if(nums.empty()){
        return;
    }
    int n = nums.size();

    // 找到中位数
    vector<int>::iterator nth = next(nums.begin(), n/2);
    nth_element(nums.begin(), nth, nums.end());
    int median = *nth;

    // 开始把元素放到合适的位置上
    // 这里的小技巧在于前面(first)和后面(last)的映射正好是叉开的
    int first = 0, mid = 0, last = n - 1;
    while(mid <= last){
        if(nums[map_index(mid, n)] > median) {
        // 如果当前mid的映射大了，就把大的放到前面的映射
            swap(nums[map_index(first, n)], nums[map_index(mid, n)]);
            ++first;
            ++mid;
        }else if(nums[map_index(mid, n)] < median){
        // 如果当前的mid的映射小了，就把他放到后面的映射
            swap(nums[map_index(mid, n)], nums[map_index(last, n)]);
            --last;
        }else{
            ++mid;
        }
    }
}

void wiggleSort2(vector<int>& nums){
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i = nums.size()-1, j=0, k = i/2 + 1; 
            i >= 0; i--) {
        nums[i] = sorted[i&1 ? k++ : j++];
    }
}

int main(int argc, const char *argv[])
{
    vector<int> nums{1, 3, 2, 2, 3, 1};
    wiggleSort2(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
