#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find_min_index(vector<int> &height, int begin, int end){
    int min = height[begin];
    int min_index = begin;
    for (int i = begin; i <= end; i++) {
        if(height[i] < min){
            min = height[i];
            min_index = i;
        }
    }
    return min_index;
}

int left(vector<int> &height, int min_index, int begin, int end){
    while(begin < min_index && height[min_index - 1] == height[min_index])
        min_index--;
    return min_index;
}

int right(vector<int> &height, int min_index, int begin, int end){
    while(end > min_index && height[min_index + 1] == height[min_index])
        min_index++;
    return min_index;
}

void helper(vector<int> &height, vector<int> &area, int begin, int end){
    if(begin == end){
        area.push_back(height[end]);
        return;
    }else if(begin > end)
        return;
    int min_index = find_min_index(height, begin, end);
    area.push_back(height[min_index] * (end - begin + 1));

    int left_min_index = left(height, min_index, begin, end);
    int right_min_index = right(height, min_index, begin, end);
    
    if(left_min_index == begin){
        helper(height, area, right_min_index + 1, end);
    }else if(right_min_index == end){
        helper(height, area, begin, left_min_index - 1);
    }else{
        helper(height, area, right_min_index + 1, end);
        helper(height, area, begin, left_min_index - 1);
    }
}

int largestRectangleArea(vector<int> &height){
    if(height.size() == 0)
        return 0;
    vector<int> area;
    helper(height, area, 0, height.size() - 1);
    return *(max_element(area.begin(), area.end()));
}

int main(int argc, const char *argv[])
{
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);

    cout << largestRectangleArea(height) << endl;
    return 0;
}
