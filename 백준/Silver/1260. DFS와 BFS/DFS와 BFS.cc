#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj[20001];
vector<int> se; // 방문 순서

bool comp(int a, int b) {
    return a > b;
}

void bfs(int st) {
    queue<int> q;
    bool vis[1001] = { 0 };

    q.push(st);
    vis[st] = true;
    se.clear();

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        se.push_back(cur);
        sort(adj[cur].begin(), adj[cur].end());

        for (auto nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

void dfs(int st) {
    stack<int> s;
    bool vis[1001] = { 0 };

    s.push(st);
    se.clear();

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        se.push_back(cur);
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
    for (int i : se) {
        cout << i << ' ';
    }
    cout << "\n";

    bfs(r);
    for (int i : se) {
        cout << i << ' ';
    }
}