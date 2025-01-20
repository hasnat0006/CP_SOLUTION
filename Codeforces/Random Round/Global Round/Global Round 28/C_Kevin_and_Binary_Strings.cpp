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
    cin >> s;
    ll n = s.size();
    vector<pair<string, pair<ll, ll>>> all_sub;
    ll need = n, id = 0;
    while (s[id] == '1')
        need--, id++;
    dbg(need);
    if (need == 0) {
        cout << 1 << " " << n << " " << "1 1" << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            continue;
        string temp = "";
        for (int j = i; j < n; j++) {
            temp.push_back(s[j]);
            // dbg(temp);
            if (temp.size() == need)
                all_sub.push_back({temp, {i, j}});
        }
    }
    dbg(all_sub);
    auto cal_xor = [&](string st) {
        reverse(vf(st));
        while (st.size() < s.size())
            st.push_back('0');
        reverse(vf(st));
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != st[i])
                ans.push_back('1');
            else
                ans.push_back('0');
        }
        return ans;
    };
    vector<pair<string, pair<ll, ll>>> v;
    for (auto &[st, i] : all_sub) {
        string XOR = cal_xor(st);
        v.push_back({XOR, i});
    }
    sort(vr(v));
    dbg(v);
    cout << 1 << " " << n << " " << v.front().second.first + 1 << " "
         << v.front().second.second + 1 << '\n';
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