#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());

    cin >> m;

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        cout << binary_search(v.begin(), v.end(), s) << "\n";
    }

}