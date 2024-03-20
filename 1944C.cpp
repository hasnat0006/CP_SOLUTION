//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|03|2024 21:19:17            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    set<int> b;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
        freq[x]++;
    }
    if (*b.begin() != 0) {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> c;
    for (int i = 0; i <= n; i++) {
        if (freq[i])
            c.push_back({freq[i], i});
    }
    sort(vf(c));
    for (int i = 1; i < c.size(); i++) {
        if (c[i].first == 1) {
            b.erase(b.find(c[i].second));
        }
    }
    int mex = 0;
    for (auto &i : b) {
        if (i != mex) {
            break;
        }
        mex++;
    }
    cout << mex << endl;
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