#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long line[10001] = { 0 };
    long long len = 0x7fffffff;

    int k, n;
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> line[i];
    }

    long long st = 1;
    long long end = len;
    long long mid = len;
    long long result;
    while (end >= st) {
        long long cnt = 0;

        mid = (st + end) / 2;
        for (int i = 0; i < k; i++) {
            cnt += (line[i] / mid);
        }

        if (cnt < n) {
            end = mid - 1;
        }
        else {
            result = mid;
            st = mid + 1;
        }
    }

    cout << result;

}