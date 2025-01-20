#include <bits/stdc++.h>
using namespace std;
#define i64 long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            vector<int> per(n);
            int p = 1;
            for (int j = i; j >= 0; j--) {
                per[j] = p++;
            }
            for (int j = i + 1; j < n; j++)
                per[j] = (p++);
            for (int j = 0; j < n; j++) {
                if (s[j] == 's') {
                    vector<int> pp;
                    for (int k = j; k < n; k++)
                        pp.push_back(per[k]);
                    sort(pp.begin(), pp.end());
                    for (int k = 0; k < (int)pp.size(); k++) {
                        if (k + 1 != pp[k]) {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}