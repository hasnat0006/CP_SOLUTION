//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|05|2024 20:47:09            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    deque<char> dq;
    for (auto i : st) {
        dq.push_back(i);
    }
    map<char, char> mp;
    while (dq.size()) {
        int fr = dq.front();
        int bc = dq.back();
        mp[fr] = bc;
        mp[bc] = fr;
        dq.pop_front();
        if (dq.size())
            dq.pop_back();
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += mp[s[i]];
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}