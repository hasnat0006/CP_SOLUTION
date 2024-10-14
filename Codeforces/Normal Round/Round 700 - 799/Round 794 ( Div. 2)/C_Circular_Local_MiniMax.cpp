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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++;
    int mx = -1;
    for (auto i : mp) {
        mx = max(mx, i.second);
    }
    if (mx * 2 > n) {
        cout << "NO\n";
        return;
    }
    sort(vf(v));
    vector<int> ans(n);
    int c = 0;
    for (int i = 0; i < n / 2; i++) {
        ans[c] = v[i], ans[c + 1] = v[(n / 2) + i], c += 2;
    }
    if (n % 2)
        ans[n - 1] = v[n - 1];
    dbg(ans);
    for (int i = 1; i < n - 1; i++) {
        if ((ans[i] > ans[i + 1] and ans[i] > ans[i - 1]) or
            (ans[i] < ans[i + 1] and ans[i] < ans[i - 1]))
            continue;
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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