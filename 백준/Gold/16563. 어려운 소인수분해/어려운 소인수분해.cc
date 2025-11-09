#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

const int MAX = 5000000;
int spf[MAX + 1]; // 최소 소인수

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int N;
    cin >> N;

    // 최소 소인수 찾기
    for (int i = 2; i <= MAX; i++) {
        if (spf[i] == 0) {           // i가 소수이면
            spf[i] = i;
            if ((long long)i * i <= MAX) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
		int k;
		cin >> k;

        // 소인수분해
        int num = k;
        while (num > 1) {
            cout << spf[num] << ' ';
            num /= spf[num];
        }
        cout << "\n";
    }

    return 0;
}