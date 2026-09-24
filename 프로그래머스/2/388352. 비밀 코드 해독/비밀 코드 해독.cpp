#include <string>
#include <vector>

using namespace std;
int count = 0;

void dfs(int k, int n, vector<int>& v, const vector<vector<int>>& q, const vector<int>& ans)
{
    if(k > 5)
    {
        bool correct = true;
        for(int t = 0; t < q.size(); t++)
        {
            int solve = 0;
            for(int i = 0; i < q[t].size(); i++)
                for(int j = 0; j < v.size(); j++)
                    if(q[t][i] == v[j]) solve++;
            if(solve != ans[t]) correct = false;
        }
        if(correct) count++;
        
        return;
    }
    
    int start;
    if(v.size() != 0)
        start = v.back() + 1;
    else start = 1;
    
    for(int i = start; i <= n; i++)
    {
        v.push_back(i);
        dfs(k + 1, n, v, q, ans);
        v.pop_back();
    }
    return;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> v;
    dfs(1, n, v, q, ans);
    return count;
}