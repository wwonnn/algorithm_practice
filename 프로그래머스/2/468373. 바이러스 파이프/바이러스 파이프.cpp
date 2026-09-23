#include <string>
#include <vector>
#include <queue>

using namespace std;

bool infectionState[105];
int maxCount = 0;

vector<int> update(int type, vector<vector<pair<int, int>>> tree)
{
    vector<int> newInfections;
    queue<int> q;

    for(int i = 1; i < tree.size(); i++)
    {
        if(infectionState[i])
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto [next, edgeType] : tree[cur])
        {
            if(edgeType != type)
                continue;

            if(!infectionState[next])
            {
                infectionState[next] = true;
                newInfections.push_back(next);
                q.push(next);
            }
        }
    }

    return newInfections;
}

void returnState(vector<int> Infections)
{
    for(int n : Infections)
    {
        infectionState[n] = false;
    }
}

void dfs(int k, vector<vector<pair<int, int>>> tree)
{
    if(k <= 0)
    {
        // 끝
        int result = 0;
        for(int i = 1; i <= tree.size() - 1; i++)
        {
            if(infectionState[i])
                result++;
        }
        if(result > maxCount)
            maxCount = result;
        
        return;
    }
    
    vector<int> infections;

    // 1번 파이프 연 경우
    infections = update(1, tree);
    dfs(k - 1, tree);
    returnState(infections);
    
    // 2번 파이프 연 경우
    infections = update(2, tree);
    dfs(k - 1, tree);
    returnState(infections);
    
    // 3번 파이프 연 경우
    infections = update(3, tree);
    dfs(k - 1, tree);
    returnState(infections);
    
    return;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    
    infectionState[infection] = true;
    vector<vector<pair<int, int>>> tree(n+1);
    
    for(int i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        tree[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    dfs(k, tree);
    
    return maxCount;
}