//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|11|2024 22:12:16            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    o_multiset<int> st;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(vf(a));
    for(int i = 0; i < n; i++)
        st.insert(a[i]);
    vector<ll>sumOfTwo;
    for(int i = 0; i < n - 1; i++){
        sumOfTwo.push_back(a[i] + a[i + 1]);
    }

    ll ans = inf;
    for(int i = 0; i < n; i++){
        int tempAns = upper_bound(vf(sumOfTwo), a[i]) - sumOfTwo.begin();
        int temp = st.order_of_key(a[i] + 1);
        tempAns += (n - temp);
        ans = min(ans, (ll)tempAns);
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