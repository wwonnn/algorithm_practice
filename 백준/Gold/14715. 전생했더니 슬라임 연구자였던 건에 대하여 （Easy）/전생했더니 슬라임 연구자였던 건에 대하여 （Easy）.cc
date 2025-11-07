#include <iostream> 

using namespace std; 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int K;
    cin >> K;

    // 소인수분해
    int count = 0;
    int num = K;
    bool isFinish = false;
    while (!isFinish) {
        isFinish = true;
        for (int i = 2; i < K; i++) {
            if (num % i == 0) {
                count++;
                num /= i;
                isFinish = false;
                break;
            }
        }
    }
    
    // 트리 높이 구하기
    int height = 0;
    while (count > 1) {
        count = count % 2 + count / 2;
        height++;
    }
    cout << height;
}