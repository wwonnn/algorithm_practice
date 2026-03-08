#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> sum;

    int d;
    cin >> d;
    sum.push_back(d);

    for (int i = 1; i < N; i++) {
        int d; 
        cin >> d;
        sum.push_back(sum[i - 1] + d);
    }

    long long max = sum[K - 1];
    for (int i = 1; i <= N - K; i++) {
        if (sum[i + K - 1] - sum[i - 1] >= max)
            max = sum[i + K - 1] - sum[i - 1];
    }

    cout << max;

    return 0;
}