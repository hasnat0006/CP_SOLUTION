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
#define pq ll, vector<ll>, greater<ll>
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    priority_queue<pq> first, actual1, actual2, last;

    for (int i = 1; i < l; i++)
        first.push(v[i]);
    for (int i = l; i <= r; i++) {
        actual1.push(v[i]);
        actual2.push(v[i]);
    }
    for (int i = r + 1; i <= n; i++)
        last.push(v[i]);
    dbg(first);
    dbg(actual1);
    dbg(last);
    auto findAns = [&](priority_queue<pq> &a, priority_queue<pq> &b) {
        ll ans = 0;
        while (a.size()) {
            if (b.size() and a.top() > b.top()) {
                b.push(a.top());
                a.pop();
                a.push(b.top());
                b.pop();
            }
            dbg(a, b);
            ans += a.top();
            a.pop();
        }
        while (a.size()) {
            ans += a.top();
            a.pop();
        }
        return ans;
    };

    cout << min(findAns(actual1, first), findAns(actual2, last)) << '\n';
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