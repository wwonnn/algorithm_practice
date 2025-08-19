#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> adj[100005];
int parent[100005];
bool visited[100005];
int farNode;  
int maxDist;

//void MakeTree(int node) {
//    for (auto n : adj[node]) {
//        if (n.first == parent[node]) continue;
//        parent[n.first] = node;
//        MakeTree(n.first);
//    }
//}

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farNode = node;
    }

    for (auto n : adj[node]) {
        if (!visited[n.first]) {
            dfs(n.first, dist + n.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V;
    cin >> V;
    for (int i = 0; i < V; i++) {
        int n;
        cin >> n;
        while (true) {
            int u, w;
            cin >> u;
            if (u == -1) break;

            cin >> w;
            adj[n].push_back({ u, w });
            adj[u].push_back({ n, w });
        }

    }
    //MakeTree(1);

    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farNode, 0);

    cout << maxDist;
}