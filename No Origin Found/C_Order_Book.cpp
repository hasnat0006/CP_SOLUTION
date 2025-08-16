#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, s;
    cin >> n >> s;
    map<pair<char, ll>, ll> mp;
    for (int i = 0; i < n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        mp[{c, a}] += b;
    }
    vector<tuple<char, ll, ll>> B, S;
    for (auto [it, c] : mp) {
        if (it.first == 'S')
            S.push_back({it.first, it.second, c});
        else
            B.push_back({it.first, it.second, c});
    }
    sort(vr(B));
    sort(vf(S));
    while(S.size() > s) {
        S.pop_back();
    }
    sort(vr(S));
    for (int i = 0; i < min(s, (ll)S.size()); i++) {
        auto [cha, num, val] = S[i];
        cout << cha << " " << num << " " << val << endl;
    }
    for (int i = 0; i < min(s, (ll)B.size()); i++) {
        auto [cha, num, val] = B[i];
        cout << cha << " " << num << " " << val << endl;
    }
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