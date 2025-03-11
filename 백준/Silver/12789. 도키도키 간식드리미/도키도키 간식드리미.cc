#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    int j = 1;
    while (true) {
        if (!vec.empty() && vec.front() == j) {
            vec.erase(vec.begin());
            j++;
        }
        else if (!st.empty() && st.top() == j) {
            st.pop();
            j++;
        }
        else {
            if (!vec.empty()) {
                st.push(vec.front());
                vec.erase(vec.begin());
            }
            else {
                break;
            }

        }

        if (j > n) {
            break;
        }
    }

    if (st.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
}