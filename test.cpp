//!-----------------------------------------------------!//
//!            Author: MIST_CG0_nai_CP0_nai             !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define endl "\n"

template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
unordered_map<int, bool> mp;
o_set<int> rmv;
vector<int> v1;
int N;

bool check(int mid, int pos) {
    int tot = rmv.order_of_key(mid);
    if (mp[mid])
        tot++;
    return (mid - tot) >= pos;
}
int bs(int pos) {
    int low = 0, high = N - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(v1[mid], pos)) {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    rmv.insert(v1[ans]);
    mp[v1[ans]] = 1;
    return v1[ans];
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; i++)
        cin >> a[i];
    for (int j = 0; j < n / 2; j++)
        cin >> b[j];
    vector<pair<int, int>> v(n / 2);
    for (int i = 0; i < n / 2; i++)
        v[i] = {a[i], b[i]};
    vector<int> ans(n / 2), ans1(n / 2);
    for (int i = 1; i <= n; i++)
        v1.emplace_back(i);
    N = v1.size();
    for (int i = 0; i < n / 2; i++) {
        int first = v[i].first, sec = v[i].second;
        ans[i] = bs(first);
        ans1[i] = bs(sec);
    }
    for (int i = 0; i < n / 2; i++)
        cout << ans[i] << " ";
    cout << endl;
    for (int i = 0; i < n / 2; i++)
        cout << ans1[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
