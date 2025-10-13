#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll con(string s) {
    string h = s.substr(0, 2);
    string m = s.substr(2, 2);
    ll sec = stoi(h) * 3600 + stoi(m) * 60;
    return sec;
}

map<ll, string> mp;

void solve() {
    string s;
    cin >> s;
    s.erase(s.begin() + 2);
    ll n = con(s);
    auto it = mp.lower_bound(n);
    string ans;
    if (it != mp.end())
        ans = it->second;
    else
        ans = mp.begin()->second;
    ans.insert(ans.begin() + 2, ':');
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 0; i < 3; i++) {
        string s = "";
        ll cnt = 4;
        while (cnt--) {
            s += to_string(i);
        }
        mp[con(s)] = s;
    }
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}