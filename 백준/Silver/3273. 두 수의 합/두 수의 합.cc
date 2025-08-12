#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);

    int result = 0;
    int st = 0;
    int en = n - 1;
    while (en > st) {
        int sum = a[st] + a[en];

        if (sum == x) {
            result++;
            st++;
            en--;
        }
        else if (sum < x) {
            st++;
        }
        else {
            en--;
        }
    }
    
    cout << result;
}