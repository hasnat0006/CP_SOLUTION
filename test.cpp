//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|11|2024 16:03:16            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

map<vector<int>, int> mp;
void solve() {
    vector<int> temp;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }
    sort(vr(temp));
    if (mp[temp] != 0)
        cout << "perfectus\n";
    else
        cout << "invalidum\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    vector<int> v(3);
    v[0] = 6, v[1] = 1, v[2] = 1;
    mp[v] = 1;
    v[0] = 6, v[1] = 3, v[2] = 0;
    mp[v] = 1;
    v[0] = 4, v[1] = 3, v[2] = 1;
    mp[v] = 1;
    v[0] = 4, v[1] = 4, v[2] = 0;
    mp[v] = 1;
    v[0] = 4, v[1] = 2, v[2] = 1;
    mp[v] = 1;
    v[0] = 3, v[1] = 3, v[2] = 3;
    mp[v] = 1;
    v[0] = 2, v[1] = 2, v[2] = 2;
    mp[v] = 1;

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}