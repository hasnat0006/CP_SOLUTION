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
    string s;
    cin >> s;
    ll one = count(vf(s), '1');
    ll zero = n - one;
    vector<long long> ans;
    ll pre = 0, lastId = inf;
    for (ll i = n - 1, z = 0; i >= 0 and z < zero; i--, z++) {
        if (s[i] == '1') {
            ll j = min(lastId, i);
            ll cnt = abs(j - i);
            // dbg(cnt, j, lastId);
            for (; j >= 0; j--) {
                if (s[j] == '0') {
                    swap(s[i], s[j]);
                    pre = pre + cnt;
                    lastId = j;
                    break;
                }
                cnt++;
            }
        }
        ans.push_back(pre);
    }
    while(one--)
        ans.push_back(-1);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << '\n';
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