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
    string s;
    ll n;
    cin >> n >> s;
    deque<char> dq;
    dq.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        if (dq.back() == s[i])
            continue;
        dq.push_back(s[i]);
    }
    while (dq.size() and dq.front() == '0')
        dq.pop_front();
    ll cnt = 0;
    while (dq.size() and dq.back() == '1') {
        dq.pop_back();
        cnt = 1;
    }
    cout << dq.size() + cnt << '\n';
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