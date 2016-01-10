#include <iostream>
#include <string>
#include <vector>
using namespace std;

int recursive_count(vector<long long>& sums, int i, int j, vector<long long>& tmp, int lower, int upper){
    if(i == j)
        return sums[i] >= lower && sums[i] <= upper;
    if(i > j)
        return 0;

    int mid = (i + j) / 2;
    int leftRanges = recursive_count(sums, i, mid, tmp, lower, upper);
    int rightRanges = recursive_count(sums, mid+1, j, tmp, lower, upper);

    // 当前的这个时候temp里的left和right分别是排好序的sum
    // 所以以此来计算可能的range
    // 
    // 因为此时左边和右边分别有序这种方法才有效，否则无效
    //     因为左边是有序的，所以sums[*Ranges]只可能变大
    //     因为右边是有序的，所以sums[k]-sums[*Ranges]在进入下一次循环时
    //     *Ranges不会变的反而小，只会变大
    //
    // 数轴------------------------------------------------------------>
    //           |                              |
    //         lower                           upper
    //           .                              。
    //           |                              |------------------------
    //           |                                      notRanges
    //           --------------------------------------------------------
    //                              mayRanges
    // 所以mayRanges-notRanges正好是在区间lower~upper内
    int notRanges = i, mayRanges = i, k = mid + 1;
    int curRanges = 0;
    for (int k = mid+1; k <= j; k++) {
        while(notRanges <= mid){
            long long sum = sums[k] - sums[notRanges];
            if(sum <= upper)
                break;
            else
                ++notRanges;
        }

        while(mayRanges <= mid){
            long long sum = sums[k] - sums[mayRanges];
            if(sum < lower)
                break;
            else
                ++mayRanges;
        }

        curRanges += mayRanges-notRanges; // 这个的结果一定是>=0的
    }

    // 此时数组的i ~ mid 和 mid+1 ~ j分别是有序的
    // 所以借助数组tmp来将数组sums的i~j合并有序的数列
    int left = i; 
    int right = mid+1;
    int cur = i;
    while(left <= mid && right <= j){
        if(sums[left] < sums[right])
            tmp[cur++] = sums[left++];
        else
            tmp[cur++] = sums[right++];
    }
    while(left <= mid)
        tmp[cur++] = sums[left++];
    while(right <= j)
        tmp[cur++] = sums[right++];
    // 用有序的tmp替换分别有序的sums
    for (int temp = i; temp <= j; temp++) {
        sums[temp] = tmp[temp];
    }

    return leftRanges + rightRanges + curRanges;
}

int countRangeSum(vector<int>& nums, int lower, int upper){
   if(nums.size() == 0) 
       return 0;

   int res = 0;

   // 建立累计求和数组
   vector<long long> sums(nums.size(), 0);
   sums[0] = nums[0];
   for (int i = 1; i < nums.size(); i++) {
       sums[i] = sums[i-1] + nums[i];
   }

   // 分治法
   vector<long long> tmp(nums.size());
   res = recursive_count(sums, 0, nums.size()-1, tmp, lower, upper);

   return res;
}

int main(int argc, const char *argv[])
{
    vector<int> nums{-2, 5, -1};
    cout << countRangeSum(nums, -2, 2) << endl;
    return 0;
}
