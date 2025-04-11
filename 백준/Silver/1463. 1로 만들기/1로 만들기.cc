#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> result(1000005, 0);

    int n;
    cin >> n;

    result[1] = 0;
    result[2] = 1;
    result[3] = 1;

    for (int i = 4; i <= 1000000; i++)
    {
        if (i % 3 == 0 && i % 2 == 0) {
            result[i] = min(min(result[i / 3], result[i / 2]), result[i - 1]) + 1;
        }
        else if (i % 3 == 0) {
            result[i] = min(result[i / 3], result[i - 1]) + 1;
        }
        else if (i % 2 == 0) {
            result[i] = min(result[i / 2], result[i - 1]) + 1;
        }
        else {
            result[i] = result[i - 1] + 1;
        }
        
    }

    cout << result[n];


}