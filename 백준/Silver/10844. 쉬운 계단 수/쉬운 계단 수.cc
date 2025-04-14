#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long result[101][10] = {0};

    int n;
    cin >> n;

    result[1][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        result[1][i] = 1;
    }


    for (int i = 2; i < 101; i++)
    {
        result[i][0] = result[i - 1][1] % 1000000000;

        for (int j = 1; j < 9; j++)
        {
            result[i][j] = result[i - 1][j - 1] % 1000000000 + result[i - 1][j + 1] % 1000000000;
        }

        result[i][9] = result[i - 1][8] % 1000000000;
    }

    long long sum = 0;
    for (auto r : result[n]) {
        sum = (sum + r) % 1000000000;
    }
    cout << sum;


}