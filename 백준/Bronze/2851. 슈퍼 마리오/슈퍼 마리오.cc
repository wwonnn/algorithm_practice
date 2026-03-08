#include <iostream>
#include <string>

using namespace std;

int main() {
    
    long long sum[15];
    sum[0] = 0;
    for (int i = 1; i <= 10; i++) {
        int d; 
        cin >> d;
        sum[i] = sum[i - 1] + d;

        if (sum[i] >= 100) {
            if (100 - sum[i - 1] < sum[i] - 100)
                cout << sum[i - 1];
            else
                cout << sum[i];

            break;
        }
    }
    if (sum[10] < 100) cout << sum[10];

    return 0;
}