//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|02|2024 00:06:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    o_set<int> st;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) {
            st.insert(v[i]);
            continue;
        }
        int cnt = st.order_of_key(v[i]);
        if (cnt == st.size())
            mp[v[i]].push_back(i);
        else {
            st.insert(v[i]);
            mp[*st.rbegin()].push_back(i);
        }
        st.insert(v[i]);
    }
    while (q--) {
        int id, turn;
        cin >> id >> turn;
        int tempTurn = min(n, turn) == n ? n - 1 : min(n, turn);
        int idx = upper_bound(vf(mp[v[id - 1]]), tempTurn) - mp[v[id - 1]].begin();
        (v[id - 1] == n) ? cout << idx + (turn - tempTurn) << endl : cout << idx << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}