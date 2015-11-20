#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> >&triangle){
    if(triangle.size() == 0)
        return 0;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int first = j == 0 ? 0 : j-1;
            int second = j == triangle[i].size()-1 ? j-1 : j;
            
            // 重新计算triangle
            // 计算方式是当前值加上上一层相邻的最小值
            triangle[i][j] = triangle[i][j] + min(triangle[i-1][first], triangle[i-1][second]);
        }
    }

    int min = triangle[triangle.size() - 1][0];
     for (int j = 0; j < triangle[triangle.size()-1].size(); j++) {
         if(triangle[triangle.size()-1][j] < min)
             // 找到最后一层的最小值
             min = triangle[triangle.size()-1][j];
     }
     
    return min;
}

int main(int argc, const char *argv[])
{
    vector<int> v1;
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    vector<int> v3;
    v3.push_back(6);
    v3.push_back(5);
    v3.push_back(7);
    vector<int> v4;
    v4.push_back(4);
    v4.push_back(1);
    v4.push_back(8);
    v4.push_back(3);
    vector<vector<int> >vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    
    cout << minimumTotal(vv) << endl;
    return 0;
}
