#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec;
    vec.push_back(0);   // vec[0] = 0으로 설정

    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        vec.push_back(vec[i - 1] + d);
    }

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;

        cout << vec[j] - vec[i - 1] << "\n";
    }

}