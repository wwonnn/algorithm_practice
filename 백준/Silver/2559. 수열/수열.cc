#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec;
    vector<int> sum;
    vec.push_back(0);

    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        vec.push_back(vec[i - 1] + d);
    }

    for (int i = k; i <= n; i++) {
        sum.push_back(vec[i] - vec[i - k]);
    }

    sort(sum.begin(), sum.end(), func);
    cout << sum.front();

}