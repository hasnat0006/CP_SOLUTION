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
    ll n;
    cin >> n;
    vector<ll> odd, even;
    ll evenSum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2)
            odd.push_back(x);
        else
            evenSum += x;
    }
    sort(vr(odd));
    ll ans = 0;
    if (!odd.empty())
        ans += evenSum;
    ll i = 0, j = odd.size() - 1, turn = 1;
    while (i <= j) {
        dbg(i, j, ans);
        if (turn) {
            ans += odd[i];
            i++;
        }
        else {
            j--;
        }
        turn = !turn;
    }
    cout << ans << '\n';
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