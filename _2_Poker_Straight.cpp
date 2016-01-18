#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 从扑克排中抽五张牌，判断是不是顺子
// A为1，2~10为数字本身。J为11，Q为12，K为13
// 大小鬼可以为任何数字，在这里我们表示成零


bool isPokerStraight(vector<int> cards){
    if(cards.size() != 5)
        return false;

    sort(cards.begin(), cards.end());

    int numberOfZeros = 0;
    int startIndex = 0;

    for (int i = 0; i < cards.size(); i++) {
        if(cards[i] != 0){
            startIndex = i;
            break;
        }
        numberOfZeros++;
    }

    int numberOfGap = 0;
    for (int i = startIndex+1; i < cards.size(); i++) {
        if(cards[i] == cards[i-1])
            return false;
        else if(cards[i] != cards[i-1] + 1){
            numberOfGap += cards[i] - cards[i-1] - 1;
        }
    }

    return (numberOfGap > numberOfZeros) ? false : true;
}

int main(int argc, const char *argv[])
{
    vector<int> nums1{0,3,2,4,0};
    vector<int> nums2{6,3,2,4,0};
    vector<int> nums3{1,3,2,4,5};
    vector<int> nums4{1,3,2,4,2};
    vector<int> nums5{1,3,2,4,11};
    cout << isPokerStraight(nums1) << endl;
    cout << isPokerStraight(nums2) << endl;
    cout << isPokerStraight(nums3) << endl;
    cout << isPokerStraight(nums4) << endl;
    cout << isPokerStraight(nums5) << endl;
    return 0;
}
