#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int N;
    cin >> N;

    int list[101][3];

    for (int i = 0; i < N; i++) {
        cin >> list[i][0] >> list[i][1] >> list[i][2];
    }
    
    int count = 0;

    for (int x = 1; x <= 9; x++) {
        for (int y = 1; y <= 9; y++) {
            if (y == x) continue;
            for (int z = 1; z <= 9; z++) {
                if (z == x || z == y) continue;

                for (int i = 0; i < N; i++) {
                    // 스트라이크, 볼 계산
                    int d = list[i][0];
                    int st = list[i][1];
                    int b = list[i][2];

                    int strike = 0;
                    int ball = 0;

                    int x2 = d / 100;
                    int y2 = d % 100 / 10;
                    int z2 = d % 100 % 10;

                    if (x2 == x) strike++;
                    else if (x2 == y || x2 == z) ball++;

                    if (y2 == y) strike++;
                    else if (y2 == x || y2 == z) ball++;

                    if (z2 == z) strike++;
                    else if (z2 == y || z2 == x) ball++;

                    if (strike != st || ball != b) break;

                    if (i == N - 1) count++;
                }
            }
        }
    }

    cout << count;
   
}