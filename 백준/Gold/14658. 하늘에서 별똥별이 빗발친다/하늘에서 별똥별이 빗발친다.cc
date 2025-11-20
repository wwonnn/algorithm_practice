#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 


int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int N, M, L, K;
    cin >> N >> M >> L >> K;

    vector<pair<int, int>> points;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
    }
    sort(points.begin(), points.end());

    int max_count = -1;
    for (int i = 0; i < K; i++) {
        int x = points[i].first;

        for (int j = 0; j < K; j++) {
            int y = points[j].second;
            int count = 0;

            // 조건에 맞는 별똥별 개수 구하기
            for (int t = 0; t < K; t++) {
                if (points[t].first >= x && points[t].first <= x + L && points[t].second >= y && points[t].second <= y + L) {
                    count++;
                }
            }

            if (count > max_count) max_count = count;
        }

    }

    cout << K - max_count;
   
}