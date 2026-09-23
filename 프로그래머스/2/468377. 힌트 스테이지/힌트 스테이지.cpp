#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int min;
    
    for(int buyHint = 0; buyHint < (1 << hint.size()); buyHint++)
    {
        vector<int> hintCount(cost.size(), 0);
        int sum = 0;
        
        for(int i = 0; i < cost.size(); i++)
        {
            if(hintCount[i] > cost.size() - 1)
                sum += cost[i][cost.size() - 1];
            else
                sum += cost[i][hintCount[i]];
            
            if(buyHint & (1 << i))
            {
                sum += hint[i][0];
                for(int j = 1; j < hint[i].size(); j++)
                {
                    hintCount[hint[i][j] - 1]++;
                }
            }
        }
        
        if(buyHint == 0)
            min = sum;
        else if(sum < min)
            min = sum;
    }
    
    return min;
}