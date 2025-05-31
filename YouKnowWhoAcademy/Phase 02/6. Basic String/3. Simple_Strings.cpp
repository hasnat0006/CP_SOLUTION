#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        auto NEW = [](char c) { return (c == 'z') ? 'a' : c + 1; };
        if (s[i] == s[i + 1]) {
            s[i + 1] = NEW(s[i]);
            if (i + 2 < n && s[i + 1] == s[i + 2])
                s[i + 1] = NEW(s[i + 1]);
        }
    }
    cout << s << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}