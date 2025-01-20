//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|03|2024 21:09:02            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans(n);
    ans[0] = (a[0] > 0) ? 0 : abs(a[0]);
    set<int> MEX;
    for (int i = 0; i <= n + 1; i++) 
        MEX.insert(i);
    MEX.erase(MEX.find(ans[0]));
    for (int i = 1; i < n; i++) {
        int drkr = *MEX.begin();
        MEX.erase(MEX.find(drkr));
        if (*MEX.begin() - drkr == a[i]) {
            ans[i] = drkr;
            continue;
        }
        MEX.insert(drkr);
        ans[i] = drkr - a[i];
        MEX.erase(MEX.find(ans[i]));
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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