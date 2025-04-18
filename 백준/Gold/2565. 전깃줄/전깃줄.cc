#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end(), func);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[i].first > vec[j].first) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());
}