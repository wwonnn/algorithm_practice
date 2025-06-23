#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[200001];
bool vis[100001];
int se[100001]; // 방문 순서

void bfs(int st) {
    queue<int> q;
    vis[st] = true;
    se[st] = 1;
    int count = 2;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        sort(adj[cur].begin(), adj[cur].end());
        for (auto nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                se[nxt] = count;
                count++;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << se[i] << "\n";
    }

}