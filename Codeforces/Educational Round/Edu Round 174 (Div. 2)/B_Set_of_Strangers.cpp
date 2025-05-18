#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    map<int, vector<pi>> mp;
    ll mxNum = 0, mx = -inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            mp[v[i][j]].push_back({i, j});
            if ((ll)mp[v[i][j]].size() > mx) {
                mx = (ll)mp[v[i][j]].size();
                mxNum = v[i][j];
            }
        }
    }
    dbg(mxNum, mx);
    dbg(mp);
    vector<ll> cnt;
    for (auto &[a, b] : mp) {
        dbg(a);
        set<pi> st;
        st.insert(b.back());
        b.pop_back();
        ll tempCnt = 1;
        while (!b.empty()) {
            auto [i, j] = b.back();
            dbg(st);
            dbg(i, j);
            b.pop_back();
            if (st.find({i, j - 1}) == st.end() and
                st.find({i, j + 1}) == st.end() and
                st.find({i + 1, j}) == st.end() and
                st.find({i - 1, j}) == st.end()) {
                st.insert({i, j});
                continue;
            }
            else {
                st.insert({i, j});
                tempCnt++;
            }
        }
        cnt.push_back(min(2LL, tempCnt));
    }

    cout << accumulate(vf(cnt), 0LL) - *max_element(vf(cnt)) << '\n';
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