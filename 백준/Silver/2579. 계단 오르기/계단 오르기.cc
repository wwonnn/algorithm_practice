#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score[301] = { 0 };
    long long result[10001] = {0};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        score[i] = d;
    }

    result[0] = score[0];
    result[1] = score[0] + score[1];
    result[2] = max(score[0] + score[2], score[1] + score[2]);
    
    for (int i = 3; i < n; i++)
    {
        result[i] = max(result[i - 2], result[i - 3] + score[i - 1]) + score[i];
    }

    cout << result[n - 1];
    
}