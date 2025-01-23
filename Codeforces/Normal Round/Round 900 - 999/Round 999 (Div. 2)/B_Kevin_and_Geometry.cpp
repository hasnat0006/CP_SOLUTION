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
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll mx, c = 0, mxN = 0, up2 = 0;
    for (auto [num, cnt] : mp) {
        if (cnt > c)
            c = cnt, mx = num;
        if (cnt >= 2) {
            mxN = max(mxN, num);
            up2++;
        }
    }
    if (c < 2) {
        cout << -1 << '\n';
        return;
    }
    if (c == 4) {
        cout << mx << " " << mx << " " << mx << " " << mx << '\n';
        return;
    }
    vector<ll> temp;
    ll cnt = 2;
    dbg(mxN);
    for (int i = 0; i < n; i++) {
        if (v[i] == mxN and cnt) {
            cnt--;
            continue;
        }
        temp.push_back(v[i]);
    }
    sort(vr(temp));
    dbg(temp);
    ll L = 2 * mxN;
    n = temp.size();
    for (int i = 0; i < n - 1; i++) {
        if (temp[i] - temp[i + 1] < L) {
            cout << mxN << " " << mxN << " " << temp[i + 1] << " " << temp[i] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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