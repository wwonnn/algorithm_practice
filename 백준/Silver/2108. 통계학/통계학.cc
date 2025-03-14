#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

bool fun(int a, int b) {
    return a < b;
}

bool fun2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

// 평균
int mean(vector<int> v) {
    long long sum = 0;
    for (auto d : v) {
        sum += d;
    }

    if (sum < 0) {
        if (abs(sum) / v.size() == 0) {
            return 0;
        }
        else {
            return floor(double(abs(sum)) / v.size() + 0.5f) * -1;
        }
    }
    else {
        return floor(double(abs(sum)) / v.size() + 0.5f);
    }
    
}

// 중앙값
int median(vector<int> v) {
    return v[v.size() / 2];
}

// 최빈값
int modeWhich(vector<int> v) {
    map<int, int> m;
    vector<pair<int, int>> result;

    for (auto d : v) {
        if (m.find(d) != m.end()) {
            m[d]++;
        }
        else {
            m.insert(make_pair(d, 1));
        }
     }
    
    for (pair<int, int> m2 : m) {
        result.push_back(make_pair(m2.first, m2.second));
    }
    sort(result.begin(), result.end(), fun2);

    if (result.size() > 1 && result[0].second == result[1].second) {
        return result[1].first;
    }
    else {
        return result[0].first;
    }
}

// 범위
int range(vector<int> v) {
    return v.back() - v.front();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v.push_back(d);
    }

    sort(v.begin(), v.end(), fun);

    cout << mean(v) << "\n";
    cout << median(v) << "\n";
    cout << modeWhich(v) << "\n";
    cout << range(v) << "\n";

}