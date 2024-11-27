//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 11:51:49            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll ans;

void findAns(int i, string s) {
    if (i == 0) {
        string temp = "";
        for (int id = 0; id < s.size(); id++) {
            if (s[id] == '+') {
                ans += stoll(temp);
                temp = "";
            }
            else
                temp.push_back(s[id]);
        }
        if(!temp.empty())
            ans += stoll(temp);
        return;
    }
    findAns(i - 1, s);
    s.insert(s.begin() + i, '+');
    findAns(i - 1, s);
}

void solve() {
    string s;
    cin >> s;
    findAns(s.size() - 1, s);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}