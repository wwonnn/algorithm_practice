#include <iostream>

using namespace std;

long long Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    cout << Fibonacci(n);

}