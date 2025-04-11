#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(long long a, long long b)
{
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> triangle;
    vector<vector<long long>> result;

    int n;
    cin >> n;

    vector<int> temp;
    for (int i = 1; i <= n; i++)
    {
        temp.clear();
        for (int j = 0; j < i; j++)
        {
            int d;
            cin >> d;

            temp.push_back(d);
        }
        triangle.push_back(temp);
    }

    result.push_back({ triangle[0][0] });
    
    vector<long long> temp2;
    for (int i = 1; i < n; i++)
    {
        temp2.clear();
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                // 삼각형 왼쪽 끝인 경우
                temp2.push_back(result[i - 1][j] + triangle[i][j]);
            }
            else if (j == i)
            {
                // 삼각형 오른쪽 끝인 경우
                temp2.push_back(result[i - 1][j - 1] + triangle[i][j]);
            }
            else
            {
                temp2.push_back(max(result[i - 1][j], result[i - 1][j - 1]) + triangle[i][j]);
            }
        }
        result.push_back(temp2);
    }

    sort(result.back().begin(), result.back().end(), func);
    cout << result.back().front();
    
}