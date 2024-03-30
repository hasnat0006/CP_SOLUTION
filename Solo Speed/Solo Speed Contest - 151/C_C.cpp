//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 22:16:08            !//
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
    vector<int> a(n), b(n);
    multiset<int> A, B;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A.insert(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (A.find(b[i]) != A.end()) {
            A.erase(A.find(b[i]));
            cnt++;
        }
    }
    if (cnt == n)
        cout << cnt - 1 << endl;
    else
        cout << cnt + 1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}