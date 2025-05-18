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
    string s;
    cin >> n >> k >> s;
    map<ll, vector<char>> mp;
    for (int i = 0; i < n; i++) {
        mp[i % k].push_back(s[i]);
    }
    dbg(mp);
    for (auto i : mp) {
        for (auto it : i.second)
            cout << it;
        cout << endl;
    }
    ll mn = inf, id = 0, index;
    for (int cnt = 1; cnt <= n / k; cnt++) {
        ll left = id, right = id + k - 1, notSame = 0;
        for (int i = 0; i < k / 2; i++) {
            if (s[left + i] != s[right - i])
                notSame++;
        }
        id += k;
        if (notSame < mn) {
            mn = notSame;
            index = cnt - 1;
        }
    }
    dbg(mn, index);
    string temp = "";
    for (int i = k * index; i < k * (index + 1); i++)
        temp.push_back(s[i]);
    dbg(temp);
    for (int i = 0; i < k; i++) {
        temp[i] = temp[k - i - 1];
    }
    dbg(temp);
    ll ans = 0;
    dbg(s);
    for (int i = 0; i < n; i++) {
        if (s[i] != temp[i % k]) {
            s[i] = temp[i % k];
            ans++;
        }
    }
    dbg(s);
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