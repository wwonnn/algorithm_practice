#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[2001];
int INF = 1e9 / 3;

int dijkstra(int st, int dst) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <가중치, 정점>
    vector<int> d(2001, INF);

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

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int n, m, t;
        int s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        // g, h 사이를 무조건 지나야 함
        // st -> g / h -> dst 다익스트라 2번
        for (int i = 0; i <= n; ++i) adj[i].clear();
        for (int j = 0; j < m; j++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({ d, b });
            adj[b].push_back({ d, a });
        }

        vector<int> dst_value;
        vector<int> result;
        for (int k = 0; k < t; k++) {
            int t_value;
            cin >> t_value;
            dst_value.push_back(t_value);
        }

        int dis = dijkstra(g, h);
        for (int dst : dst_value) {
            if (dijkstra(s, g) + dis + dijkstra(h, dst) == dijkstra(s, dst)) {
                result.push_back(dst);
            }
            else if (dijkstra(s, h) + dis + dijkstra(g, dst) == dijkstra(s, dst)) {
                result.push_back(dst);
            }
        }
        sort(result.begin(), result.end());
        for (int r : result) {
            cout << r << ' ';
        }
        cout << "\n";
    }
}