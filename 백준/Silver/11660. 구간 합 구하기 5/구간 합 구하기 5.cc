#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> vec;
    
    for (int i = 0; i < n; i++) {
        vector<long long> temp;
        temp.push_back(0);
        for (int j = 1; j <= n; j++) {
            int d;
            cin >> d;
            temp.push_back(temp[j - 1] + d);
        }
        vec.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int j = x1; j <= x2; j++) {
            sum += vec[j - 1][y2] - vec[j - 1][y1 - 1];
        }
        cout << sum << "\n";
    }

}