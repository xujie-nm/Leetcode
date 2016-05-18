#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


// sort, not effective
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    if(nums1.empty() || nums2.empty())
        return res;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end() && it2 != nums2.end()){
        if(*it1 == *it2){
            if(res.empty() || *it1 != res.back())
                res.push_back(*it1);
            ++it1;
            ++it2;
        }else if(*it1 < *it2)
            ++it1;
        else
            ++it2;

    }

    return res;
}

// hash, more effective
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2){
    if(nums1.empty() || nums2.empty())
        return vector<int> ();
   
    unordered_set<int> hash;
    unordered_set<int> res;

    for (int i = 0; i < nums1.size(); i++)
        hash.insert(nums1[i]);

    for (int i = 0; i < nums2.size(); i++) 
        if(hash.count(nums2[i]) > 0)
            res.insert(nums2[i]);
    return vector<int>(res.begin(), res.end());
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};

    vector<int> res;
    res = intersection2(nums1, nums2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
