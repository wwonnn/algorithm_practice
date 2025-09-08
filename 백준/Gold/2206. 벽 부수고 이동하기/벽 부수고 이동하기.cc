#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001];
int dis[1001][1001][2];  // 거리 / 벽을 부셨는지

int N, M;
int px[4] = { 1, 0, -1, 0 };
int py[4] = { 0, 1, 0, -1 };

struct Node {
    int x, y, broken;
};

int BFS(int x, int y) {
    queue<Node> q;
    q.push({ x, y, 0 });
    dis[1][1][0] = 1;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == N && curr.y == M) {
            // (N, M)에 도착했을 때
            return dis[N][M][curr.broken];
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + px[i];
            int ny = curr.y + py[i];

            if (nx > N || nx < 1 || ny > M || ny < 1) continue;

            if (map[nx][ny] == 1 && curr.broken == 0 && dis[nx][ny][1] == 0) {
                q.push({ nx, ny, 1 });
                dis[nx][ny][1] = dis[curr.x][curr.y][curr.broken] + 1;
            }
            else if (map[nx][ny] == 0 && dis[nx][ny][curr.broken] == 0) {
                q.push({ nx, ny, curr.broken });
                dis[nx][ny][curr.broken] = dis[curr.x][curr.y][curr.broken] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j - 1] - '0';
        }
    }

    cout << BFS(1, 1);

}