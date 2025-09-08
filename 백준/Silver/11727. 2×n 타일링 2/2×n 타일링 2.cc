#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dp[1005] = { 0 };
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 % 10007)%10007;
    }

    cout << dp[N];
}