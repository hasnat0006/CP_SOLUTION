//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|10|2024 21:09:48            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    iota(vf(v), 1);

    auto find_max = [&](vector<int> v) {
        int mx = 0;
        if(v.back() % 2 == 1 or v.front() != 2)
            return 0;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                mx |= v[i];
            else
                mx &= v[i];
        }
        return mx;
    };

    map<int, set<vector<int>>> mp;

    do {
        ll x = find_max(v);
        mp[x].insert(v);
    } while (next_permutation(vf(v)));

    cout << mp.rbegin()->first << '\n';
    for (auto x : mp[mp.rbegin()->first]) {
        for (auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
        // break;
    }
}

/*
5 - 5
2 1 3 4 5
6 - 7
1 2 3 4 6 5
7 - 7
1 2 3 4 6 5 7
8 - 15
1 2 3 4 6 5 7 8
9 - 9
1 2 3 4 6 5 7 8 9
10 - 15
1 2 3 4 5 6 8 9 10 7


*/

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
