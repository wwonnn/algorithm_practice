#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p1 = 0;
int p2 = 0;
int p3 = 0;

void solve(int x, int y, int size, const vector<vector<int>>& paper) {

    int color = paper[x][y];
    if (size != 1) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (paper[i][j] != color) {

                    // 왼쪽 위
                    solve(x, y, size / 3, paper);
                    // 중앙 위
                    solve(x, y + size / 3, size / 3, paper);
                    // 오른쪽 위
                    solve(x, y + size / 3 + size / 3, size / 3, paper);

                    // 왼쪽 중앙
                    solve(x + size / 3, y, size / 3, paper);
                    // 중앙 중앙
                    solve(x + size / 3, y + size / 3, size / 3, paper);
                    // 오른쪽 중앙
                    solve(x + size / 3, y + size / 3 + size / 3, size / 3, paper);

                    // 왼쪽 아래
                    solve(x + size / 3 + size / 3, y, size / 3, paper);
                    // 중앙 아래
                    solve(x + size / 3 + size / 3, y + size / 3, size / 3, paper);
                    // 오른쪽 아래
                    solve(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3, paper);

                    return;
                }
            }
        }
    }

    if (color == -1) {
        p1++;
    }
    else if(color == 0){
        p2++;
    }
    else {
        p3++;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<vector<int>> paper(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, n, paper);
    cout << p1 << "\n" << p2 << "\n" << p3;
}