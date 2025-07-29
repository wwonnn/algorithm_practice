#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
int INF = 1e9 / 3;

int dijkstra(int st, int dst, int N) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <가중치, 정점>
    vector<int> d(N + 1, INF);

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

    return d[dst];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
            
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    int v1, v2;
    cin >> v1 >> v2;

    int result = 0;
    int result2 = 0;

    // 1 -> v1 -> v2 -> N
    result += dijkstra(1, v1, N);
    result += dijkstra(v1, v2, N);
    result += dijkstra(v2, N, N);
    
    // 1 -> v2 -> v1 -> N
    result2 += dijkstra(1, v2, N);
    result2 += dijkstra(v2, v1, N);
    result2 += dijkstra(v1, N, N);

    if (result > result2) {
        if (result2 >= INF) {
            cout << -1;
        }
        else {
            cout << result2;
        }
        
    }
    else {
        if (result >= INF) {
            cout << -1;
        }
        else {
            cout << result;
        }
    }
    
}