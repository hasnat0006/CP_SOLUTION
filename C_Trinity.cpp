//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|11|2024 22:12:16            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
    ll ans = inf;
    ll low = n / 2 - 1, high = n - 1;

    auto cnt = [&](int id){
        int c = 0;
        for(int i = 0; i < n - 1; i++){
            if((a[i] + a[i + 1] <= a[id]))
                c++;
        }
        return c;
    };

    while(low <= high){
        ll mid = (low + high) / 2;
        int mx = a[mid];
        int tempAns = cnt(mid);
        int temp = st.order_of_key(mx + 1);
        tempAns += (n - temp);
        dbg(mid, tempAns);
        if(tempAns <= ans){
            ans = tempAns;
            low = mid + 1;
        }
        else
            high = mid - 1;
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