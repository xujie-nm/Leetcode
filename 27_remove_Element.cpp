#include <iostream>
#include <string>
#include <vector>
using namespace std;

int removeElement(int A[], int length, int elem){
    int i, j;
    int n = length;
    for (i = 0, j = 0; i < length; i++) {
        if(A[i] != elem){
            A[j++] = A[i];
        }else{
            n--;
        }
    }
    return n;
}

// from tail
int removeElement(vector<int>& nums, int val){
    int tail = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
        while(nums[tail] == val)
            tail--;
        if(nums[i] == val && i < tail){
            int temp = nums[tail];
            nums[tail] = nums[i];
            nums[i] = temp;
        }
    }

    while(1){
        if(!nums.empty() && nums.back() == val)
            nums.pop_back();
        else
            break;
    }
    return nums.size();
}

int main(int argc, const char *argv[])
{
    vector<int> a{1, 2, 3, 3, 4, 6, 7};
    int len = removeElement(a, 3);
    cout << "len: " << len << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
