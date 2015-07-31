#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs_top(int node, vector<vector<int> > &graph, vector<int> &visited, bool &cycle){
    if(visited[node] == 1){
        cycle = true;
        return;
    }
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        dfs_top(graph[node][i], graph, visited, cycle);
        if(cycle)
            return;
    }
    visited[node] = 2; 
}

bool canFinish(int numCourses, vector<pair<int, int> > &prerequisites){
    vector<vector<int> > graph(numCourses);
    vector<int> visited(numCourses, 0);
    //初始化这个先修课程所对应的图，使用二维数组来表示图
    for (int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
    }

    bool cycle = false;
    //从每一个节点出发判断有没有环
    //数组visited中的节点一共有三个状态
    //visited[i] = 0代表这个节点没有被访问过
    //visited[i] = 1代表这个节点被访问过但是这条通路还没有走完
    //visited[i] = 2代表这个节点不仅仅被访问过，而且这条通路没有环
    for (int i = 0; i < numCourses; i++) {
        if(cycle)
            return false;
        if(visited[i] == 0)
            dfs_top(i, graph, visited, cycle);
    }
    
    return !cycle;    
}

int main(int argc, const char *argv[])
{
    vector<pair<int, int> > prer;
    prer.push_back(make_pair(0, 1));
    cout << canFinish(2, prer) << endl;
    return 0;
}
