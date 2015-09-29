#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// O(n)
int hIndex(vector<int> &citations){
    if(citations.size() == 0)
        return 0;
    int res = 0;
    for (int i = citations.size()-1; i >= 0; i--) {
        if(citations[i] > res)
            res++;
        else
            break;
    }
    return res;
}

//O(logn)
int hIndex2(vector<int> &citations){
    if(citations.size() == 0)
        return 0;
    int n = citations.size();
    int paper = 0;
    int low = 0;
    int high = n - 1;
    int mid; 
    while(low <= high){
        mid = (low + high)/2;
        if(n-mid > citations[mid]){
            low = mid + 1;
        }else if(n-mid < citations[mid]){
            paper = n-mid;
            high = mid - 1;
        }else{
            paper = n-mid;
            break;
        }
    }
    return paper;
}

int main(int argc, const char *argv[])
{
    vector<int> citations;
    citations.push_back(1);
    citations.push_back(1);
    citations.push_back(4);
    citations.push_back(5);
    citations.push_back(6);
    citations.push_back(6);

    cout << hIndex2(citations) << endl;;
    return 0;
}
