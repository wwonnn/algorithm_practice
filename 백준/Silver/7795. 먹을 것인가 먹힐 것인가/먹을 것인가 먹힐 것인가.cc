#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool func(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> A;
        int count = 0;

        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        sort(A.begin(), A.end(), func);

        // 13 7 2
        // 103 11 290 215
        for (int k = 0; k < M; k++) {
            int b;
            cin >> b;

            int st = 0;
            int end = N - 1;
            int mid = (st + end) / 2;
            int index;
            while (st <= end) {
                if (A[mid] > b) {
                    st = mid + 1;
                }
                else if(A[mid] <= b) {
                    end = mid - 1;
                }
                mid = (st + end) / 2;
            }
            index = mid;
            if(A[index] > b)
                count += (index + 1);
        }
        cout << count << "\n";
    }

}