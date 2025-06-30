#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100][100];
int vis[100][100];
int dis[100][100];  // 최단 거리

void bfs(int i, int j) {
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    vis[i][j] = true;
    dis[i][j] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x, y;

        x = cur.first;
        y = cur.second + 1;
        if (x >= 0 && x < 100 && y >= 0 && y < 100 && arr[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                dis[x][y] = dis[cur.first][cur.second] + 1;
            }
        }

        x = cur.first;
        y = cur.second - 1;
        if (x >= 0 && x < 100 && y >= 0 && y < 100 && arr[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                dis[x][y] = dis[cur.first][cur.second] + 1;
            }
        }

        x = cur.first + 1;
        y = cur.second;
        if (x >= 0 && x < 100 && y >= 0 && y < 100 && arr[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                dis[x][y] = dis[cur.first][cur.second] + 1;
            }
        }

        x = cur.first - 1;
        y = cur.second;
        if (x >= 0 && x < 100 && y >= 0 && y < 100 && arr[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                dis[x][y] = dis[cur.first][cur.second] + 1;
            }
        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    bfs(0, 0);
    cout << dis[n - 1][m - 1];

}