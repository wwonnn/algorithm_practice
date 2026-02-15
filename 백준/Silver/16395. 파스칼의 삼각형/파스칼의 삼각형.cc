#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int dp[35][35] = {1};
    for (int i = 1; i < 35; i++) {
        dp[i][1] = 1;
        dp[i][i] = 1;
    }

    for (int i = 3; i < 35; i++) {
        for (int j = 2; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}