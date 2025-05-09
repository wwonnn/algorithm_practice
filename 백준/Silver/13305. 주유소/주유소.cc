#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> distance;
    vector<int> cost;
    
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int d;
        cin >> d;
        distance.push_back(d);
    }
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cost.push_back(c);
    }

    int i = 0;
    long long cost_sum = 0;
    while (i < distance.size())
    {
        cost_sum += cost[i] * distance[i];

        int j = i + 1;
        if (j >= distance.size()) {
            break;
        }

        while (cost[i] < cost[j]) {
            cost_sum += cost[i] * distance[j];
            j++;
        }
        i = j;
    }

    cout << cost_sum;
}