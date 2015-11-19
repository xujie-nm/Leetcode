#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// TLE
class NumArray{
    public:
        NumArray(vector<int> &nums):nums_(nums){
            int temp = 0;
            for (int i = 0; i < nums_.size(); i++) {
                temp += nums_[i];
                sum_.push_back(temp);
            }
        }

        void update(int i, int val){
            int diff = val - nums_[i];
            for (int j = i; j < sum_.size(); j++) {
                sum_[j] += diff;
            }
        }

        int sumRange(int i, int j){
            return sum_[j] - (i > 0 ? sum_[i-1] : 0);
        }

    private:
        vector<int> nums_;
        vector<int> sum_;
};
// Bucket
class NumArray2{
    public:
        NumArray2(vector<int>& nums){
            // 计算桶的个数以及桶的大小
            int size = nums.size();
            bucketNum = (int)sqrt(2*size);
            bucketSize = bucketNum;
            while(bucketSize*bucketNum < size)
                ++bucketSize;

            // 把元素填入桶
            buckets.resize(bucketNum);
            for (int i = 0, k = 0; i < bucketNum; i++) {
                int tempSum = 0;
                buckets[i].val.resize(bucketSize);
                for (int j = 0; j < bucketSize && k<size; j++, k++) {
                    tempSum += nums[k];
                    buckets[i].val[j] = nums[k];
                }
                buckets[i].sum = tempSum;
            }
        }

        void update(int i, int val){
            int index1 = i / bucketSize;
            int index2 = i % bucketSize;
            buckets[index1].sum += (val - buckets[index1].val[index2]);
            buckets[index1].val[index2] = val;
        }

        int sumRange(int i, int j){
           int index11 = i / bucketSize;
           int index12 = i % bucketSize;
           int index21 = j / bucketSize;
           int index22 = j % bucketSize;
           int sum = 0;
           // 如果在一个桶中
           if(index11 == index21){
               for(int i = index12; i <= index22; i++) 
                   sum += buckets[index11].val[i];
               return sum;
           }

           // 计算第一个同种需要计算的值
           for (int i = index12; i < bucketSize; i++) {
               sum += buckets[index11].val[i];
           }
           // 计算中间桶的值
           for (int i = index11+1; i < index21; i++) {
               sum += buckets[i].sum;
           }
           // 把最后一个桶的值加上
           for (int i = 0; i <= index22; i++) {
               sum += buckets[index21].val[i];
           }
           return sum;
        }
    private:
        struct Bucket{
            int sum;
            vector<int> val;
        };

        int bucketNum;
        int bucketSize;
        vector<Bucket> buckets;
};
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
int main(int argc, const char *argv[])
{
    vector<int> nums{1,3,5};
    NumArray2 numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1,10);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
