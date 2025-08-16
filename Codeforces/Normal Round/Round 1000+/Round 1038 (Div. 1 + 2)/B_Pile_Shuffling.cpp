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
    ll a, b, c, d;
    Node() {}
    Node(ll p, ll q, ll r, ll s) { a = p, b = q, c = r, d = s; }
};

void solve() {
    ll n;
    cin >> n;
    vector<Node> v(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i] = Node(a, b, c, d);
    }

    ll removedOneCnt = 0, extra = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].b > v[i].d) {
            extra += (v[i].b - v[i].d);
            extra += min(v[i].a, v[i].c);
        }
        if (v[i].a > v[i].c) {
            extra += v[i].a - v[i].c;
        }
    }
    cout << extra << '\n';
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