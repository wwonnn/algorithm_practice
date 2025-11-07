#include <iostream> 

using namespace std; 

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

    int t;
    cin >> t;
    int arr[101];

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                sum += GCD(arr[j], arr[k]);
            }
        }
        cout << sum << "\n";
    }
}