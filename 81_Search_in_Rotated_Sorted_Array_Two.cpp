#include <iostream>
#include <string>
#include <vector>
using namespace std;

int left(int A[], int i){
    if(i > 0)
        while(A[i-1] == A[i])
            i--;
    return i;
}

int right(int A[], int n, int i){
    if(i < n-1)
        while(A[i+1] == A[i])
            i++;
    return i;
}

bool search(int A[], int n, int target){
    if(n == 1){
        if(A[0] == target)
            return true;
        else
            return false;
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
        if(target >= A[0]){
            high = right(A,n,pos);
            low = 0;
        }else{
            high = n-1;
            low = left(A,pos+1);
        }
    }else{
        high = n-1;
        low = 0;
    }

    while(high >= low){
        mid = (low + high)/2;
        if(target > A[mid]){
            low = right(A, n, mid + 1);
        }else if(target < A[mid]){
            high = left(A, mid - 1);
        }else
            return true;
    }
    return false;
}

// binary search
bool search2(vector<int> &nums, int target){
    int low = 0, high = nums.size()-1, mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(nums[mid] == target)
            return true;
        // 跳过重复的数
        if((nums[low] == nums[mid]) && (nums[high] == nums[mid])){
            ++low;
            --high;
        }else if(nums[low] <= nums[mid]){
            // 判断在那一半
            if((nums[low] <= target) && nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }else{
            if((nums[mid] < target) && (nums[high] >= target))
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return false;
}

int main(int argc, const char *argv[])
{
    int A[] = {0, 1, 2, 2};
    cout << search(A, 4, 2) << endl;
    return 0;
}
