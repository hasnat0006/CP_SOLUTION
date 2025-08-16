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
    ll n, m, p, s;
    cin >> n >> m >> p >> s;
    map<pair<ll, ll>, ll> notRec;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        notRec[{min(a, b), max(a, b)}] = 1;
    }
    ll bunL = 1, bunR = p, saugeL = p + 1, saugeR = p + s, extraL = p + s + 1,
       extraR = n;
    auto isValid = [&](ll bit) {
        bitset<22> b = bit;
        dbg(b);
        ll bunSet = 0;
        for (int i = bunL; i <= bunR; i++)
            if (b[i])
                bunSet++;
        dbg(bunSet);
        if (bunSet != 1)
            return false;
        ll saugeSet = 0;
        for (int i = saugeL; i <= saugeR; i++)
            if (b[i])
                saugeSet++;
        dbg(saugeSet);
        if (saugeSet != 1)
            return false;

        for (int i = 1; i <= n; i++) {
            if (b[i]) {
                for (int j = 1; j <= n; j++) {
                    if (b[j] and notRec.count({min(i, j), max(i, j)}))
                        return false;
                }
            }
        }
        return true;
    };
    set<ll> st;
    function<void(ll, ll)> recursion = [&](ll i, ll mask) {
        if (isValid(mask)) {
            st.insert(mask);
        }
        if (i > n)
            return;
        recursion(i + 1, mask);
        recursion(i + 1, mask | (1LL << i));
        return;
    };
    recursion(1, 0);
    dbg(st);
    cout << st.size() << '\n';
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