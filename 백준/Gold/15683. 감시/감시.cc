#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 위 오 아래 왼
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int min_count = 101;
int info[10][10];
int looking[10][10];

void CCTV(int x, int y, int dir) {
    while (true) {
        x += dx[dir];
        y += dy[dir];

        if (x >= N || x < 0 || y >= M || y < 0 || info[x][y] == 6) break;
        if (info[x][y] == 0) {
            //info[x][y] = -1;
            looking[x][y]++;
        }
    }
   
}

void Reset(int x, int y, int dir) {
    while (true) {
        x += dx[dir];
        y += dy[dir];

        if (x >= N || x < 0 || y >= M || y < 0 || info[x][y] == 6) break;
        if (info[x][y] == 0) {
            looking[x][y]--;
            //if (looking[x][y] <= 0) {
            //    info[x][y] = 0;
            //}
        }

    }
}

void Calculate(int pos) {
    if (pos == N * M) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (info[i][j] == 0 && looking[i][j] == 0) {
                    count++;
                }
            }
        }
        min_count = min(min_count, count);
        return;
    }

    int i = pos / M;
    int j = pos % M;

    switch (info[i][j])
    {
    case 1:
        for (int t = 0; t < 4; t++) {
            CCTV(i, j, t);
            Calculate(pos + 1);
            Reset(i, j, t);
        }
        break;
    case 2:
        CCTV(i, j, 0);
        CCTV(i, j, 2);
        Calculate(pos + 1);
        Reset(i, j, 0);
        Reset(i, j, 2);

        CCTV(i, j, 1);
        CCTV(i, j, 3);
        Calculate(pos + 1);
        Reset(i, j, 1);
        Reset(i, j, 3);
        break;
    case 3:
        CCTV(i, j, 0);
        CCTV(i, j, 1);
        Calculate(pos + 1);
        Reset(i, j, 0);
        Reset(i, j, 1);

        CCTV(i, j, 1);
        CCTV(i, j, 2);
        Calculate(pos + 1);
        Reset(i, j, 1);
        Reset(i, j, 2);

        CCTV(i, j, 2);
        CCTV(i, j, 3);
        Calculate(pos + 1);
        Reset(i, j, 2);
        Reset(i, j, 3);

        CCTV(i, j, 3);
        CCTV(i, j, 0);
        Calculate(pos + 1);
        Reset(i, j, 3);
        Reset(i, j, 0);
        break;
    case 4:
        CCTV(i, j, 0);
        CCTV(i, j, 1);
        CCTV(i, j, 2);
        Calculate(pos + 1);
        Reset(i, j, 0);
        Reset(i, j, 1);
        Reset(i, j, 2);

        CCTV(i, j, 1);
        CCTV(i, j, 2);
        CCTV(i, j, 3);
        Calculate(pos + 1);
        Reset(i, j, 1);
        Reset(i, j, 2);
        Reset(i, j, 3);

        CCTV(i, j, 2);
        CCTV(i, j, 3);
        CCTV(i, j, 0);
        Calculate(pos + 1);
        Reset(i, j, 2);
        Reset(i, j, 3);
        Reset(i, j, 0);

        CCTV(i, j, 3);
        CCTV(i, j, 0);
        CCTV(i, j, 1);
        Calculate(pos + 1);
        Reset(i, j, 3);
        Reset(i, j, 0);
        Reset(i, j, 1);
        break;
    case 5:
        CCTV(i, j, 0);
        CCTV(i, j, 1);
        CCTV(i, j, 2);
        CCTV(i, j, 3);
        Calculate(pos + 1);
        break;
    default:
        // 0 또는 6
        Calculate(pos + 1);
        break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 백트래킹
    // CCTV를 모든 경우에 비춰보고 가장 사각지대가 없는 것을 선택

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> info[i][j];
        }
    }

    Calculate(0);

    cout << min_count;

}