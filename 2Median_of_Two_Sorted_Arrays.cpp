#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
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
};

int main(int argc, const char *argv[])
{
    return 0;
}
