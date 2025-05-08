#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coin;
    
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        coin.push_back(d);
    }

    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k < 0) {
            break;
        }

        count += k / coin[i];
        k = k % coin[i];
    }

    cout << count;
}