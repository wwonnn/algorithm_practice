#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> time;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        time.push_back(make_pair(x, y));
    }

    sort(time.begin(), time.end(), func);

    pair<int, int> temp = time[0];
    int count = 1;
    for (int i = 1; i < time.size(); i++)
    {
        if (temp.second <= time[i].first) {
            count++;
            temp = time[i];
        }
    }

    cout << count;
}