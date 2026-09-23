#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    const int INF = 500001;
    
    vector<vector<int>> rain(m, vector<int>(n, INF));
    for(int i = 0; i < drops.size(); i++)
    {
        int x = drops[i][0];
        int y = drops[i][1];
        rain[x][y] = i + 1;
    }
    
    vector<vector<int>> rowMin(m, vector<int>(n, INF));
    
    // 가로 방향 슬라이딩 윈도우
    for(int i = 0; i < m; i++)
    {
        deque<int> dq;
        
        for(int j = 0; j < n; j++)
        {
            // 현재 값보다 크거나 같은 값은 최솟값이 될 가능성이 없으므로 제거
            while (!dq.empty() && rain[i][dq.back()] >= rain[i][j])
            {
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            // 윈도우 밖으로 나간 인덱스 제거
            while (!dq.empty() && dq.front() <= j - w)
            {
                dq.pop_front();
            }
            
            // w개의 칸이 모였을 때
            if(j >= w - 1)
            {
                int startX = j - w + 1;
                rowMin[i][startX] = rain[i][dq.front()];
            }
        }
    }
    
    int bestValue = -1;
    int bestY = 0;
    int bestX = 0;
    
    // 세로 방향 슬라이딩 윈도우
    for(int i = 0; i <= n - w; i++)
    {
        deque<int> dq;
        for(int j = 0; j < m; j++)
        {
            while(!dq.empty() && rowMin[dq.back()][i] >= rowMin[j][i])
            {
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            while(!dq.empty() && dq.front() <= j - h)
            {
                dq.pop_front();
            }
            
            if(j >= h - 1)
            {
                int startY = j - h + 1;
                
                int currentValue = rowMin[dq.front()][i];
                
                if(currentValue > bestValue)
                {
                    bestValue = currentValue;
                    bestY = startY;
                    bestX = i;
                }
                else if(currentValue == bestValue)
                {
                    if (startY < bestY ||
                        (startY == bestY && i < bestX))
                    {
                        bestY = startY;
                        bestX = i;
                    }
                }
            }
        }
    }
    
    return {bestY, bestX};
}