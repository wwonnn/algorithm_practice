#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string result;

    for (int i = 0; i < n; i++) {
        result += 'a';
    }

    cout << result;

}