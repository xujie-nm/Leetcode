#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isBadVersion(int version){
    if(version >= 1702766719)
        return true;
    else
        return false;
}

//long long int
long long int firstBadVersion(long long int n){
    if(n == 0)
        return 0;
    long long int res = n;
    long long int low = 0;
    long long int high = n;
    long long int mid;
    while(low <= high){
        mid = (low + high)/2;
         if(isBadVersion(mid)){
            if(mid < res)
                res = mid;
            else
                break;
            high = mid - 1;
         }else{
            low = mid + 1;
         }
    }
    return res;
}

//int
int firstBadVersion2(int n){
    if(n == 0)
        return 0;
    int res = n;
    int low = 0;
    int high = n;
    int mid;
    while(low <= high){
        mid = low +  (high - low)/2;
         if(isBadVersion(mid)){
            if(mid < res)
                res = mid;
            else
                break;
            high = mid - 1;
         }else{
            low = mid + 1;
         }
    }
    return res;
}
int main(int argc, const char *argv[])
{
    cout << firstBadVersion2(2126753390) << endl;
    return 0;
}
