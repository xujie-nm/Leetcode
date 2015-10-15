#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Building{
    Building(int l, int r, int h){ 
        left = l;
        right = r;
        height = h;
    }

    Building(const vector<int> &b){
        left = b[0];
        right = b[1];
        height = b[2];
    }

    bool operator<(const Building &rhs)const{
        return this->height < rhs.height;
    }
    int left;
    int right;
    int height;
};

vector<pair<int, int> > getSkyline(vector<vector<int> >&buildings){
    vector<pair<int, int> >res;
    if(buildings.size() == 0)
        return res;

    priority_queue<Building>queue;
    int x = buildings[0][0];
    int height = 0;
    int buildNum = 0;
    while(true){
        // 处理building的右边
        if(buildNum == buildings.size() || x < buildings[buildNum][0]){
            // 处理building的右边
            while(!queue.empty() && x >= queue.top().right){
                queue.pop();
            }
            if(queue.empty()){
                //当前队列没有building
                //可能没有building，也可能在中间没有building
                height = 0;
                res.push_back(make_pair(x, height));

                //如果没有，退出
                //如果有，计算新的x坐标
                if(buildNum == buildings.size())
                    break;
                else
                    x = buildings[buildNum][0];
            }else{
                //如果队列有building
                if(queue.top().height < height){
                    height = queue.top().height;
                    res.push_back(make_pair(x, height));
                }

                if(buildNum == buildings.size())
                    x = queue.top().right;
                else
                    x = min(queue.top().right, buildings[buildNum][0]);
            }
        }else{
            //处理building的左边
            while(buildNum != buildings.size() && buildings[buildNum][0] == x){
                //x已经到了当前的building
                queue.push(buildings[buildNum++]);
            }

            //如果有了更高的building
            if(queue.top().height > height){
                height = queue.top().height;
                res.push_back(make_pair(x, height));
            }

            if(buildNum == buildings.size())
                x = queue.top().right;
            else
                x = min(queue.top().right, buildings[buildNum][0]);
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> b1{2,9,10};
    vector<int> b2{3,7,15};
    vector<int> b3{5,12,12};
    vector<int> b4{15,20,10};
    vector<int> b5{19,24,8};
    vector<vector<int> > buildings{b1, b2, b3, b4, b5};

    vector<pair<int, int> > res;
    res = getSkyline(buildings);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << "  " << res[i].second << endl;
    }
    return 0;
}
