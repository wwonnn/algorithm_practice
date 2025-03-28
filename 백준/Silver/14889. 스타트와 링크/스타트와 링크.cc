#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int n;
vector<int> member;

long long min_r = 1000000000;

void func(vector<vector<int>>& abil, int idx, int count) {
    if (count == n / 2) {
        int abil_1 = 0, abil_2 = 0;
        vector<int> team1, team2;

        for (int i = 0; i < member.size(); i++) {
            if (member[i]) {
                team1.push_back(i);
            }
            else {
                team2.push_back(i);
            }
        }

        for (int i = 0; i < team1.size(); i++) {
            for (int j = 0; j < team1.size(); j++) {
                abil_1 += abil[team1[i]][team1[j]];
                abil_2 += abil[team2[i]][team2[j]];
            }
        }

        if (abs(abil_1 - abil_2) < min_r) {
            min_r = abs(abil_1 - abil_2);
        }

        return;
    }

    for (int i = idx; i < member.size(); i++) {
        if (member[i] == 0) {
            // 멤버가 아직 팀에 배정되지 않았을 때
            member[i] = 1;
            func(abil, i + 1, count + 1);
            member[i] = 0;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> abil(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        member.push_back(0);
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            abil[i][j] = d;
        }
    }

    func(abil, 0, 0);
    cout << min_r;

}