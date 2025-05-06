#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> vec_b(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> vec_w(n + 1, vector<long long>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;

            // 첫번째가 검은색인 경우
            if ((i + j) % 2 == 0) {
                if (c == 'B') {
                    vec_b[i][j] = vec_b[i - 1][j] + vec_b[i][j - 1] - vec_b[i - 1][j - 1];
                    
                }
                else {
                    vec_b[i][j] = vec_b[i - 1][j] + vec_b[i][j - 1] - vec_b[i - 1][j - 1] + 1;
                }
            }
            else {
                if (c == 'B') {
                    vec_b[i][j] = vec_b[i - 1][j] + vec_b[i][j - 1] - vec_b[i - 1][j - 1] + 1;
                }
                else {
                    vec_b[i][j] = vec_b[i - 1][j] + vec_b[i][j - 1] - vec_b[i - 1][j - 1];
                }
            }

            // 첫번째가 흰색인 경우
            if ((i + j) % 2 == 0) {
                if (c == 'W') {
                    vec_w[i][j] = vec_w[i - 1][j] + vec_w[i][j - 1] - vec_w[i - 1][j - 1];
                }
                else {
                    vec_w[i][j] = vec_w[i - 1][j] + vec_w[i][j - 1] - vec_w[i - 1][j - 1] + 1;
                }
            }
            else {
                if (c == 'W') {
                    vec_w[i][j] = vec_w[i - 1][j] + vec_w[i][j - 1] - vec_w[i - 1][j - 1] + 1;
                }
                else {
                    vec_w[i][j] = vec_w[i - 1][j] + vec_w[i][j - 1] - vec_w[i - 1][j - 1];
                }
            }
        }
    }

    // 최소 경우 찾기
    long long result = 4e6;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            long long sum_b = vec_b[i][j] - vec_b[i - k][j] - vec_b[i][j - k] + vec_b[i - k][j - k];
            long long sum_w = vec_w[i][j] - vec_w[i - k][j] - vec_w[i][j - k] + vec_w[i - k][j - k];
            result = min(result, min(sum_b, sum_w));
        }
    }
    cout << result;
}