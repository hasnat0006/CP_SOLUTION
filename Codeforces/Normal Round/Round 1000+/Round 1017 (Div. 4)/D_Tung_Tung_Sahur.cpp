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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    string FS, FT;
    vector<int> SCNT, TCNT;
    FS.push_back(s[0]);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == FS.back()) {
            cnt++;
        }
        else {
            FS.push_back(s[i]);
            SCNT.push_back(cnt);
            cnt = 1;
        }
    }
    SCNT.push_back(cnt);
    cnt = 0;
    FT.push_back(t[0]);
    for(int i = 0; i < m; i++) {
        if(t[i] == FT.back()) {
            cnt++;
        }
        else {
            FT.push_back(t[i]);
            TCNT.push_back(cnt);
            cnt = 1;
        }
    }
    TCNT.push_back(cnt);
    dbg(FS, SCNT);
    dbg(FT, TCNT);
    for(int i = 0; i < FS.size(); i++) {
        if(TCNT[i] >= SCNT[i] and TCNT[i] <= 2 * SCNT[i]) {
            continue;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    if(FS.size() != FT.size()) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < FS.size(); i++) {
        if(FS[i] != FT[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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