#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> dq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        dq.push_back(make_pair(i+1, d));
    }

    while (dq.size() > 1) {
        int num = dq.front().second;
        cout << dq.front().first << ' ';
        dq.pop_front();

        if (num > 0) {
            for (int j = 0; j < abs(num) - 1; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int j = 0; j < abs(num); j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

        }
    }
    cout << dq.front().first;
    
}