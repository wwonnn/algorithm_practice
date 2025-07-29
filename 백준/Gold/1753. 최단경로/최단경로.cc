#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
int d[20005];
int INF = 1e9 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <가중치, 정점>
    vector<int> result;

    int V, E, st;
    cin >> V >> E >> st;

    fill(d, d + V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
            
        adj[u].push_back({ w, v });
    }

    d[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        if (d[curr.second] < curr.first) continue;

        for (auto a : adj[curr.second]) {
            if (d[a.second] > d[curr.second] + a.first) {
                d[a.second] = d[curr.second] + a.first;
                pq.push({ d[a.second], a.second });
            }
            else {
                continue;
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (i != st && d[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << d[i] << "\n";
        }
    }
 
}