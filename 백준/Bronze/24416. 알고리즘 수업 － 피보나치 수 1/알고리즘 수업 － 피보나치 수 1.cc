#include <iostream>

using namespace std;

int cnt = 1;

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    else {
        cnt++;
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n) {
    int f[40] = { 0 };
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    fib(n);
    cout << cnt << ' ' << n - 2;

}