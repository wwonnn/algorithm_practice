#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[1005] = { 0 };
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i < 1005; i++) {
        dp[i] = (dp[i - 1] + 1) % 2;
    }

    if (dp[N] == 0) {
        cout << "CY";
    }
    else cout << "SK";

    return 0;
}