//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 998244353;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v, fact(n + 1), inv(n + 1), ifact(n + 1);
    inv[1] = fact[0] = ifact[0] = 1;
    // for (int i = 2; i < n + 1; i++)
    //     inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (int i = 1; i < n + 1; i++)
        fact[i] = fact[i - 1] * i % mod;
    // for (int i = 1; i < n + 1; i++)
    //     ifact[i] = ifact[i - 1] * inv[i] % mod;
    int cnt = 1, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cnt++;
        }
        else if (cnt > 1) {
            v.push_back(cnt), ans += (cnt - 1), cnt = 1;
        }
    }
    if (cnt > 1)
        v.push_back(cnt), ans += (cnt - 1), cnt = 1;
    dbg(v);
    // dbg(ans);
    // dbg(fact);
    if (ans == 0) {
        cout << 0 << " " << 1 << endl;
        return;
    }
    int way = fact[ans];
    dbg(ans, way);
    for (auto i : v) {
        way *= (i);
        way %= mod;
    }
    cout << ans << " " << way << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}