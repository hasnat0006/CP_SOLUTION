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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> ans;
    int mn = inf, id = -1, even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2)
            odd++;
        else
            even++;
    }
    dbg(v);
    if (even and odd) {
        if (v.front() % 2 != v.back() % 2) {
            ans.push_back({1, n});
            v[n - 1] = v.front();
        }
        else {
            v[0] = v.back();
            ans.push_back({1, n});
        }
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] % 2 == v.back() % 2) {
                ans.push_back({i + 1, n});
                v[i] = v.back();
            }
            else {
                ans.push_back({1, i + 1});
                v[i] = v.front();
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            v[i - 1] = v.back();
            ans.push_back({i, n});
        }
    }
    dbg(v);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}