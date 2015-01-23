#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int> > res_vector;
    sort(num.begin(), num.end());
    bool flag = false;
    for (int i = 0; i < num.size(); i++) {
        for(int j = i; j < num.size(); j++)
        {
            vector<int>:: iterator it;
            int temp = 0 - num[i] - num[j];
            flag = false;
            it = find(num.begin() + j + 1, num.end(), temp);
            if(it != num.end())
            {
                vector<int> res;
                res.push_back(num[i]);
                res.push_back(num[j]);
                res.push_back(temp);
                sort(res.begin(), res.end());
                for(vector<vector<int> >::iterator it = res_vector.begin(); it != res_vector.end(); ++it){
                    if((*it)[0] == res[0] && (*it)[1] == res[1] && (*it)[2] == res[2]){
                        flag = true;
                        break;
                    }
                    else
                        flag = false;
                }
                if(!flag)
                {
                    res_vector.push_back(res);
                }
            }
        }
    }
    return res_vector;
}

vector<vector<int> > threeSum2(vector<int> &num)
{
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    int n = num.size();
    for (int i = 0; i < n-2; i++) {
        if(i > 0 && num[i-1] == num[i])
            continue;
        int first = num[i];
        int low = i+1;
        int high = n-1;
        while(low < high)
        {
            int second = num[low];
            int third = num[high];
            if(first+second+third == 0)
            {
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
            }else if(first + second + third > 0){
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

int main(int argc, const char *argv[])
{
    vector<int> array;
    array.push_back(-1);
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);
    array.push_back(-1);
    array.push_back(-4);
    
    vector<vector<int> > res;
    res = threeSum(array);
    for(vector<vector<int> >::iterator it = res.begin(); it != res.end(); ++it){
        for(vector<int>::iterator it_1 = (*it).begin(); it_1 != (*it).end(); ++it_1){
            cout << *it_1 << " ";
        
        }
        cout << endl;
    }
    return 0;
}
