#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj[200001];
bool vis[100001];

int bfs(int st) {
    queue<int> q;
    int count = 0;
    q.push(st);
    vis[st] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bfs(1);

}