#include <iostream>
#include <string>
#include <vector>
using namespace std;

int search(int A[], int n, int target){
    if(n == 1){
        if(A[0] == target)
            return 0;
        else
            return -1;
    }
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if(A[i] > A[i+1]){
            pos = i;
            break;
        }
    }
    
    int high, low, mid;
    if(pos != -1){
        if(target >= A[0])
        {
            high = pos;
            low = 0;
        }
        else{
            high = n-1;
            low = pos + 1;
        }
    }
    else{
        high = n-1;
        low = 0;
    }
    
    while(high >= low){
        mid = (low + high)/2;
        if(target > A[mid])
            low = mid + 1;
        else if(target < A[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int search(vector<int>&nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid;

    while(low <= high){
        mid = (high-low)/2 +low;
        if(nums[mid] == target)
            return mid;

        if(nums[mid] > nums[high]){ // 说明左半段肯定是有序的
            if(target >= nums[low] && target < nums[mid]) // 确定是否肯定在有序的那一部分
                high = mid-1;
            else
                low = mid+1;
        }else{ // 说明右半段肯定是有序的
            if(target > nums[mid] && target <= nums[high])// 确定是否肯定在有序的那一部分
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}
int main(int argc, const char *argv[])
{
    vector<int> a{4, 5, 6, 7, 0, 1, 2} ;
    cout << "pos is: " << search(a, 2) << endl;
    return 0;
}
