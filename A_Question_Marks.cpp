//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|08|2024 20:38:02            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto c : s) {
        mp[c]++;
    }
    int ans = 0;
    int que = mp['?'];
    mp['?'] = 0;
    for(auto it : mp){
        ans += min(it.second, n);
    }
    cout << ans << endl;
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