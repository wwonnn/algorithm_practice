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

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
            
        adj[a].push_back(b);
        deg[b]++;
    }

    // 위상정렬
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        
        result.push_back(curr);

        for (int i : adj[curr]) {
            deg[i]--;
            if (deg[i] == 0) {
                pq.push(i);
            }
        }
    }

    for (int r : result) {
        cout << r << ' ';
    }

}