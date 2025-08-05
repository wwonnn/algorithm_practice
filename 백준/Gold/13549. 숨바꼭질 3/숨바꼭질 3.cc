#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100001];
int INF = 1e9 / 3;

int dijkstra(int st, int dst) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <가중치, 정점>
    vector<int> d(100001, INF);

    d[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        if (d[curr.second] < curr.first) continue;

        for (auto a : adj[curr.second]) {
            if (d[curr.second] + a.first < d[a.second]) {
                d[a.second] = d[curr.second] + a.first;
                pq.push({d[a.second], a.second});
                
            }
        }
    }

    return d[dst];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= 100000; i++) {
        if (i - 1 >= 0)
            adj[i].push_back({ 1, i - 1 });
        if (i + 1 <= 100000)
            adj[i].push_back({ 1, i + 1 });
        if (i * 2 <= 100000)
            adj[i].push_back({ 0, i * 2 });
    }

    cout << dijkstra(N, K);
    
}