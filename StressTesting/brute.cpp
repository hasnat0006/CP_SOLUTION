#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    map<int, int> cnt;
    if (a[n - 1] == b[n - 1]) {
        cout << n << "\n";
        return;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == b[i]) {
            cout << i + 1 << "\n";
            return;
        }
        if (a[i] == a[i + 1] || b[i] == b[i + 1]) {
            cout << i + 1 << "\n";
            return;
        }
        if (i + 2 < n) {
            cnt[a[i + 2]]++;
            cnt[b[i + 2]]++;
        }
        if (cnt[a[i]] || cnt[b[i]]) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "0\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        testCase();
    }
    return 0;
}