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
    vector<ll> S, P;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's')
            S.push_back(i);
        else if (s[i] == 'p')
            P.push_back(i);
    }
    dbg(S, P);
    if (s.front() == '.' and s.back() == '.' and S.size() > 0 and P.size() > 0)
        cout << "NO" << '\n';
    else if (S.empty() or P.empty()) {
        cout << "YES" << '\n';
    }
    else if (P.back() < n - 1 and S.size() > 1)
        cout << "NO" << '\n';
    else {
        if (S.back() > P.front()) 
            cout << "NO" << '\n';
        else if (s.front() == '.') {
            cout << (P.size() == 1 ? "YES" : "NO") << '\n';
        }
        else if(P.size() == 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
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