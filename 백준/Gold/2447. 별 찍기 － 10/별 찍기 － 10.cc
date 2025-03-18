#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void draw_stars(vector<string>& stars, int d, int r, int c) {
    // d: 길이 r: 행 c: 열
    if (d == 1) {
        return;
    }
    string erase_s(d / 3, ' '); // 삭제할 길이

    for (int i = r + d / 3; i < r + d / 3 * 2; i++) {
        stars[i].replace(c + d / 3, d / 3, erase_s);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            draw_stars(stars, d / 3, r + d / 3 * i, c + d / 3 * j);
        } 
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> stars;

    for (int i = 0; i < n; i++) {
        stars.push_back(string(n, '*'));
    }
    draw_stars(stars, n, 0, 0);

    for (auto s : stars) {
        cout << s << "\n";
    }
}