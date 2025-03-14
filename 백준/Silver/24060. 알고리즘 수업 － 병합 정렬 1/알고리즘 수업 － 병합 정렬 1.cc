#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& v, int p, int r);
void merge(vector<int>& v, int p, int q, int r);

int k, K = 0;
vector<int> result(500005);

void merge_sort(vector<int>& v, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

void merge(vector<int>& v, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r) {
        if (v[i] <= v[j]) {
            result[t++] = v[i++];
        }
        else {
            result[t++] = v[j++];
        }
    }
    // 왼쪽 배열 부분이 남은 경우
    while (i <= q) {
        result[t++] = v[i++];
    }
    // 오른쪽 배열 부분이 남은 경우
    while (j <= r) {
        result[t++] = v[j++];
    }

    // 결과 저장
    i = p;
    t = 1;
    while (i <= r) {
        k++;
        if (k == K) {
            cout << result[t];
        }
        v[i++] = result[t++];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> K;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v.push_back(d);
    }

    merge_sort(v, 0, v.size() - 1);
    if (k < K) {
        cout << -1;
    }

}