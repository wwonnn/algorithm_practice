#include <iostream>
using namespace std;

int N, B;

void printDigit(int x) {
    if (x >= 10) cout << (char)('A' + x - 10);
    else cout << x;
}

void func(int n) {
    if (n < B) {     // 베이스 케이스
        printDigit(n);
        return;
    }
    func(n / B);     // 앞 자리들
    printDigit(n % B); // 마지막 자리
}

int main() {
    cin >> N >> B;
    func(N);
}
