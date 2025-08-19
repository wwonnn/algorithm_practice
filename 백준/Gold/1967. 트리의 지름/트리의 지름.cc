#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> adj[10005];
bool visited[10005];
int farNode;
int maxDist;

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

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back({ c, w });
        adj[c].push_back({ p, w });
    }
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(1, 0);
    
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farNode, 0);

    cout << maxDist;
}