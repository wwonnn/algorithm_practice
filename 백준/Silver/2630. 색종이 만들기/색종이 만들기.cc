#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int white = 0;
int blue = 0;
int paper[128][128] = { 0 };

void solve(int x, int y, int size) {

    int color = paper[x][y];
    if (size != 1) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (paper[i][j] != color) {
                    // 왼쪽 위
                    solve(x, y, size / 2);
                    // 오른쪽 위
                    solve(x + size / 2, y, size / 2);
                    // 왼쪽 아래
                    solve(x, y + size / 2, size / 2);
                    // 오른쪽 아래
                    solve(x + size / 2, y + size / 2, size / 2);

                    return;
                }
            }
        }
    }

    if (color == 0) {
        white++;
    }
    else {
        blue++;
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 색종이 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, n);
    cout << white << "\n" << blue;
}