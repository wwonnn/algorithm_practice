#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<vector<int>> vec(str.length(), vector<int>(150, 0));

    vec[0][(int)str[0]] = 1;
    for (int i = 1; i < str.length(); i++) {
        for (int j = 0; j < 150; j++) {
            if (j == (int)str[i]) {
                vec[i][j] = vec[i - 1][j] + 1;
            }
            else {
                vec[i][j] = vec[i - 1][j];
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (a == 0) {
            cout << vec[b][int(c)] << "\n";
        }
        else {
            cout << vec[b][int(c)] - vec[a - 1][(int)c] << "\n";
        }
    }

}