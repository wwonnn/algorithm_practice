#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a, b, c;

long long solve(long long count) {
    if (count == 0) {
        return 1;
    }
    if (count == 1) {
        return a % c;
    }

    long long tmp = solve(count / 2);
    long long result = (tmp * tmp) % c;

    if (count % 2 == 1) {
        return (result * a) % c;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;
   
    cout << solve(b);
}