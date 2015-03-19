#include <iostream>
#include <string>
#include <vector>
using namespace std;

int firstMissingPositive(int A[], int n){
   if(n <= 0)
       return 1;
   else if(n == 1)
       if(A[0] > 1 || A[0] < 1)
           return 1;
       else
           return 2;

   int min_po;
   int last_flag = false;
   min_po = 1;
   for (int i = 0; i < n; i++) {
       if(A[i] >0 && A[i] < min_po)
           min_po = A[i];
   }

   if(min_po > 1)
       return 1;
   for (int i = 0; i < n; i++) {
       if(A[i] == min_po){
            i = -1;
            if(min_po == n)
                last_flag = true;
            min_po++;
       }
   }

   if(min_po < n || (min_po == n && !last_flag))
       return min_po;
   else if(min_po == n && last_flag)
       return min_po + 1;
}

int main(int argc, const char *argv[])
{
    int A[] = {-10, -3, -100, -1000, -239, 1};
    cout << firstMissingPositive(A, 6) << endl;;
    
    return 0;
}
