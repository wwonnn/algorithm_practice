#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> adj[200001];
bool vis[100001];
int se[100001]; // 방문 순서

bool comp(int a, int b) {
    return a > b;
}

void dfs(int st) {
    stack<int> s;
    int count = 1;
    s.push(st);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        se[cur] = count;
        count++;
        sort(adj[cur].begin(), adj[cur].end(), comp);
        for (auto nxt : adj[cur]) {
            if (!vis[nxt]) {
                s.push(nxt);
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
    dfs(r);
    for (int i = 1; i <= n; i++) {
        cout << se[i] << "\n";
    }

}