#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool dfs_top(int node, vector<vector<int> > &graph, vector<int> &visited, vector<int> &res){
   
    if(visited[node] == 1)
        return false;
    if(visited[node] == 2)
        return true;

    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
            if(!dfs_top(graph[node][i], graph, visited, res))
                return false;
    }
    res.push_back(node);
    visited[node] = 2;
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int> > &pres){
    vector<vector<int> > graph(numCourses);
    vector<int> visited(numCourses, 0);
    vector<int> res;

    for (int i = 0; i < pres.size(); i++) {
        graph[pres[i].second].push_back(pres[i].first);
    }

    for (int i = 0; i < numCourses; i++) {
        if(!dfs_top(i, graph, visited, res))
            return vector<int>();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char *argv[])
{
    vector<pair<int, int> > pres;
    pres.push_back(make_pair(1, 0));
    pres.push_back(make_pair(2, 0));
    pres.push_back(make_pair(3, 1));
    pres.push_back(make_pair(3, 2));

    vector<int> res;
    res = findOrder(4, pres);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
