#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sortColors(int A[], int n){
    if(n <= 1)
        return;
    int i = 0;
    int state = 0;
    while(i < n){
        if(A[i] == state){
           i++;
           continue;
        }
        int j = i+1;
        while(j < n){
            if(A[j] == state){
                swap(A[i], A[j]);
                break;
            }
            j++;
        }
        if(j == n)
            state++;
        if(state == 3)
            break;
    }
}

// 4ms
// 把0放左边，2放右边，1放中间
void sortColors2(vector<int> &nums){
    if(nums.size() < 2) 
        return;
    int left = 0;
    int right = nums.size()-1;
    while(left <= right && nums[left] == 0) 
        left++;
    while(right >= left && nums[right] == 2)
        right--;
    if(left >= right)
        return;
    int tempLeft = left;
    while(tempLeft < right){
        if(nums[tempLeft] == 0){
            swap(nums[tempLeft], nums[left]);
            tempLeft++;
            left++;
        }else if(nums[tempLeft] == 2){
            swap(nums[tempLeft], nums[right]);
            right--;
            while(nums[right] == 2) 
                right--;
            if(nums[tempLeft] == 1)
                tempLeft++;
        }else
            tempLeft++;
    }
    if(nums[tempLeft] == 0)
        swap(nums[tempLeft], nums[left]);
}

int main(int argc, const char *argv[])
{
    vector<int> A{2,1};
    sortColors2(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
