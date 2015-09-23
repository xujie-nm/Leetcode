#include <iostream>
#include <string>
#include <vector>
using namespace std;

//no recursion
bool binarySearch(vector<int> nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid;
    while(low < high){
        mid = (low + high)/2;
        if(target == nums[mid])
            return true;
        else if(target > nums[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    if(nums[low] == target)
        return true;
    else
        return false;
}

bool searchMatrix(vector<vector<int> > &matrix, int target){
    int n = matrix[0].size();
    int m = matrix.size();
    for (int i = 0; i < m; i++) {
        if(matrix[i][0] <= target && matrix[i][n-1] >= target){
            if(binarySearch(matrix[i], target))
                return true;
        }else
            continue;
    }
    return false;
}

//recursion
bool helper(vector<vector<int> > &matrix, int x, int y, int target){
    int m = matrix.size();
    if(x > m-1 || y < 0)
        return false;
    if(matrix[x][y] == target)
        return true;
    else if(matrix[x][y] < target)
        return helper(matrix, x+1, y, target);
    else
        return helper(matrix, x, y-1, target);
}

bool searchMatrix2(vector<vector<int> > &matrix, int target){
    int n = matrix[0].size();
    if(n == 0)
        return false;
    return helper(matrix, 0, n-1, target);
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(4);
    line1.push_back(7);
    line1.push_back(11);
    line1.push_back(15);
    vector<int> line2;
    line2.push_back(2);
    line2.push_back(5);
    line2.push_back(8);
    line2.push_back(12);
    line2.push_back(19);
    vector<int> line3;
    line3.push_back(3);
    line3.push_back(6);
    line3.push_back(9);
    line3.push_back(16);
    line3.push_back(22);
    vector<int> line4;
    line4.push_back(10);
    line4.push_back(13);
    line4.push_back(14);
    line4.push_back(17);
    line4.push_back(24);
    vector<int> line5;
    line5.push_back(18);
    line5.push_back(21);
    line5.push_back(23);
    line5.push_back(26);
    line5.push_back(30);
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    matrix.push_back(line5);

    cout << searchMatrix2(matrix, 9) << endl;
    return 0;
}
