#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag,
                     tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                        tree_order_statistics_node_update>;
template <typename T>
using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> ans(n), even, odd;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    auto calculateInversions = [](vector<ll>& arr) {
        ll inv_count = 0;
        ll n = arr.size();
        o_set<ll> s;
        for (int i = 0; i < n; i++) {
            inv_count += (s.size() - s.order_of_key(arr[i]));
            s.insert(arr[i]);
        }
        return inv_count;
    };
    ll even_inversions = calculateInversions(even);
    ll odd_inversions = calculateInversions(odd);
    sort(vf(even));
    sort(vf(odd));
    for (int i = 0, e = 0, o = 0; i < n; i++) {
        ans[i] = (i % 2 == 0) ? even[e++] : odd[o++];
    }
    if ((even_inversions % 2) != (odd_inversions % 2)) {
        swap(ans[n - 1], ans[n - 3]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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