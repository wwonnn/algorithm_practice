#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R[1001];
    int G[1001];
    int B[1001];
    long long result[1001][3] = {0};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        R[i] = r;
        G[i] = g;
        B[i] = b;
    }

    result[0][0] = R[0];
    result[0][1] = G[0];
    result[0][2] = B[0];

    for (int i = 1; i < n; i++)
    {
        result[i][0] = min(result[i - 1][1], result[i - 1][2]) + R[i];
        result[i][1] = min(result[i - 1][0], result[i - 1][2]) + G[i];
        result[i][2] = min(result[i - 1][0], result[i - 1][1]) + B[i];
    }

    cout << min(result[n - 1][0], min(result[n - 1][1], result[n - 1][2]));
    
}