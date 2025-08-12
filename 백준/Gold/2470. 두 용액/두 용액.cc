#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int st = 0;
    int en = n - 1;
    int min_diff = 2e9; // 충분히 큰 수
    int ans1 = a[st], ans2 = a[en];

    while (st < en) {
        int sum = a[st] + a[en];
        int diff = abs(sum);

        if (diff < min_diff) {
            min_diff = diff;
            ans1 = a[st];
            ans2 = a[en];
        }
        if (sum == 0) {
            // 완벽한 답 찾음
            break;
        }
        else if (sum < 0) {
            st++;
        }
        else {
            en--;
        }
    }

    cout << ans1 << ' ' << ans2;
}