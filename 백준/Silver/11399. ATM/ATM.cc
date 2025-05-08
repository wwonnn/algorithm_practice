#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> time;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        time.push_back(t);
    }

    sort(time.begin(), time.end(), func);

    long long sum = time[0];
    for (int i = 1; i < time.size(); i++)
    {
        time[i] += time[i - 1];
        sum += time[i];
    }

    cout << sum;
}