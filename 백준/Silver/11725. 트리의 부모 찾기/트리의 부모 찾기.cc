#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100005];
int p[100005];

void dfs(int curr) {
    for (int nxt : adj[curr]) {
        if (nxt == p[curr]) continue;
        p[nxt] = curr;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    for (int i = 2; i <= N; i++)
        cout << p[i] << "\n";
}