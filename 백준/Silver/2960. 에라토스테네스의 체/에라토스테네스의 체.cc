#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

bool IsPrime(int x) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;

    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

    int N, K;
    cin >> N >> K;

    int num[1001];
    fill(num, num + N + 5, 1);

    while (K > 0) {
        int p;
        for (int j = 2; j <= N; j++) {
            if (num[j] == 1 && IsPrime(j)) {
                p = j;
                break;
            }
        }

        int i = 1;
        while (K > 0 && p * i <= N) {
            if (num[p * i] == 1) {
                num[p * i] = 0;
                K--;
                if (K == 0) {
                    cout << p * i;
                    break;
                }
            }
            i++;
        }

    }
	
}