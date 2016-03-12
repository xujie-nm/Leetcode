#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


vector<vector<int> > threeSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    int n = num.size();
    for (int i = 0; i < n-2; i++) {
        if(i > 0 && num[i-1] == num[i])
            continue;
        int first = num[i];
        int low = i+1;
        int high = n-1;
        while(low < high){
            int second = num[low];
            int third = num[high];
            if(first+second+third == target){
                vector<int> v;
                v.push_back(first);
                v.push_back(second);
                v.push_back(third);
                result.push_back(v);
                while(low < n && num[low] == num[low+1])
                    low++;
                while(high > 0 && num[high] == num[high-1])
                    high--;
                low++;
                high--;
             }else if(first + second + third > target){
                while(high > 0 && num[high] == num[high-1])
                    high--;
                high--;
             }else{
                while(low < n && num[low] == num[low+1])
                    low++;
                low++;
             }
        }
    }
    return result;
}

vector<vector<int> > fourSum(vector<int> &num, int target)
{
    vector<vector<int> > result;
    if(num.size() < 4)
        return result;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size() - 3; i++) {
        if(i>0 && num[i-1] == num[i])
            continue;
        vector<int> n(num.begin()+i+1, num.end());
        vector<vector<int> > ret = threeSum(n, target-num[i]);
        for (int j = 0; j < ret.size(); j++) {
            ret[j].insert(ret[j].begin(), num[i]);
            result.push_back(ret[j]);
        }
    }
    return result;
}

vector<vector<int> > fourSum2(vector<int> &num, int target){
    vector<vector<int> > res_vec;
    int n = num.size();
    if(n < 4)
        return res_vec;
    sort(num.begin(), num.end());
    unordered_map<int, vector<pair<int, int> > > maps;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            maps[num[i]+num[j]].push_back(make_pair(i, j));
        }
    }

    for(unordered_map<int, vector<pair<int, int> > >::iterator it = maps.begin(); it != maps.end(); ++it){
        int temp = target - it->first;
        if(maps.count(temp) > 0)
        {
            for(vector<pair<int, int> >::iterator it_1 = maps[it->first].begin(); 
                    it_1 != maps[it->first].end(); ++it_1){
                for(vector<pair<int, int> >::iterator it_2 = maps[temp].begin(); 
                        it_2 != maps[temp].end(); ++it_2){
                    vector<int> res;
                    map<int, int> temp_map;
                    temp_map[it_1->first] += 1;
                    temp_map[it_1->second] += 1;
                    temp_map[it_2->first] += 1;
                    temp_map[it_2->second] += 1;
                    if(temp_map.size() == 4)
                    {
                        bool flag = false;
                        // 查看这个答案是否出现过
                        for(vector<vector<int> >::iterator it_vec = res_vec.begin(); 
                                it_vec != res_vec.end(); ++it_vec){
                            map<int, int>::iterator it_temp = temp_map.begin();
                            if((*it_vec)[0] == num[it_temp->first] && 
                                    (*it_vec)[1] == num[(++it_temp)->first] && 
                                    (*it_vec)[2] == num[(++it_temp)->first] && 
                                    (*it_vec)[3] == num[(++it_temp)->first])
                            {
                                flag = true;
                                break;
                            }
                        }
                        
                        if(!flag)
                        {
                            for(map<int, int>::iterator it_3 = temp_map.begin(); 
                                    it_3 != temp_map.end(); ++it_3){
                                res.push_back(num[it_3->first]);
                            }
                            res_vec.push_back(res);
                        }
                    }
                }
            }
        }
    }
    return res_vec;
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(-2);
    num.push_back(2);
    vector<vector<int> > res_vec = fourSum(num, 0);
    cout << "ok ok ok ok ok ok ok" << endl;
    for(vector<vector<int> >::iterator it = res_vec.begin(); it != res_vec.end(); ++it){
        for (int i = 0; i < 4; i++) {
            cout << (*it)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

