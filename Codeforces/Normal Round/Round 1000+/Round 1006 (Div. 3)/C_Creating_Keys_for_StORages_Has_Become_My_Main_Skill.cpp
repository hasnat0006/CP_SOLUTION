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
    ll n, x;
    cin >> n >> x;
    vector<ll> ans;
    bitset<32> b(x);
    for (int i = 0; i < n; i++) {
        bitset<32> a(i);
        ll f = 0;
        for (int j = 31; j >= 0; j--) {
            if (b[j] == 0 and a[j] == 1) {
                f = 1;
                break;
            }
        }
        if(f) break;
        ans.push_back(i);
    }
    if(ans.size() == n) {
        ll OR = 0;
        for(auto i : ans) {
            OR |= i;
        }
        if(OR != x) {
            ans.pop_back();
            ans.push_back(x);
        }
    }
    else {
        ans.push_back(x);
        while(ans.size() < n) {
            ans.push_back(0);
        }
    }
    for(auto i : ans) {
        cout << i << ' ';
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