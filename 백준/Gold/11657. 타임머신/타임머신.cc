#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1e9 / 3;

struct Edge {
    int u, v;
    long long w;
};

vector<long long> bellmanFord(int V, int st, vector<Edge>& edges) {

    vector<long long> d(V + 1, INF);

    d[st] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto& e : edges) {
            if (d[e.u] != INF && d[e.u] + e.w < d[e.v]) {
                d[e.v] = d[e.u] + e.w;
            }
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<Edge> edges;

    int N, M;
    cin >> N >> M;

    for (int j = 0; j < M; j++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        edges.push_back({ a, b, c });
    }

    vector<long long> result = bellmanFord(N, 1, edges);

    // 사이클 확인
    bool isCycle = false;
    for (auto& e : edges) {
        if (result[e.u] != INF && result[e.u] + e.w < result[e.v]) {
            cout << -1;
            isCycle = true;
            break;
        }
    }

    if (!isCycle) {
        for (int i = 2; i <= N; i++) {
            if (result[i] == INF) cout << -1 << "\n";
            else cout << result[i] << "\n";
        }
    }

}