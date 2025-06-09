#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long h = 0;
    vector<long long> tree;
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        tree.push_back(d);
        if (tree[i] > h) {
            h = tree[i];
        }
    }

    long long st = 1;
    long long end = h;
    long long mid = h;
    long long result = 0;
    while (end >= st) {
        long long cnt = 0;

        mid = (st + end) / 2;
        for (int i = 0; i < n; i++) {
            if (tree[i] - mid > 0) {
                cnt += (tree[i] - mid);
            }
        }

        if (cnt < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            st = mid + 1;
        }
    }

    cout << result;

}