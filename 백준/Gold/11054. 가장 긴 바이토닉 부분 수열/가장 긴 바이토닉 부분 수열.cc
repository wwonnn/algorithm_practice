#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp_f(n, 1); // 최소 길이는 1 (자기 자신만 포함)
    vector<int> dp_b(n, 1); // 최소 길이는 1 (자기 자신만 포함)
    vector<int> result(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp_f[i] = max(dp_f[i], dp_f[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int k = n - 1; k > i; k--) {
            if (arr[k] < arr[i]) {
                dp_b[i] = max(dp_b[i], dp_b[k] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        result[i] = dp_f[i] + dp_b[i] - 1;
    }
    // 가장 긴 증가하는 부분 수열의 길이
    cout << *max_element(result.begin(), result.end());
}