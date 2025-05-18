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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    set<pair<ll, ll>> s;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        s.insert({x, i});
    }
    ll mx = (*s.rbegin()).first, turn = 0;
    while (!s.empty() && (*s.rbegin()).first == mx) {
        auto itFirst = *s.begin();
        auto itLast = *s.rbegin();
        s.insert({itLast.first - 1, itLast.second});
        s.erase(s.find(itLast));
        auto it = *s.rbegin();
        dbg(s, turn);
        if(it.first - itFirst.first > k) {
            cout << (turn % 2 == 0 ? "Jerry" : "Tom") << endl;
            return;
        }
        turn++;
    }
    cout << (sum % 2 == 0 ? "Jerry" : "Tom") << endl;
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