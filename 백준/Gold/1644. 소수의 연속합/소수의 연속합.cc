#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> PrimeList(long long n) {
    // n이하 모든 소수 구하기
    vector<bool> isPrime(n + 1, true);
    vector<int> primeList;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        else isPrime[i] = false;
    }

    for (int i = 0; i < n + 1; i++) {
        if (isPrime[i]) primeList.push_back(i);
    }

    return primeList;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> prime = PrimeList(N);
    if (prime.size() == 0) {
        cout << 0;
        return 0;
    }
    int st = 0;
    int en = 0;
    int sum = prime[st];
    int count = 0;

    while (st <= en) {
        if (sum == N) {
            sum -= prime[st];
            st++;
            count++;
        }
        else if (sum < N) {
            en++;
            if (en >= prime.size()) break;
            sum += prime[en];
        }
        else if (sum > N) {
            sum -= prime[st];
            st++;
        }
    }
    cout << count;
}