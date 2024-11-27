//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 21:32:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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
    string s;
    cin >> n >> s;
    set<ll> A, B;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            A.insert(i);
        else
            B.insert(i);
    }
    dbg(A);
    dbg(B);
    ll ans = 0;
    while (A.size() and B.size()) {
        if (*A.begin() < *B.begin()) {
            dbg("A is small");
            ll val = *A.begin();
            A.erase(val);
            while (!B.empty() and B.lower_bound(val) != B.end()) {
                ll bVal = *B.lower_bound(val);
                B.erase(bVal);
                if (A.lower_bound(bVal) == A.end())
                    break;
                else {
                    val = *A.lower_bound(bVal);
                    A.erase(val);
                }
                dbg(A);
                dbg(B);
            }
        }
        else {
            dbg("B is small");
            ll val = *B.begin();
            B.erase(val);
            while (!A.empty() and A.lower_bound(val) != A.end()) {
                ll aVal = *A.lower_bound(val);
                A.erase(aVal);
                if (B.lower_bound(aVal) == B.end())
                    break;
                else {
                    val = *B.lower_bound(aVal);
                    B.erase(val);
                }
                dbg(A);
                dbg(B);
            }
        }
        ans++;
        dbg(ans);
        dbg(A);
        dbg(B);
    }
    ans += A.size() + B.size();
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}