//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), ans(n + m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0, j = 0, k = 0;
    while (i < n or j < m) {
        if (a[i] < b[j] and i < n)
            ans[k++] = a[i++];
        else if (a[i] > b[j] and j < m)
            ans[k++] = b[j++];
        else if (a[i] == b[j] and i < n and j < m)
            ans[k++] = a[i++], ans[k++] = b[j++];
        else if (i < n)
            ans[k++] = a[i++];
        else if (j < m)
            ans[k++] = b[j++];
    }
    for (int i = 0; i < n + m; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}