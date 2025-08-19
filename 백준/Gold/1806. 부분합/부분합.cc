#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int INF = 1e9 / 3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int st = 0;
    int en = 0;
    int len = INF;
    int sum = a[st];
    while (st <= en) {
        if (sum >= S) {
            if (en - st + 1 < len) len = en - st + 1;
            sum -= a[st];
            st++;
        }
        else if (en < N) {
            en++;
            sum += a[en];
        }
        else break;
    }
    if (len >= INF) cout << 0;
    else cout << len;
}