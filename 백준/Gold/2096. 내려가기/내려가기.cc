#include <iostream>
#include <algorithm>

using namespace std;

int dp_max[2][3];
int dp_min[2][3];
int score[100000][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> score[i][j];
        }
    }

    dp_max[0][0] = dp_min[0][0] = score[0][0];
    dp_max[0][1] = dp_min[0][1] = score[0][1];
    dp_max[0][2] = dp_min[0][2] = score[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int max_val = -1;
            int min_val = 1e9;

            for (int k = -1; k <= 1; k++) {
                if (j + k < 0 || j + k > 2) continue;

                max_val = max(max_val, dp_max[0][j + k]);
                min_val = min(min_val, dp_min[0][j + k]);
            }
            dp_max[1][j] = max_val + score[i][j];
            dp_min[1][j] = min_val + score[i][j];
        }
        dp_max[0][0] = dp_max[1][0];
        dp_max[0][1] = dp_max[1][1];
        dp_max[0][2] = dp_max[1][2];

        dp_min[0][0] = dp_min[1][0];
        dp_min[0][1] = dp_min[1][1];
        dp_min[0][2] = dp_min[1][2];

    }

    cout << max({ dp_max[0][0], dp_max[0][1], dp_max[0][2] }) << ' ' << min({ dp_min[0][0], dp_min[0][1], dp_min[0][2] });

}