#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[32001];
int deg[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int i : adj[curr]) {
            deg[i]--;
            if (deg[i] == 0) {
                q.push(i);
            }
        }
    }

    for (int i : result) {
        cout << i << ' ';
    }

}