#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<long long> house;
    vector<long long> dis;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        house.push_back(x);
    }
    sort(house.begin(), house.end());
    for (int i = 1; i < n; i++) {
        dis.push_back(house[i] - house[i - 1]);
    }
    long long d = house.back();
    long long st = 1;
    long long end = d;
    long long mid = d;
    long long result = 0;
    while (end >= st) {
        long long cnt = 1;

        mid = (st + end) / 2;
        long long temp = 0;
        for (int i = 0; i < dis.size(); i++) {
            temp += dis[i];
            if (temp >= mid) {
                temp = 0;
                cnt++;
            }
        }

        if (cnt < c) {
            end = mid - 1;
        }
        else {
            result = mid;
            st = mid + 1;
        }
    }

    cout << result;

}