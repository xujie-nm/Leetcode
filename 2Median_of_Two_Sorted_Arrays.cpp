#include <iostream>
#include <string>
#include <vector>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    vector<int> res_array;
    double res;
    int i = 0;
    int j = 0;
    while(1)
    {   
        if(i < m && j < n)
        {   
            if(A[i] < B[j])
            {   
                res_array.push_back(A[i]);
                i++;
            }   
            else
            {   
                res_array.push_back(B[j]);
                j++;
            }   
        }   
        else if(i < m)
        {   
                                
            res_array.push_back(A[i]);
            i++;
        }   
        else if(j < n)
        {   
            res_array.push_back(B[j]);
            j++;
        }   
        else
            break;
    }   
    if(res_array.size() % 2 == 1)
    {   
        res = res_array[res_array.size()/2];
    }   
    else
    {   
        res = (double)((res_array[res_array.size()/2] + res_array[res_array.size()/2 - 1]) / (double)2.0);
    }   
    return res;
}

double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size() + nums2.size();
    int m = n/2;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    int val1 = 0;
    int val2 = 0;
    for (int i = 0; i <= m; i++) {
        val1 = val2;
        if(it1 < nums1.end() && it2 < nums2.end()){
            if(*it1 < *it2){
                val2 = *it1;
                it1++;
            }else{
                val2 = *it2;
                it2++;
            }
        }else if(it1 < nums1.end()){
            val2 = *it1;
            it1++;
        }else if(it2 < nums2.end()){
            val2 = *it2;
            it2++;
        }
    }
    if(n%2 == 0){
        return (double)(val1+val2)/2.0;
    }else
        return (double)val2;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{1,2,3,5,7,9};
    vector<int> nums2{6,8,10};
    cout << findMedianSortedArrays2(nums1, nums2) << endl;
    return 0;
}
