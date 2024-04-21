//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|04|2024 20:56:22            !//
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

vector<int> store;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return;
    }
    int id = upper_bound(vf(store), k) - store.begin();
    id--;
    vector<int> ans;
    ans.push_back(store[id]);
    k -= store[id];
    ans.push_back(k);
    for (int i = 3; i <= n; i++)
        ans.push_back(0);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    for (int i = 0; i <= 30; i++) {
        store.push_back((1ll << i) - 1);
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}