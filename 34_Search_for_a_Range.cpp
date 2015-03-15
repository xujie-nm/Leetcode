#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> searchRange(int A[], int n, int target){
    vector<int> res;
    int res_index = -1;
    int high = n - 1;
    int low = 0;
    int mid;

    while(high >= low){
        mid = (high + low)/2;
        if(target == A[mid]){
            res_index = mid;
            break;
        }
        else if(A[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    high = res_index;
    low = res_index;
    if(res_index != -1){
        while(high < n){
            if(A[++high] != target)
                break;
        }
        
        while(low >= 0){
            if(A[--low] != target)
                break;
        }
        ++low;
        --high;
    }

    res.push_back(low);
    res.push_back(high);
    return res;
}

int main(int argc, const char *argv[])
{
    int A[] = {5,7,7,8,8,10};
    vector<int> res;
    res = searchRange(A, 6, 5);

    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
