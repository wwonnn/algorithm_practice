#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool fun(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        else {
            return a.first.length() > b.first.length();
        }
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> v;
    map<string, int> words;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() < m) {
            continue;
        }
        
        if (words.find(s) == words.end()) {
            // 단어장에 없는 경우
            words.insert(make_pair(s, 1));
        }
        else {
            words[s]++;
        }
    }

    for (auto w : words) {
        v.push_back(w);
    }

    sort(v.begin(), v.end(), fun);

    for (auto w : v) {
        cout << w.first << "\n";
    }

}