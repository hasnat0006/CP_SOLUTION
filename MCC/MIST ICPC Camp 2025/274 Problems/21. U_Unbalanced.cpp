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
    ll n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << '\n';
            return;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        map<char, ll> mp;
        mp[s[i]]++, mp[s[i + 1]]++, mp[s[i + 2]]++;
        for (auto [c, cnt] : mp) {
            if (cnt > 1) {
                cout << i + 1 << " " << i + 3 << '\n';
                return;
            }
        }
    }
    cout << "-1 -1" << '\n';
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