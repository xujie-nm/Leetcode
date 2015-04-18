#include <iostream>
#include <string>
#include <vector>
using namespace std;

int removeDuplicates(int A[], int n){
    if(n <= 2)
        return n;
    int first = 1;
    int second = 1;
    int count = 1;
    while(first < n && second < n){
        if(A[second] != A[second-1]){
            A[first] = A[second];
            first++;
            count = 1;
        }else if(A[second] == A[second-1] && count < 2){
            A[first] = A[second];
            first++;
            count++;
        }
        second++;
    }
    return first;
}

int main(int argc, const char *argv[])
{
    int A[] = {1, 1, 1, 2, 2, 3};
    cout  << removeDuplicates(A, 6) << endl;
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}

