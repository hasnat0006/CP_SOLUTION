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
    string s;
    cin >> n >> s;
    vector<ll> a, b;
    set<ll> s1, s2;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'A')
            a.push_back(i), s1.insert(i);
        else
            b.push_back(i), s2.insert(i);
    }
    if (a.front() == 1 and b.size() == 1 and b.back() == n) {
        cout << "Alice" << "\n";
        return;
    }
    if (b.back() == 1 and a.size() == 1 and a.back() == n) {
        cout << "Bob" << "\n";
        return;
    }
    while (s1.size()) {
        ll temp = *s1.begin();
        if (s2.lower_bound(temp) != s2.end()) {
            s1.erase(s1.find(temp));
        }
        else if (temp == n and s2.find(1) != s2.end())
            s1.erase(s1.find(temp));
        else
            break;
    }
    dbg(s1);
    dbg(s2);
    if (s1.size() == 0) {
        cout << "Bob" << "\n";
        return;
    }
    else
        cout << "Alice" << "\n";
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