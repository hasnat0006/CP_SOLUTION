//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n, x, m;
    cin >> m >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    vector<int> v;
    int sum = 0;
    for (auto i : mp) {
        v.pb(i.second);
        sum += i.second;
    }
    if (sum < m) {
        cout << 0 << endl;
        return;
    }
    sort(vf(v));
    dbg(v);
    int ans = 0;
    int high = v.back(), low = 0;
    while (low <= high) {
        int mid = (low + high + 1) / 2;
        int numOfDays = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            numOfDays += v[i] / mid;
        }
        dbg(low, high, mid, numOfDays, ans);
        if (numOfDays >= m) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}