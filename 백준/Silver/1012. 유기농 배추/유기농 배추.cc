#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int house[50][50];
int vis[50][50];

void bfs(int i, int j) {
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    vis[i][j] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x, y;

        x = cur.first;
        y = cur.second + 1;
        if (x >= 0 && x < 50 && y >= 0 && y < 50 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }

        x = cur.first;
        y = cur.second - 1;
        if (x >= 0 && x < 50 && y >= 0 && y < 50 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }

        x = cur.first + 1;
        y = cur.second;
        if (x >= 0 && x < 50 && y >= 0 && y < 50 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }

        x = cur.first - 1;
        y = cur.second;
        if (x >= 0 && x < 50 && y >= 0 && y < 50 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, k;
    cin >> t;
    
    for (int j = 0; j < t; j++) {
        memset(house, 0, sizeof(house));
        memset(vis, 0, sizeof(vis));
        
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            house[y][x] = 1;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (house[i][j] && !vis[i][j]) {
                    bfs(i, j);
                    count++;
                }
            }
        }
    
        cout << count << "\n";
    }

}