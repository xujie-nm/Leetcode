#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 以low作为哨兵，把数组vec分为左边小于vec[low]，右边大于vec[low]
// 递归
void qsort(vector<int>& vec, int start, int end){
    if(start < end){
        int key = vec[start];
        int low = start;
        int high = end;

        while(low < high){
            while(low < high && vec[high] > key)
                high--;
            vec[low] = vec[high];
            while(low < high && vec[low] <= key)
                low++;
            vec[high] = vec[low];
        }
        vec[low] = key;

        qsort(vec, start, low-1);
        qsort(vec, low+1, end);
    }
}

//非递归
//使用栈来模拟递归调用
int partation(vector<int>& vec, int low, int high){
    if(low >= high)
        return low;
    int key = vec[low];
    while(low < high){
        while(low < high && vec[high] > key)
            high--;
        vec[low] = vec[high];
        while(low < high && vec[low] <= key)
            low++;
        vec[high] = vec[low];
    }
    vec[low] = key;
    return low;
}

void qsort2(vector<int>& vec, int start, int end){
   if(start >= end)
       return;
   stack<pair<int, int> > indexs;
   indexs.push(make_pair(start, end));
   while(!indexs.empty()){
       pair<int, int> p1 = indexs.top();
       indexs.pop();
       int index = partation(vec, p1.first, p1.second);
       if(index != p1.second && index != p1.first)
           indexs.push(make_pair(index+1, end));
       if(index != p1.first && index != p1.second)
           indexs.push(make_pair(start, index-1));
   }
}
int main(int argc, const char *argv[])
{
    vector<int> vec;
    int temp;
    while(cin >> temp){
        vec.push_back(temp);
    }
    qsort2(vec, 0, vec.size()-1);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
