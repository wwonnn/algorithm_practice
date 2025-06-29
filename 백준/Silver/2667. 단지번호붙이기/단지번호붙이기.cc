#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int house[25][25];
int vis[25][25];
vector<int> se; // 방문 결과

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    int count = 1;

    q.push(make_pair(i, j));
    vis[i][j] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x, y;

        x = cur.first;
        y = cur.second + 1;
        if (x >= 0 && x < 25 && y >= 0 && y < 25 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                count++;
            }
        }

        x = cur.first;
        y = cur.second - 1;
        if (x >= 0 && x < 25 && y >= 0 && y < 25 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                count++;
            }
        }

        x = cur.first + 1;
        y = cur.second;
        if (x >= 0 && x < 25 && y >= 0 && y < 25 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                count++;
            }
        }

        x = cur.first - 1;
        y = cur.second;
        if (x >= 0 && x < 25 && y >= 0 && y < 25 && house[x][y]) {
            if (!vis[x][y]) {
                q.push(make_pair(x, y));
                vis[x][y] = true;
                count++;
            }
        }

    }
    se.push_back(count);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            house[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (house[i][j] && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
    
    sort(se.begin(), se.end());
    cout << se.size() << "\n";
    for (int i : se) {
        cout << i << "\n";
    }
}