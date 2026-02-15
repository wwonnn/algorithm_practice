#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int arr[100] = { 0 };
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        arr[i] = arr[i - 1] + i;
        
        if (arr[i] >= A) {
            if(arr[i] < B)
                count += (arr[i] - max(A, arr[i - 1] + 1) + 1) * i;
            else {
                count += (B - max(A, arr[i - 1] + 1) + 1) * i;
                break;
            }
        }
    }

    cout << count;

    return 0;
}