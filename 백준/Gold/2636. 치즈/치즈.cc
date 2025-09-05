#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int px[4] = { -1, 0, 1, 0 };
int py[4] = { 0, 1, 0, -1 };

int info[100][100];
bool isSearch[100][100] = { false };
int N, M;

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    
    while (!q.empty()) {
        pair<int, int> curr;
        curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + px[i];
            int ny = curr.second + py[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (info[nx][ny] == 1) {
                info[nx][ny] = -1;
            }
            else if (info[nx][ny] == 0 && !isSearch[nx][ny]) {
                q.push({ nx, ny });
                isSearch[nx][ny] = true;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // BFS
    // 0인 부분을 탐색. 0인 부분이 판의 가장자리와 접촉되어 있으면 공기로 판단

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> info[i][j];
        }
    }

    int hour = 0;
    int count = 0;
    int lastCount = 0;
    bool isFinish = true;
    while (true) {
        // 공기와 접촉된 치즈 탐색
        for (int i = 0; i < N; i++) {
            if (info[i][0] == 0 && !isSearch[i][0]) {
                BFS(i, 0);
            }

            if (info[i][M - 1] == 0 && !isSearch[i][M - 1]){
                BFS(i, M - 1);
            }
        }
        for (int i = 0; i < M - 1; i++) {
            if (info[0][i + 1] == 0 && !isSearch[0][i + 1]) {
                BFS(0, i + 1);
            }

            if (info[N - 1][i + 1] == 0 && !isSearch[N - 1][i + 1]) {
                BFS(N - 1, i + 1);
            }
        }

        // 치즈 녹기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (info[i][j] == -1) {
                    isFinish = false;
                    count++;
                    info[i][j] = 0;
                }
            }
        }
        
        // 치즈가 다 녹았는지
        if (!isFinish) {
            hour++;
            isFinish = true;
            lastCount = count;
            count = 0;
            memset(isSearch, 0, sizeof(isSearch));
        }
        else {
            // 치즈가 다 없어지면
            break;
        }
        
    }

    cout << hour << "\n" << lastCount;

}