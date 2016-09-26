#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
    int i = 0;
    int j = 0;
    vector<pair<int, int> > ret;
    int k1 = 0;
    while(i < nums1.size() && j < nums2.size() && k1 < k)
    {
        ret.push_back(make_pair(nums1[i], nums2[j]));
        if(i == nums1.size()-1)
            j++;
        else if( j == nums2.size()-1)
            i++;
        else
        {
            if(nums1[i+1] + nums2[j] < nums1[i] + nums2[j+1])
                i++;
            else
                j++;
        }
    }

    return ret;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{1, 7, 11};
    vector<int> nums2{2, 4, 6};

    vector<pair<int, int> > res;
    res = kSmallestPairs(nums1, nums2, 3);

    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i].first << "," << res[i].second << "]" << endl;
    }
    return 0;
}
