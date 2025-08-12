#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1e9 / 3;
int d[401][401];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, INF);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int i = 1; i <= n; i++) d[i][i] = 0;

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // k를 거쳐 가는게 더 빠른지

    long long min = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] + d[j][i] < min && i != j) min = d[i][j] + d[j][i];
        }
    }

    if (min == INF) cout << -1;
    else cout << min;
}