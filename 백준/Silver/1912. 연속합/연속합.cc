#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long result[100005] = { 0 };

bool func(long long a, long long b)
{
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> arr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }

    result[0] = arr[0];
    long long  max_num = result[0];

    for (int i = 1; i < n; i++)
    {
        result[i] = (max(arr[i], result[i - 1] + arr[i]));
        if (result[i] > max_num)
        {
            max_num = result[i];
        }
    }

    cout << max_num;
    
}