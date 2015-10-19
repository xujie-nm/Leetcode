#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct classcomp{
    bool operator()(const int& lhs, const int& rhs)const{
        return lhs > rhs;
    }
};

class MedianFinder{
    public:
        
        // Adds a number into the data structure
        void addNum(int num){
            if(big.size() == 0){
                if(small.size() == 0){
                    big.insert(num);
                }else{
                    if(num < *(small.begin())){
                        big.insert(*(small.begin()));
                        small.erase(small.begin());
                        small.insert(num);
                    }else
                        big.insert(num);
                }
                return;
            }else if(small.size() == 0){
                if(big.size() == 0){
                    small.insert(num);
                }else{
                    if(num > *(big.begin())){
                        small.insert(*(big.begin()));
                        big.erase(big.begin());
                        big.insert(num);
                    }else
                        small.insert(num);
                }
                return;
            }

            int bigofSmall = *(small.begin());
            int smallofBig = *(big.begin());
            if(num < bigofSmall)
                small.insert(num);
            else if(num > smallofBig)
                big.insert(num);
            else{
                if(big.size() > small.size())
                    small.insert(num);
                else if(big.size() < small.size())
                    big.insert(num);
                else
                    small.insert(num);
            }
            // 调整
            adjust();
        }

        // Return the median of current data stream
        double findMedian(){
            if(big.size() == small.size()){
                int Big = *(big.begin());
                int Small = *(small.begin());
                return double(Big+Small) / 2.0;
            }else if(big.size() > small.size()){
                return *(big.begin());
            }else
                return *(small.begin());
        }

    private:
        // adjust big and small
        void adjust(){
            int n = big.size() - small.size();
            if(n >= -1 && n <= 1)
                return;
            if(n > 1){
                auto it = big.begin();
                while(big.size() - small.size() > 1){
                    small.insert(*it);
                    it = big.erase(it);
                }
            }else{
                auto it = small.begin();
                while(small.size() - big.size() > 1){
                    big.insert(*it);
                    it = small.erase(it);
                }
            }
        }

        multiset<int> big;
        multiset<int, classcomp> small;
};

// TLE
class MedianFinder2{
    public:
        void addNum(int num){
            nums.insert(num);
        }

        double findMedian(){
            if(nums.size()%2 == 1){
                int median = nums.size()/2;
                int i = 0;
                for(multiset<int>::iterator it = nums.begin(); it != nums.end(); ++it){
                    if(i == median)
                        return *it;
                    i++;
                }
            }else{
                int high = nums.size()/2;
                int low = high-1;
                int i = 0;
                int sum = 0;
                for(multiset<int>::iterator it = nums.begin(); it != nums.end(); ++it){
                    if(i == low)
                        sum += *it;
                    else if(i == high)
                        sum += *it;
                    i++;
                }
                return (double) (sum) /2.0;
            }
        }

    private:
        multiset<int> nums;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
int main(int argc, const char *argv[])
{
    MedianFinder2 mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "median: " << mf.findMedian() << endl;
    mf.addNum(3);
    cout << "median: " << mf.findMedian() << endl;
    mf.addNum(5);
    cout << "median: " << mf.findMedian() << endl;
    mf.addNum(7);
    cout << "median: " << mf.findMedian() << endl;
    mf.addNum(9);
    cout << "median: " << mf.findMedian() << endl;
    return 0;
}
