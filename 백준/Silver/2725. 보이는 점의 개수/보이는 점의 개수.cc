#include <iostream> 

using namespace std; 

int result[1001][1001];

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
    
    // (0, 0)에서 보이는 점인지 확인
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (GCD(i, j) == 1) result[i][j] = 1;
        }
    }

    int C;
    cin >> C;

    for (int c = 0; c < C; c++) {
        int N;
        cin >> N;

        int count = 0;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (result[i][j] == 1) count++;
            }
        }
        cout << count << "\n";
    }

}