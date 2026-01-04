#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long DP[1005][3];
    long long DP_e[1005][2];
    int n;
    cin >> n;
    
    long long mod = 1000000007;
    
    DP[1][0] = 1;
    DP_e[1][0] = 1;
    
    DP[2][0] = DP[2][1] = DP[2][2] = 1;
    DP_e[2][0] = DP_e[2][1] = 1;
    
    for (int i = 3; i <= n + 1; i++) {
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % mod;
        DP[i][1] = (DP[i - 1][0] + DP[i - 2][0] * 2) % mod;
        DP[i][2] = (DP[i - 1][0] + DP[i - 2][0]) % mod;
        
        DP_e[i][0] = (DP_e[i - 1][0] + DP_e[i - 1][1]) % mod;
        DP_e[i][1] = (DP_e[i - 1][0] + DP_e[i - 2][0]) % mod;
    }
    
    long long ans = ((DP[n + 1][0] - DP_e[n + 1][0]) % mod + mod) % mod;
    cout << ans;
}