#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    string s, l, r;
    int m;
    cin >> s >> m >> l >> r;
    map<char, vector<int>> mp;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]].push_back(i);
    }

    for(int i = 0; i < m; i++) {
        
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