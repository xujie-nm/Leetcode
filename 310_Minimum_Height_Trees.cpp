#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

// BFS TLE recursive
// 这个方法的思想是从一个叶子点出发，找到深度为一半且不是叶子的节点
void helper(vector<int>&heights, int curNode, int curLevel, vector<pair<int, int> > &edges){
    if(edges.empty())
        return;
    unordered_map<int, pair<int, int> > neightbors;
    for (int i = 0; i < edges.size(); i++) {
        if(edges[i].first == curNode){
            heights[edges[i].second] = curLevel+1;
            neightbors[edges[i].second] = edges[i];
        }else if(edges[i].second == curNode){
            heights[edges[i].first] = curLevel+1;
            neightbors[edges[i].first] = edges[i];
        }
    }
    if(neightbors.size() == 0)
        return;
    for(auto it = neightbors.begin(); it != neightbors.end(); ++it){
        auto found = find(edges.begin(), edges.end(), it->second);
        if(found != edges.end())
            edges.erase(found);
    }

    for(auto it = neightbors.begin(); it != neightbors.end(); ++it)
        helper(heights, it->first, curLevel+1, edges);
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int> >&edges){
    vector<int> res;
    if(n <= 1){
        res.push_back(0);
        return res;
    }
    vector<pair<int, int> > tempEdges = edges;
    
    vector<int> heights(n, -1);
    heights[0] = 1;
    helper(heights, 0, 1, tempEdges);
    int max = *(max_element(heights.begin(), heights.end()));       

    vector<int> nodes(n, 0);
    for (int i = 0; i < edges.size(); i++) {
        nodes[edges[i].first]++;    
        nodes[edges[i].second]++;    
    }

    for (int i = 0; i < heights.size(); i++) {
        if(max%2 == 1){
            if(heights[i] == max/2+1 && nodes[i] != 1)
                res.push_back(i);
        }else if(max%2 == 0)
            if((heights[i] == max/2 || heights[i] == max/2+1)
             && nodes[i] != 1)
                res.push_back(i);
    }
    return res;
}

//no recursive
//这个方法的思想是从边上度为1的点开始逐个消去，最后剩下中心的点
vector<int> findMinHeightTrees2(int n, vector<pair<int, int> >&edges){
    vector<int> res;
    if(n <= 1){
        res.push_back(0);
        return res;
    }

    vector<int> nodes(n); // 这个表示无向图中每个点的度
    vector<vector<int> > graph(n, vector<int>());
    for(pair<int, int> pair : edges){
        nodes[pair.first]++;
        nodes[pair.second]++;
        graph[pair.first].push_back(pair.second);
        graph[pair.second].push_back(pair.first);
    }

    queue<int> queue;
    for (int i = 0; i < n; i++) {
        if(nodes[i] == 1)
            queue.push(i);
    }
    int count = n;
    while(count > 2){
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            int side = queue.front();
            queue.pop();
            count--;
            for(int inside : graph[side]){
                nodes[inside]--;
                if(nodes[inside] == 1)
                    queue.push(inside);
            }
        }
    }
    res.push_back(queue.front());
    queue.pop();
    if(!queue.empty())
        res.push_back(queue.front());
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(4, 5));
    res = findMinHeightTrees2(6, edges);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
