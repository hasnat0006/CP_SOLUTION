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

using namespace std;

#define int long long
#define float long double
#define pairi pair<int, int>
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
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
    int mx = -1, mn = inf, mx_id = -1, mn_id = -1, pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > mx)
            mx = v[i], mx_id = i;
        else if (v[i] < mn)
            mn = v[i], mn_id = i;
        if (v[i] > 0)
            pos++;
        else if (v[i] < 0)
            neg++;
    }
    int zero = n - (pos + neg);
    dbg(mx, mx_id, mn, mn_id);
    vector<pairi> ans;
    if (neg == 0) {
        for (int i = 1; i < n; i++)
            ans.pb({i + 1, i});
    }
    else if (pos == 0) {
        for (int i = n - 2; i >= 0; i--)
            ans.pb({i + 1, i + 2});
    }
    else if (pos >= 13) {
        while (v[mx_id] < 20)
            ans.pb({mx_id + 1, mx_id + 1}), v[mx_id] += v[mx_id];
        for (int i = 0; i < n; i++)
            if (v[i] < 0)
                v[i] += v[mx_id], ans.pb({i + 1, mx_id + 1});
        for (int i = 1; i < n; i++)
            ans.pb({i + 1, i});
    }
    else if (neg >= 13) {
        while (v[mn_id] > -20)
            ans.pb({mn_id + 1, mn_id + 1}), v[mn_id] += v[mn_id];
        for (int i = 0; i < n; i++)
            if (v[i] > 0)
                v[i] += v[mn_id], ans.pb({i + 1, mn_id + 1});
        for (int i = n - 2; i >= 0; i--)
            ans.pb({i + 1, i + 2});
    }
    else if (mx >= -mn) {
        for (int i = 0; i < n; i++)
            if (v[i] < 0)
                v[i] += v[mx_id], ans.pb({i + 1, mx_id + 1});
        for (int i = 1; i < n; i++)
            ans.pb({i + 1, i});
    }
    else {
        for (int i = 0; i < n; i++)
            if (v[i] > 0)
                v[i] += v[mn_id], ans.pb({i + 1, mn_id + 1});
        for (int i = n - 2; i >= 0; i--)
            ans.pb({i + 1, i + 2});
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}