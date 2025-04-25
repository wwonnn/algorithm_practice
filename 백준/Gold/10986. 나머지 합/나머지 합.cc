 #include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long count = 0;
    long long prefix_sum = 0;
    vector<long long> r(m, 0);
    r[0] = 1; // 초기 누적합이 0일 때를 위해

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        prefix_sum = (prefix_sum + d) % m;

        if (prefix_sum < 0) prefix_sum += m;

        count += r[prefix_sum];
        r[prefix_sum]++;
    }

    cout << count;
}
