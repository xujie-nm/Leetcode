#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// sort, not effective
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    if(nums1.empty() || nums2.empty())
        return res;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end() && it2 != nums2.end()){
        if(*it1 == *it2){
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
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    if(nums1.empty() || nums2.empty())
        return res;

    unordered_map<int, int> hash;

    for (int i = 0; i < nums2.size(); i++)
        hash[nums2[i]]++;

    for (int i = 0; i < nums1.size(); i++) {
        if(hash.count(nums1[i]) > 0){
            res.push_back(nums1[i]);
            hash[nums1[i]]--;
            if(hash[nums1[i]] == 0)
                hash.erase(nums1[i]);
        }
    }

    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    vector<int> res;

    res = intersect2(nums1, nums2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
