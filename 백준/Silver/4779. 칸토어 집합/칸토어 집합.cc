#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string cantor(string s) {
    if (s.length() == 1) {
        return s;
    }

    return cantor(s.substr(0, s.length() / 3)) + string(s.length() / 3, ' ') + cantor(s.substr(s.length() / 3 * 2, s.length() / 3));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    while (true) {
        cin >> n;
        if (cin.eof() == true) break;

        str = string(pow(3, n), '-');
        cout << cantor(str) << "\n";
    }
    return 0;

}