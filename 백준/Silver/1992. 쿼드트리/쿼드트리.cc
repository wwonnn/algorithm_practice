#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int white = 0;
int blue = 0;
int video[5000][5000] = { 0 };
string result;

void solve(int x, int y, int size) {

    int color = video[x][y];
    if (size != 1) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (video[i][j] != color) {
                    result.append("(");

                    // 왼쪽 위
                    solve(x, y, size / 2);
                    // 오른쪽 위
                    solve(x, y + size / 2, size / 2);
                    // 왼쪽 아래
                    solve(x + size / 2, y, size / 2);
                    // 오른쪽 아래
                    solve(x + size / 2, y + size / 2, size / 2);

                    result.append(")");

                    return;
                }
            }
        }
    }

    if (color == 0) {
        result.append("0");
    }
    else {
        result.append("1");
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            video[i][j] = s[j] - '0';
        }
    }

    solve(0, 0, n);
    cout << result;
}