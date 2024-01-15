//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)
// #define ordered_set tree<int, null_type, greater<int>, rb_tree_tag,
// tree_order_statistics_node_update>

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e12;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> pre(n);
    sort(vf(v));
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + v[i];
    int suru = 0, sesh = inf, ans = 0;
    while (suru <= sesh) {
        int mid = suru + (sesh - suru) / 2;
        // int choto_ase = lower_bound(v.begin(), v.end(), mid) - v.begin();
        // int result = ((choto_ase)*mid) - pre[choto_ase - 1];
        int result = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] < mid)
                result += (mid - v[j]);
            else
                break;
        }
        if (result > x)
            sesh = mid - 1;
        else
            suru = mid + 1;
    }
    cout << sesh << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}
