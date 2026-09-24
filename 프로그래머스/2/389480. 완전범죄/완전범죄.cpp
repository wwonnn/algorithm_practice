#include <string>
#include <vector>

using namespace std;

int INF = 500001;

int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    
    for(auto i : info)
    {
        vector<int> temp(n + 1, INF);
        
        for(int a = 0; a < n; a++)
        {
            if (dp[a] == INF)
                continue;
            
            // A가 훔친 경우
            if(a + i[0] < n)
            {
                temp[a + i[0]] = min(temp[a + i[0]], dp[a]);
            }
                
            // B가 훔친 경우
            if(dp[a] + i[1] < m)
            {
                temp[a] = min(temp[a], dp[a] + i[1]);
            }
        }
        dp = temp;
    }
    
    int answer = INF;

    for (int a = 0; a < n; ++a) {
        if (dp[a] < m) {
            answer = min(answer, a);
        }
    }
    
    return answer == INF ? -1 : answer;
}