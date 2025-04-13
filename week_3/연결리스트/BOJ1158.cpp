// 요세푸스 문제
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> l;
    for (int i = 1; i <= n; ++i)
        l.push_back(i);

    vector<int> result;

    while (!l.empty()) {
        for (int i = 0; i < k - 1; ++i) {
            l.push_back(l.front());
            l.pop_front();
        }
        result.push_back(l.front());
        l.pop_front();
    }

    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ">";
}
