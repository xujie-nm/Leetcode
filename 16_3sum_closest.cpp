#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int threeSumClosest(vector<int> &num, int target){
    int res = 0;
    int final_res;
    int n = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < n - 2; i++) {
        int first = num[i];
        int low = i + 1;
        int high = n - 1;
        while(low < high){
            int temp = first + num[low] + num[high] - target;
            cout << first << " " << num[low] << " " << num[high] << endl;
            cout << temp << endl;
            cout << endl;
            if(temp == 0)
                return target;
            else if(temp > 0){
                if(res == 0){
                    res = temp;
                    final_res = temp + target;
                }
                else if(res > temp){
                    res = temp;
                    final_res = temp + target;
                }
                while(high > 0 && num[high] == num[high -1])
                    high--;
                high--;
            }
            else{
                if(res == 0){
                    res = -temp;
                    final_res = temp + target;
                }
                else if(res > temp*(-1)){
                    res = temp*(-1);
                    final_res = temp + target;
                }
                while(low < n && num[low] == num[low + 1])
                    low++;
                low++;
            }
        }
    }
    return final_res;
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    //num.push_back(-4);
    cout << threeSumClosest(num, 0) << endl;
    return 0;
}
