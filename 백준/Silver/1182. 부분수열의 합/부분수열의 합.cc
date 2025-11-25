#include <iostream>
using namespace std;

int N, S;
int num[21];
int cnt = 0;

void dfs(int idx, int sum) {
    if (idx == N) {
        if (sum == S) cnt++;
        return;
    }

    // 현재 원소 선택
    dfs(idx + 1, sum + num[idx]);

    // 현재 원소 비선택
    dfs(idx + 1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> num[i];

    dfs(0, 0);

    // 공집합 제외
    if (S == 0) cnt--;

    cout << cnt;
}
