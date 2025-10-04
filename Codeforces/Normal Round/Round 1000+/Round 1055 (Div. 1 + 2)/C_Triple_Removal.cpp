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

class Node {
   public:
    ll oc, zc, con;
    Node() { oc = zc = con = 0; }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
        
    vector<Node> pre(n + 5);
    for (int i = 1; i <= n; i++) {
        pre[i].zc = pre[i - 1].zc;
        pre[i].oc = pre[i - 1].oc;
        pre[i].con = pre[i - 1].con;
        if (v[i] == 0) 
            pre[i].zc++;
        else
            pre[i].oc++;
        if (v[i] != v[i - 1])
            pre[i].con++;
    }
    for(int i = 0; i < n; i++) {
        dbg(i, pre[i].oc, pre[i].zc, pre[i].con);
    }
    while (m--) {
        ll l, r;
        cin >> l >> r;
        Node L = pre[l - 1];
        Node R = pre[r];
        ll zero = R.zc - L.zc, one = R.oc - L.oc;
        if ((zero % 3 != 0) or (one % 3 != 0) or ((r - l + 1) % 3 != 0)) {
            cout << -1 << '\n';
            continue;
        }
        ll conLen = R.con - L.con + (L.con == pre[l].con);
        ll ans = 0;
        if (zero == one and conLen == (r - l + 1))
            ans++;
        ans += ((zero / 3) + (one / 3));
        cout << ans << '\n';
    }
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