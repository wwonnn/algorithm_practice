#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++)
            cout << i + 1 << ' ' << n - i << ' ';
    }
    else {
        for (int i = 0; i < n / 2; i++)
            cout << i + 1 << ' ' << n - i << ' ';
        cout << n / 2 + 1;
    }

}