#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<vector<pair<int, int>>> positions(routes.size());
    int max_size = 0;
    int answer = 0;
    
    for(int i = 0; i < routes.size(); i++)
    {
        for(int j = 0; j < routes[i].size() - 1; j++)
        {
            // 각 로봇 별 이동 좌표 저장
            pair<int, int> st = {points[routes[i][j] - 1][0], points[routes[i][j] - 1][1]};
            pair<int, int> dst = {points[routes[i][j + 1] - 1][0], points[routes[i][j + 1] - 1][1]};
            
            int index = 0;
            int r = dst.first - st.first;
            int c = dst.second - st.second; 
            
            if(j == 0)
                positions[i].push_back({st.first, st.second});
            
            // 행 이동
            if(r > 0)
            {
                for(int k = 1; k <= r; k++)
                    positions[i].push_back({st.first + k, st.second});
            }
            else
            {
                for(int k = -1; k >= r; k--)
                    positions[i].push_back({st.first + k, st.second});
            }

            // 열 이동
            if(c > 0)
            {
                for(int k = 1; k <= c; k++)
                    positions[i].push_back({dst.first, st.second + k});
            }
            else
            {
                for(int k = -1; k >= c; k--)
                    positions[i].push_back({dst.first, st.second + k});
            }
            
            if(max_size < positions[i].size()) 
                max_size = positions[i].size();
        }
    }
    
    for(int t = 0; t < max_size; t++)
    {
        int count[101][101] = {0};
        for(int i = 0; i < positions.size(); i++)
        {
            if(positions[i].size() <= t) continue;
            
            count[positions[i][t].first][positions[i][t].second]++;
        }
        
        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j < 101; j++)
            {
                if(count[i][j] >= 2) answer++;
            }
        }
    }
    
    return answer;
}