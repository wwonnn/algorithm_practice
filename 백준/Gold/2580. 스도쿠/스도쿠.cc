#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> prob(9, vector<int>(9));
vector<pair<int, int>> blank;

void func(int k) {
    if (k == blank.size()) {
        // 스도쿠를 다 채웠을 때
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << prob[i][j] << ' ';
            }
            cout << "\n";
        }
        exit(0);
    }

    int x = blank[k].first;
    int y = blank[k].second;
    for (int i = 1; i <= 9; i++) {
        // i가 blank에 들어갈 수 있는지
        bool num = true;
        // 가로, 세로
        for (int j = 0; j < 9; j++) {
            if (prob[x][j] == i || prob[j][y] == i) {
                num = false;
            }
        }
        if (!num) {
            continue;
        }

        // 3x3
        for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
            for (int t = y / 3 * 3; t < y / 3 * 3 + 3; t++) {
                if (prob[j][t] == i) {
                    num = false;
                }
            }
        }
        if (!num) {
            continue;
        }

        if (num) {
            prob[x][y] = i;
            func(k + 1);
            prob[x][y] = 0;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n;
            prob[i][j] = n;

            if (n == 0) {
                blank.push_back(make_pair(i, j));
            }
        }
    }
    
    func(0);
}