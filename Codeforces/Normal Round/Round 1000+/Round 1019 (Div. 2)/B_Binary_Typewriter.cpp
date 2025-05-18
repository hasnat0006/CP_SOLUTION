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
    string s;
    cin >> s;
    ll highestLen = 0, cnt = 0, f = 0, hid = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0' and f)
            cnt++;
        else if(s[i] == '1') {
            if(f) {
                if(cnt > highestLen)
                    highestLen = cnt, hid = i;
                cnt = 0;
            }
            f = 1;
        }
    }
    if(f) {
        if (cnt > highestLen)
            highestLen = cnt, hid = n;
    }
    dbg(highestLen);
    ll ans = (s[0] == '1' ? 2 : 1);
    for(int i = 1; i < n; i++) {
        ans += ((s[i] != s[i - 1]) ? 2 : 1);
    }
    if(highestLen) {
        if(s[0] == '0')
            ans--;
        else
            ans -= (hid == n ? 1 : 2);
    }
    cout << ans  << endl;
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