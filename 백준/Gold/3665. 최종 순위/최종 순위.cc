#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        queue<int> q;
        vector<int> result;
        vector<int> rank;
        int team[501] = { 0 };
        vector<int> adj[501];
        int deg[501] = { 0 };

        int n, m;
        cin >> n;

        // 작년 그래프 만들기
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            rank.push_back(d);
            team[d] = j;
        }
        
        for (int j = 0; j < rank.size(); j++) {
            for (int k = j + 1; k < rank.size(); k++) {
                adj[rank[j]].push_back(rank[k]);
                deg[rank[k]]++;
            }
        }

        // 올해 바뀐 순위 반영
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            
            if (team[a] > team[b]) {
                adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
                adj[a].push_back(b);
                deg[a]--;
                deg[b]++;
            }
            else {
                adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
                adj[b].push_back(a);
                deg[b]--;
                deg[a]++;
            }

        }

        // 위상정렬
        for (int j = 1; j <= n; j++) {
            if (deg[j] == 0) {
                q.push(j);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int j : adj[curr]) {
                deg[j]--;
                if (deg[j] == 0) {
                    q.push(j);
                }
            }
        }

        if (result.size() != n) {
            cout << "IMPOSSIBLE" << "\n";
        }
        else {
            for (int r : result) {
                cout << r << ' ';
            }
            cout << "\n";
        }
    }
}