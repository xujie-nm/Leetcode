#include <iostream>

#include <string>

#include <queue>
#include <vector>
#include <unordered_map>

#include <set>
#include <map>
using namespace std;

// use hashmap and map
vector<int> topKFrequent(vector<int>&nums, int k){
    vector<int> res;
    unordered_map<int, int> hash_1;
    for (int i = 0; i < nums.size(); i++) {
        hash_1[nums[i]]++;
    }

    // hash_2 的 first 为 frequent，second 为 number
    map<int, set<int> > hash_2;
    for(auto it = hash_1.begin(); it != hash_1.end(); it++)
        hash_2[it->second].insert(it->first);

    for(auto it_1 = hash_2.rbegin(); it_1 != hash_2.rend(); it_1++){
        for(auto it_2 = (it_1->second).begin(); 
                 it_2 != (it_1->second).end(); it_2++){
            if(k > 0){
                res.push_back(*it_2);
                k--;
            }else
                break;
        }
    }

    return res;
}

// use hash map and priority queue

vector<int> topKFrequent2(vector<int>& nums, int k){
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    vector<int> res;
    // pair<first, second>: first is frequent, second is number
    priority_queue<pair<int, int> > pq;
    for(auto it = map.begin(); it != map.end(); it++){
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > (map.size()-k)){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{5,3,1,1,1,3,73,1};
    vector<int>res;
    res = topKFrequent(nums, 2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
