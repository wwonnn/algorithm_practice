#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> dp;

    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(2);

    for (int i = 5; i < 100; i++)
    {
        dp.push_back(dp[i - 1] + dp[i - 5]);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << dp[n - 1] << "\n";
    }
    
}