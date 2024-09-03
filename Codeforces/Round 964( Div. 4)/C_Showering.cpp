//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|08|2024 20:48:52            !//
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
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int,int>> a(n + 1);
    a[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back({m, 0});
    sort(vf(a));
    for (int i = 0; i < a.size() - 1; i++){
        int pre = a[i].second;
        int nxt = a[i + 1].first;
        // cout << pre << " " << nxt << endl;
        // cout << nxt + 1 - pre << endl;
        if(nxt - pre >= s){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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