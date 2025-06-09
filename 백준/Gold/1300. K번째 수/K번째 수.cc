#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    long long st = 1;
    long long end = k;
    long long mid = k;
    long long result = 0;
    while (end >= st) {
        long long cnt = 0;

        mid = (st + end) / 2;
        for (int i = 1; i <= n; i++) {
            cnt += min(n, (long long)(mid / i));
        }

        if (cnt < k) {
            st = mid + 1;
        }
        else {
            result = mid;
            end = mid - 1;
        }
    }

    cout << result;

}