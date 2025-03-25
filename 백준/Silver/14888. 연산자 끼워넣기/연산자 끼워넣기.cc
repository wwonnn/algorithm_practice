#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> op;
vector<int> result;

long long min_r = 1000000000;
long long max_r = -1000000000;

void func(int k) {
    if (k == num.size() - 1) {
        long long sum = num[0];
        for (int i = 0; i < result.size(); i++) {
            switch (result[i])
            {
            case 0:
                // +
                sum += num[i + 1];
                break;
            case 1:
                // -
                sum -= num[i + 1];
                break;
            case 2:
                // *
                sum *= num[i + 1];
                break;
            case 3:
                // /
                if (sum < 0 && num[i + 1] > 0) {
                    sum = sum * (-1) / num[i + 1] * (-1);
                }
                else {
                    sum /= num[i + 1];
                }
                break;

            }
        }

        if (sum < min_r) {
            min_r = sum;
        }
        if (sum > max_r) {
            max_r = sum;
        }

        return;
    }   

    for (int i = 0; i < op.size(); i++) {
        if (op[i] > 0) {
            result.push_back(i);
            op[i]--;
            func(k + 1);
            op[i]++;
            result.pop_back();
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        num.push_back(d);
    }

    for (int i = 0; i < 4; i++) {
        int o;
        cin >> o;
        op.push_back(o);
    }
    
    func(0);

    cout << max_r << "\n" << min_r;
}